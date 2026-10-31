cmake_minimum_required(VERSION 3.30)

# CMake must know about experimental standard-library module support before
# project() enables the C++ language. Nodens requires this when consumed via
# FetchContent or add_subdirectory().
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "f35a9ac6-8463-4d38-8eec-5d6008153e7d")

project(NodensApp VERSION 0.3.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(nodens
    GIT_REPOSITORY https://github.com/eldritch-codex/nodens.git
    GIT_TAG        v0.3.0 # A release tag; change it to move to a newer Nodens release
)
FetchContent_MakeAvailable(nodens)

add_executable(NodensApp src/main.cpp)
target_link_libraries(NodensApp PRIVATE Nodens::Nodens)
