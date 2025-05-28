const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    const array = [_]i32{1, 2, 5, 6, 8, 11};
    const target = 5;

    var found = false;

    const result = binarySearch();

    if (found)
    {
        print("Target found",.{});
    }
    else
    {
        print("Target not found.",.{});
    }

}

fn binarySearch(target) {
    var left:usize = 0;
    var right:usize = array.len - 1;

    while (left <= right)
    {
        // 5/2 = 2.5, floor to 2 is the first index used to check if the middle value (2)  is equal to the target value (5)
        const middle:usize = @divTrunc(left + right, 2);

        if (array[middle] == target)
        {
            found = true;
            break;
        }
        else if (array[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
}