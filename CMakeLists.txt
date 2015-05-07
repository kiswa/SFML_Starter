cmake_minimum_required(VERSION 3.2)

project(sfml_starter)

find_package(SFML REQUIRED)

file(GLOB SOURCES
    "src/*.hpp"
    "src/*.cpp")

add_executable("sfml" ${SOURCES})

set_property(TARGET sfml PROPERTY CXX_STANDARD 11)
target_link_libraries(sfml sfml-graphics sfml-window sfml-system)
