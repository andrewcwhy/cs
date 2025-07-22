// Arrays as function arguments

const print = @import("std").debug.print;

pub fn main() !void {
    const arr = [_]isize{ 1, 2, 3, 4, 5 };

    const total: isize = sumOfElems(&arr);

    print("Sum of elements = {}\n", .{total});
}

fn sumOfElems(arr: []const isize) isize {
    var sum: isize = 0;

    for (arr) |val| {
        sum += val;
    }

    return sum;
}
