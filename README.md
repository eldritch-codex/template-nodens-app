# Nodens Application Template

A minimal C++23 application template using [Nodens](https://github.com/EldritchCodex/Nodens).

> ⚠️ The published development environment currently builds and validates Nodens applications for Linux only. Native Windows and macOS builds are not currently supported or validated.

## Prerequisites

Install Docker and an editor with Dev Container support:

- [Zed](https://zed.dev/)
- [Visual Studio Code](https://code.visualstudio.com/) with the [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)

This template uses the published Linux graphics image:

```text
ghcr.io/eldritch-codex/arch-dev:main
```

The included `.devcontainer/devcontainer.json` uses NVIDIA by default with
`--gpus=all`. NVIDIA hosts need a working host driver and NVIDIA Container
Toolkit configured in Docker. See the [NVIDIA Container Toolkit installation
guide](https://docs.nvidia.com/datacenter/cloud-native/container-toolkit/latest/install-guide.html).

For Intel/AMD, comment the NVIDIA `runArgs` and uncomment the `/dev/dri`,
`video`, and `render` arguments. Keep exactly one `runArgs` block active.

## Getting Started

1. Create a repository from this template or clone it locally.
2. Open the project folder in Zed or Visual Studio Code.
3. Choose **Reopen in Container** or the equivalent Dev Container action.
4. Open a terminal inside the container.
5. Configure, build, and run the application:

   ```shell
   cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug \
       -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
   cmake --build build --target NodensApp
   ./build/NodensApp
   ```

Nodens builds with Clang. The container's default compiler is GCC, which does not build it, so name Clang when you configure.

The first CMake configuration downloads Nodens and its dependencies with `FetchContent`. You do not need to clone or build the Nodens repository separately.

This template uses Nodens [0.1.0](https://github.com/eldritch-codex/nodens/releases/tag/v0.1.0), pinned by `GIT_TAG v0.1.0` in `CMakeLists.txt`, so every build gets the same Nodens. While Nodens is at 0.x, a release that changes the API bumps the minor version. To upgrade, change the tag to a newer release and rebuild. To follow unreleased work, use a Nodens commit hash from `main` instead of a tag.
