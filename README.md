<h1 align="center">Nodens Application Template</h1>

<h3 align="center">A minimal C++23 application template for the Nodens framework.</h3>

<p align="center">
  <a href="https://github.com/eldritch-codex/nodens/releases/tag/v0.3.0"><img src="https://img.shields.io/badge/Nodens-0.3.0-blue?style=flat-square" alt="Nodens 0.3.0"></a>
  <img src="https://img.shields.io/badge/C%2B%2B-23-blue?style=flat-square" alt="C++23">
  <img src="https://img.shields.io/badge/CMake-3.30-blue?style=flat-square" alt="CMake 3.30">
  <img src="https://img.shields.io/badge/platform-Linux-blue?style=flat-square" alt="Platform: Linux">
  <a href="https://opensource.org/licenses/MIT"><img src="https://img.shields.io/badge/license-MIT-yellow?style=flat-square" alt="License: MIT"></a>
</p>

<p align="center">
  <a href="https://github.com/eldritch-codex/nodens/blob/main/docs/guide/getting-started.md">Getting Started</a> ·
  <a href="https://github.com/eldritch-codex/nodens/blob/main/docs/guide/README.md">Guide</a> ·
  <a href="https://github.com/eldritch-codex/nodens">Nodens</a>
</p>

> **Status:** the template builds against Nodens 0.3.0. Nodens is experimental, and a breaking change bumps its minor version.
>
> **Limitations:** the published development environment builds and validates Nodens applications for Linux only. Native Windows and macOS builds are not supported or validated.

## Introduction

A minimal application that uses [Nodens](https://github.com/eldritch-codex/nodens). On GitHub, select **Use this template** to create your own repository, then build and run it in the development environment below. The template fetches Nodens with CMake `FetchContent`, so you do not need to clone or build the Nodens repository separately.

## Nodens version

The Nodens version is pinned by `GIT_TAG` in `CMakeLists.txt`, so every build gets the same Nodens. While Nodens is at 0.x, a release that changes the API bumps the minor version. To upgrade, change the tag to a newer release and rebuild. To follow unreleased work, use a Nodens commit hash from `main` instead of a tag.

## Development environment

### Prerequisites

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

### Getting started

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

The container's default compiler is Clang, which Nodens requires. The first CMake configuration downloads Nodens and its dependencies.

### Zed on the host

If Zed runs outside the container, `.zed/tasks.json` and `.zed/debug.json` run the build and the debugger inside it with the [Dev Containers CLI](https://github.com/devcontainers/cli):

```shell
npm install -g @devcontainers/cli
```

Run the **Docker: Start** task once, then use the Build, Run and debug tasks. They use the NVIDIA configuration. On Intel or AMD, replace `nvidia` with `dri` in `.zed/tasks.json`, `.zed/debug.json` and `.zed/settings.json`. The debugger needs CodeLLDB in the container image (`/opt/codelldb`).

## Acknowledgements

In September 2026 I started experimenting with LLM coding agents (Claude Code, ZedAI and Pi) and even decided to develop my own: [Armitage](https://eldritchcodex.com/armitage/). I use them mostly to learn new stuff, but also they help with documentation, CI/CD and general project upkeep. Commits carry no co-author or AI attribution trailers, since I am responsible for every commit.

## License

Copyright (c) 2026 EldritchCodex. The project and its entire history are licensed under the MIT License.
