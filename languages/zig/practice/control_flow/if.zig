const std = @import("std");
const print = std.debug.print;

fn main() void {
    var number: i32 = 9;

    if (number < 7) {
        print("{} is less than {}\n", .{ number, 7 });
    } else {
        print("Condition false.\n", .{});
    }

    number = 7;

    if (number != 0) {
        print("Number was something other than zero\n", .{});
    }
}
