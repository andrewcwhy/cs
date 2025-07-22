const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // Define the tree implementations
    const tree_types = [_][]const u8{
        "avl_tree",
        "binary_search_tree",
        "binary_tree",
    };

    // Store build steps for the "all" command
    var build_steps = std.ArrayList(*std.Build.Step).init(b.allocator);
    defer build_steps.deinit();

    // Track which executable to run for the default "run" command
    var current_exe: ?*std.Build.Step.Compile = null;

    // Create build steps for each tree type
    for (tree_types) |tree_type| {
        const exe = b.addExecutable(.{
            .name = tree_type,
            .target = target,
            .optimize = optimize,
        });

        // Add source files for this specific tree type
        const tree_path = b.fmt("{s}/src", .{tree_type});
        exe.addCSourceFiles(.{
            .root = b.path(tree_path),
            .files = &.{ "main.c", "utils/impl.c" },
        });
        exe.linkLibC();

        // Create install step for this executable
        const install_artifact = b.addInstallArtifact(exe, .{});

        // Create a build step for this tree type
        const build_step = b.step(tree_type, b.fmt("Build {s}", .{tree_type}));
        build_step.dependOn(&install_artifact.step);

        // Store this step for the "all" command
        build_steps.append(build_step) catch unreachable;

        // Set this as the current executable (last one built will be the default for run)
        current_exe = exe;
    }

    // Create default "run" step that runs the currently built program
    if (current_exe) |exe| {
        const run_cmd = b.addRunArtifact(exe);
        run_cmd.addArgs(b.args orelse &.{});

        const run_step = b.step("run", "Run the built program");
        run_step.dependOn(&run_cmd.step);
    }

    // Create an "all" step to build everything
    const all_step = b.step("all", "Build all tree implementations");
    for (build_steps.items) |step| {
        all_step.dependOn(step);
    }
}
