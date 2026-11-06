
cmake_minimum_required(VERSION 3.16)    # specifies the minimum CMake version

project(CPunchPunch LANGUAGES CXX)      # names our project plus says C++ is the languaage

set(CMAKE_CXX_STANDARD 17)              # uses C++ 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)     

# Below are just commands to download Raylib automatically if not installed

include(FetchContent)                   # enables downloading external libraries

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)


# Create game executable
add_executable(CPunchPunch
    src/main.cpp
    src/HomePage.cpp
)

# Link Raylib
target_link_libraries(CPunchPunch PRIVATE raylib) #	connects your game to Raylib
