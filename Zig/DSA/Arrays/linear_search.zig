const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();

    const allocator = gpa.allocator();

    const N: usize = 1000000000;

    var arr = std.ArrayList(i32).init(allocator);
    defer arr.deinit();

    print("Creating an array with {} elements...\n",.{N});

    // Populate the list with numbers from 0 to N-1
    for (0..N) |i| {
        try arr.append(@intCast(i));
    }
    
    const len = arr.items.len;
    const target: i32 = @intCast(len - 1);

    print("Searching for element {} in the array of {} elements...\n", .{ target, len });
    const start = std.time.nanoTimestamp();

    linearSearch(arr.items, target);

    const end = std.time.nanoTimestamp();
    const elapsed = end - start;

    const elapsed_ms = @as(f64, @floatFromInt(elapsed)) / 1e6;


    print("Search completed in {d} nanoseconds ({d:.2} ms).\n", .{elapsed, elapsed_ms});
}

// Your original linearSearch function, unchanged.
// It returns `void` and handles its own printing.
fn linearSearch(arr: []const i32, target: i32) void {
    for (arr, 0..) |elem, idx| {
        if (elem == target) {
            print("Element {} found at index {}.\n", .{ target, idx });
            return;
        }
    }
    print("Element {} not found.\n", .{target});
}
