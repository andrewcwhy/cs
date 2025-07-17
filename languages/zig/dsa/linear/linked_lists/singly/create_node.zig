const std = @import("std");

const Node = struct {
    value: i32,
    next: ?*Node,
};

const LinkedList = struct {
    allocator: std.mem.Allocator,
    head: ?*Node = null,

    pub fn init(allocator: std.mem.Allocator) LinkedList {
        return LinkedList{
            .allocator = allocator,
            .head = null,
        };
    }

    pub fn print(self: *LinkedList) void {
        var current = self.head;
        while (current) |node| {
            std.debug.print("{} -> ", .{node.value});
            current = node.next;
        }
        std.debug.print("null\n", .{});
    }

    pub fn deinit(self: *LinkedList) void {
        var current = self.head;
        while (current) |node| {
            const next = node.next;
            self.allocator.destroy(node);
            current = next;
        }
        self.head = null;
    }
};

pub fn main() !void {
    const allocator = std.heap.page_allocator;
    var list = LinkedList.init(allocator);

    try list.addFront(10);
    try list.addFront(20);
    try list.addFront(30);

    list.print(); // Should print: 30 -> 20 -> 10 -> null

    list.deinit(); // Free memory
}
