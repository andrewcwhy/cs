const expect = @import("std").testing.expect;

test "square" {
    var x: i32 = 10;
    
    const before = x;

    square(&x);

    try expect(x == before * before);
}

fn square(num: *i32) void {
    num.* *= num.*;
}
