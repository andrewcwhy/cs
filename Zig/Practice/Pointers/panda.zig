const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    const arr = [_]i32{ 2, 4, 5, 8, 1 };

    print("Array: {any}\n", .{arr});
    print("Address of the first element: {p}\n", .{&arr[0]});

    print("First element value: {}\n", .{arr[0]});

    // Taking an address of an individual element gives a
    // single-item pointer. This kind of pointer
    // does not support pointer arithmetic.
    const ptr = &arr[0];
    print("Value of the first element via pointer dereference: {}\n", .{ptr.*});
}
