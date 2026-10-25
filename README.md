# Nodens Application Template

A minimal C++23 application template using [Nodens](https://github.com/eldritch-codex/nodens).

> ⚠️ The published development environment currently builds and validates Nodens applications for Linux only. Native Windows and macOS builds are not currently supported or validated.

## Prerequisites

Install Docker and an editor with Dev Container support:

- [Zed](https://zed.dev/)
- [Visual Studio Code](https://code.visualstudio.com/) with the [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)

This template uses the published Linux graphics image:

```text
ghcr.io/eldritch-codex/arch-dev:main
```

The template has two Dev Container configurations, and your editor asks which
to open:

- `.devcontainer/nvidia/` for NVIDIA GPUs, using `--gpus=all`. The host needs a
  working driver and NVIDIA Container Toolkit configured in Docker. See the
  [NVIDIA Container Toolkit installation
  guide](https://docs.nvidia.com/datacenter/cloud-native/container-toolkit/latest/install-guide.html).
- `.devcontainer/dri/` for Intel and AMD GPUs, using `/dev/dri` and the `video`
  and `render` groups.

## Getting Started

1. Create a repository from this template or clone it locally.
2. Open the project folder in Zed or Visual Studio Code.
3. Choose **Reopen in Container** or the equivalent Dev Container action.
4. Open a terminal inside the container.
5. Configure, build, and run the application:

   ```shell
   cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
   cmake --build build --target NodensApp
   ./build/NodensApp
   ```

The container's default compiler is Clang, which Nodens requires.

The first CMake configuration downloads Nodens and its dependencies with `FetchContent`. You do not need to clone or build the Nodens repository separately.

This template uses Nodens [0.1.0](https://github.com/eldritch-codex/nodens/releases/tag/v0.1.0), pinned by `GIT_TAG v0.1.0` in `CMakeLists.txt`, so every build gets the same Nodens. While Nodens is at 0.x, a release that changes the API bumps the minor version. To upgrade, change the tag to a newer release and rebuild. To follow unreleased work, use a Nodens commit hash from `main` instead of a tag.
