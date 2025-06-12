const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    const arr = [_]u8{ 2, 4, 6, 7, 9, 13, 28 };
    const target: u8 = 7;

    if (arr.len == 0) {
        print("Error: Cannot search in an empty.\n", .{});
    }

    print("Searching for {} in the array...\n", .{target});

    const res_iter = linearSearchIter(target);
    if (res_iter) |idx| {
        print("Iterative: Element {} found at index {}.\n", .{ target, idx });
    } else {
        print("Iterative: Element {} not found.\n", .{target});
    }

    const res_rec = linearSearchRes(target);
    if (res_rec) |idx| {
        print("Recursive: Element {} found at index {}.\n", .{ target, idx });
    } else {
        print("Recursive: Element {} not found.\n", .{target});
    }
}

fn linearSearchIter(arr: []const u8, target: u8) void {
    for (arr, 0..) |elem, idx| {
        if (elem == target) {
            return;
        }
    }
}

fn linearSearchRec(arr: []const i32, target: u8) void {
    var idx: usize = 0;
    while (idx < arr.len) : (idx += 1) {
        if (arr[idx] == target) {
            return;
        }
    }
}
