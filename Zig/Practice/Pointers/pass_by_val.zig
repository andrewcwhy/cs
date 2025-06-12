const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    var x: u8 = 10;

    print("Before passByVal: {}\n",.{x});
    passByVal(x);
    print("Outside passByVal: {}\n",.{x});
}

fn passByVal(num: u8) void {
    num = 20;
    print("Inside passByVal: {}\n",.{num});
}