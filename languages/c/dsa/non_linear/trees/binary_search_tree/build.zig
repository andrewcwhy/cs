const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = std.builtin.OptimizeMode.ReleaseSafe;

    const exe = b.addExecutable(.{
        .name = "binary_tree",
        .target = target,
        .optimize = optimize,
    });

    exe.addCSourceFiles(.{
        .root = b.path("src"),
        .files = &.{ "main.c", "utils/impl.c" },
    });
    exe.linkLibC();

    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.addArgs(b.args orelse &.{});
    run_cmd.step.dependOn(b.getInstallStep());

    const run_step = b.step("run", "Run the program");
    run_step.dependOn(&run_cmd.step);
}
