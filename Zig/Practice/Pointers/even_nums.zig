const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    const start_num: u8 = 0;
    const end_num: u8 = 200;

    var count: u8 = 0;
    var sum: u8 = 0;

    evenNums(start_num, end_num, &count, &sum);

    print("Count of even numbers between {} and {}: {}\n",.{start_num, end_num, count});
    print("Sum of even numbers between {} and {}: {}\n",.{start_num, end_num, sum});
}

fn evenNums(start: u8, end: u8, count: *u8, sum: *u8) void {
    var i: u8 = start;
    while( start <= end)
    {
        if (i % 2 == 0)
        {
            count.* += 1;  // Dereference the pointer to increment the count
            sum.* += i; // Dereference the pointer to add to the sum
        }
    }
}