
cmake_minimum_required(VERSION 3.16)

project(CPunchPunch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download Raylib automatically if not installed
include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

# Create game executable
add_executable(CPunchPunch src/main.cpp)

# Link Raylib
target_link_libraries(CPunchPunch PRIVATE raylib)
