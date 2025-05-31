const std = @import("std");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    const args = try std.process.argsAlloc(allocator);
    defer std.process.argsFree(allocator, args);

    const target_format = blk: {
        if (args.len >= 3) {
            if (std.mem.eql(u8, args[2], "--json")) break :blk "json";
            if (std.mem.eql(u8, args[2], "--jsonc")) break :blk "jsonc";
        }
        break :blk "json"; // default
    };

    const file_name = if (std.mem.eql(u8, target_format, "json")) "janush.json" else if (std.mem.eql(u8, target_format, "jsonc")) "janush.jsonc" else return error.UnsupportedFormat;

    const content = try generateTemplate(allocator, target_format);
    defer allocator.free(content);

    const file = try std.fs.cwd().createFile(file_name, .{ .truncate = true });
    defer file.close();

    try file.writeAll(content);
    std.debug.print("Created {s}\n", .{file_name});
}

fn generateTemplate(allocator: std.mem.Allocator, format: []const u8) ![]u8 {
    if (std.mem.eql(u8, format, "json") or std.mem.eql(u8, format, "jsonc")) {
        const lines = [_][]const u8{
            "{\n",
            "  \"clean\": {\n",
            "    \"targets\": [\n",
            "      \"**/dist/**\",\n",
            "      \"**/node_modules/**\",\n",
            "      \"**/target/**\",\n",
            "      \"*.exe\",\n",
            "      \"*.log\",\n",
            "      \"bun.lock\",\n",
            "      \"Cargo.lock\",\n",
            "      \".moon/cache\"\n",
            "    ]\n",
            "  }\n",
            "}\n",
        };
        return try std.mem.concat(allocator, u8, &lines);
    } else {
        return error.UnsupportedFormat;
    }
}
