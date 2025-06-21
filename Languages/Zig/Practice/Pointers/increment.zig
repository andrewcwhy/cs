const expect = @import("std").testing.expect;

test "increment" {
    var x: i32 = 10;
    const before = x;

    increment(&x);

    try expect(x == before + 1);
}

fn increment(num: *i32) void {
    num.* += 1;
}
