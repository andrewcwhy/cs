const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    const p1 = Point{ .x = 10, .y = 20 };
    print("Point p1: ({}, {})\n", .{ p1.x, p1.y });

    const p2 = Point.create(9, 20);
    Point.display(p2);
}

const Point = struct {
    x: f64,
    y: f64,

    fn create(x: f64, y: f64) Point {
        return Point{ .x = x, .y = y };
    }

    fn display(self: Point) void {
        std.debug.print("Point: ({}, {})\n", .{ self.x, self.y });
    }
};
