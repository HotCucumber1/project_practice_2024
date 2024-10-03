cmake_minimum_required(VERSION 3.29)
project(projects_practice)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5.1 COMPONENTS graphics window system audio REQUIRED)

add_executable(projects_practice
        lw4/polar_rose.cpp)
target_link_libraries(projects_practice sfml-graphics sfml-window sfml-system sfml-audio)
