git_repository(
    name = "libgam",
    remote = "https://github.com/bentglasstube/gam.git",
    commit = "9b57245805ec164ab5c2985a7ce752eeb40b0672",
)

git_repository(
    name = "mxebzl",
    remote = "https://github.com/cfrantz/mxebzl.git",
    tag = "20170703_RC03",
)

load("@mxebzl//tools:repository.bzl", "mxe_compilers")
mxe_compilers(
    deps = [
        "compiler",
        "SDL2",
        "SDL2-extras",
        "xz",
    ],
)
