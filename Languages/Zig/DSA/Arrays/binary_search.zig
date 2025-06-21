const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    const arr = [_]u8{ 2, 4, 6, 7, 9, 13, 28 };
    const target: u8 = 7;

    if (arr.len == 0) {
        print("Error: Cannot search in an empty.\n", .{});
    }

    print("Searching for {} in the array...\n", .{target});

    const res_iter = binarySearchIter(&arr, target);
    if (res_iter) |idx| {
        print("Iterative: Element {} found at index {}.\n", .{ target, idx });
    } else {
        print("Iterative: Element {} not found.\n", .{target});
    }

    const res_rec = binarySearchRec(&arr, 0, arr.len - 1, target);
    if (res_rec) |idx| {
        print("Recursive: Element {} found at index {}.\n", .{ target, idx });
    } else {
        print("Recursive: Element {} not found.\n", .{target});
    }
}

fn binarySearchIter(arr: []const u8, target: u8) ?usize {
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

    return null; // Element not found
}

fn binarySearchRec(arr: []const u8, left: usize, right: usize, target: u8) ?usize {
    // Base case: if the search space is invalid, the element is not present.
    if (left > right) {
        return null;
    }

    const mid: usize = @divTrunc(left + right, 2);

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRec(arr, mid + 1, right, target);
    } else {
        return binarySearchRec(arr, left, mid - 1, target);
    }
}
