const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    const array = [_]i32{ 10, 6, 5, 6, 20 };
    const length = array.len;

    const target: i32 = 0;

    if (target == 0) {
        print("Target cannot be 0.\n", .{});
        return;
    }

    const matched = findMultiples(&array, 0, length - 1, target);
    if (matched > 0) {
        print("There are {} multiple(s) of {}.\n", .{ matched, target });
    } else {
        print("There are no multiples of {}.\n", .{target});
    }
}

fn findMultiples(array: []const i32, start: usize, end: usize, target: i32) usize {
    var count: usize = 0;

    if (@mod(array[start], target) == 0) {
        count += 1;
    }

    if (start == end) {
        return count;
    }

    return count + findMultiples(array, start + 1, end, target);
}
