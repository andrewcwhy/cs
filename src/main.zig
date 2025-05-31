const std = @import("std");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    const args = try std.process.argsAlloc(allocator);
    defer std.process.argsFree(allocator, args);

    if (args.len < 2) {
        std.debug.print("Usage: janush <clean|outdated>\n", .{});
        return;
    }

    const command = args[1];

    if (std.mem.eql(u8, command, "clean")) {
        return @import("commands/clean.zig").main();
    } else {
        std.debug.print("Unknown command: {s}\n", .{command});
        return;
    }
}
