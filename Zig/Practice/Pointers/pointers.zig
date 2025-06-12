const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    var num: u8 = 7;
    const ptr: *u8 = &num;
    // Dereferencing ptr to access the value
    print("Value of num: {}\n", .{ptr.*});
    print("Address of num: {}\n", .{ptr});
    print("Address of ptr: {}\n", .{&ptr});
    ptr.* = 9;
    print("Modified value of num: {}\n", .{num});
}
