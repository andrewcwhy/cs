const std = @import("std");
const fs  = std.fs;
const json = std.json;

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    try cleanMonorepo(allocator);
}

fn cleanMonorepo(allocator: std.mem.Allocator) !void {
    const cwd = fs.cwd();

    var configFile = try cwd.openFile("janush.json", .{});
    defer configFile.close();

    const configData = try configFile.readToEndAlloc(allocator, 10 * 1024);
    defer allocator.free(configData);

    const parsed = try json.parseFromSlice(Config, allocator, configData, .{});
    defer parsed.deinit();

    for (parsed.value.clean.targets) |pattern| {
        try processPattern(pattern, allocator);
    }
}

fn processPattern(pattern: []const u8, allocator: std.mem.Allocator) !void {
    if (std.mem.startsWith(u8, pattern, "**/")) {
        const inner = pattern[3..];
        if (std.mem.endsWith(u8, inner, "/***")) {
            const dirName = inner[0 .. inner.len - 4];
            try deleteDirsRecursive(".", dirName, allocator);
        } else {
            try deleteFilesRecursive(".", inner, allocator);
        }
    } else {
        try deleteIfExists(pattern);
    }
}

fn deleteIfExists(path: []const u8) !void {
    const cwd = fs.cwd();
    cwd.deleteFile(path) catch |err| switch (err) {
        error.IsDir       => try cwd.deleteDir(path),
        error.FileNotFound=> return,
        else              => return err,
    };
    std.debug.print("Deleted: {s}\n", .{path});
}

fn deleteDirsRecursive(base: []const u8, target: []const u8, allocator: std.mem.Allocator) !void {
    var dir = try fs.cwd().openDir(base, .{ .iterate = true });
    defer dir.close();

    var it = dir.iterate();
    while (try it.next()) |entry| {
        const subpath = try fs.path.join(allocator, &[_][]const u8{ base, entry.name });
        defer allocator.free(subpath);

        if (entry.kind == .directory) {
            if (std.mem.eql(u8, entry.name, target)) {
                try fs.cwd().deleteTree(subpath);
                std.debug.print("Deleted dir: {s}\n", .{subpath});
            } else {
                try deleteDirsRecursive(subpath, target, allocator);
            }
        }
    }
}

fn deleteFilesRecursive(base: []const u8, pattern: []const u8, allocator: std.mem.Allocator) !void {
    var dir = try fs.cwd().openDir(base, .{ .iterate = true });
    defer dir.close();

    var it = dir.iterate();
    while (try it.next()) |entry| {
        const subpath = try fs.path.join(allocator, &[_][]const u8{ base, entry.name });
        defer allocator.free(subpath);

        if (entry.kind == .directory) {
            try deleteFilesRecursive(subpath, pattern, allocator);
        } else if (matches(pattern, entry.name)) {
            try fs.cwd().deleteFile(subpath);
            std.debug.print("Deleted file: {s}\n", .{subpath});
        }
    }
}

fn matches(pattern: []const u8, name: []const u8) bool {
    // simple "*.ext" support
    if (pattern.len > 0 and pattern[0] == '*') {
        const suffix = pattern[1..];
        return std.mem.endsWith(u8, name, suffix);
    } else {
        return std.mem.eql(u8, name, pattern);
    }
}

const Config = struct {
    clean: struct {
        targets: []const []const u8,
    },
};
