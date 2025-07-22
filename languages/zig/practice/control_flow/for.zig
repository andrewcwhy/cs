const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    const friends [_][]u8{"Briana", "Elan", "Holden", "Reem"};

    for (friends) |friend| {
        if (friend == "Briana") {
            print("Briana is my sister and firend.");
        } else if (friend == "Reem") {
            print("Reem was my orientation leader and now my friend!");
        } else {
            print("{} is my friend.",.{friend});
        }
    }
}
