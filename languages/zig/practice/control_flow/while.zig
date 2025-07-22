const std = @import("std");
const print = std.debug.print;

fn main() void {
    var applied: bool = false;

    while(!applied) {
        print("Have you applied for internships? (yes/no): ",.{});

        if ( == "yes") {
            applied = true;
        } else {
            print("APPLY",.{});
        }
    }

    print("Congratualtions on successfully applying for an internship!\n");
    print("Now get an internship.\n");
}
