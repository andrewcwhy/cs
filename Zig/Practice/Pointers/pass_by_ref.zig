const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    var x: u8 = 10;
    print("Before passByRef: {}\n", .{x});
    passByRef(&x);
    print("Outside passByRef: {}\n", .{x});
}

fn passByRef(num: *u8) void {
    num.* = 20;
    print("Inside passByRef: {}\n", .{num.*});
}
