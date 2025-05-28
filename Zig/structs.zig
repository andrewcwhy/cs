const std = @import("std");
const print = std.debug.print;

const Coordinate = struct {
    x: i32,
    y: i32,
    z: i32,

    fn newCoordinate(x: i32, y: i32, z: i32) Coordinate {
        return Coordinate{ .x = x, .y = y, .z = z };
    }

    fn printCoordinate(self: Coordinate) void {
        print("x: {}\n", .{self.x});
        print("y: {}\n", .{self.y});
        print("z: {}\n", .{self.z});
    }
};

pub fn main() !void {

    // Using newCoordinate and printCoordinate()

    const coordinate1 = Coordinate.newCoordinate(9, 7, 5);
    print("-----Coordinate 1-----\n", .{});
    coordinate1.printCoordinate();

    // Using only newCoordinate() function

    const coordinate2 = Coordinate.newCoordinate(4, 28, 7);
    print("-----Coordinate 2-----\n", .{});
    print("x: {}\n", .{coordinate2.x});
    print("y: {}\n", .{coordinate2.y});
    print("z: {}\n", .{coordinate2.z});

    // Without using the new_coordinate() and print_coordinate()

    const coordinate3 = Coordinate{ .x = 1, .y = 96, .z = 7 };
    print("-----Coordinate 3-----\n", .{});
    print("x: {}\n", .{coordinate3.x});
    print("y: {}\n", .{coordinate3.y});
    print("z: {}\n", .{coordinate3.z});
}
