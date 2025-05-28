const std = @import("std");
const print = std.debug.print;


pub fn main() !void {
    const val = 10;
    const result = sqr(val);
    print("Result: {}\n", .{result});
}

fn sqr(val: i32) i32 {
    return val * val;
}
