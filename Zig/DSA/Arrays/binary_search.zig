const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    const arr = [_]i32{ 1, 2, 5, 6, 8, 11 };
    const target: i32 = 5;

    const index = binarySearch(&arr, target);

    if (index) |idx| {
        print("Element {} found at index {}.\n", .{ target, idx });
    } else {
        print("Element {} not found.\n", .{target});
    }
}

fn binarySearch(arr: []const i32, target: i32) ?usize {
    if (arr.len == 0) {
        print("The array is empty.\n", .{});
    }

    var left: usize = 0;
    var right: usize = arr.len - 1;

    while (left <= right) {
        // 5/2 = 2.5, floor to 2 is the first index used to check if the middle value (2)  is equal to the target value (5)
        const mid: usize = @divTrunc(left + right, 2);

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return null;
}
