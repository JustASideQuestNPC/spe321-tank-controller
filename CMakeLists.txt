cmake_minimum_required(VERSION 3.26)
project(spe321_robot_raylib)

set(CMAKE_CXX_STANDARD 20)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

# Adding our source files
#file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
#set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

add_executable(robot_controller src/main.cpp
        src/Window.hpp)
target_link_libraries(robot_controller PRIVATE raylib)

add_executable(gamepad_test src/gamepad-test.cpp
        src/Window.hpp
        src/Gamepad.hpp
        src/Gamepad.cpp
        src/Vec2D.cpp
        src/Vec2D.hpp)
target_link_libraries(gamepad_test PRIVATE raylib)