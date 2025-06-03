const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    const point1 = Coordinate.init(9, 7, 5);
    const point2 = Coordinate.init(4, 28, 7);
    const point3 = Coordinate{ .x = 1, .y = 96, .z = 7 };

    Coordinate.display(point1);
    print("x: {}\n", .{point2.x});
    print("y: {}\n", .{point2.y});
    print("z: {}\n", .{point2.z});
    point3.display();
}

const Coordinate = struct {
    x: i32,
    y: i32,
    z: i32,

    fn init(x: i32, y: i32, z: i32) Coordinate {
        return Coordinate{ .x = x, .y = y, .z = z };
    }

    fn display(self: Coordinate) void {
        print("Coordinates: (x: {}, y: {}, z: {})\n", .{ self.x, self.y, self.z });
    }
};
