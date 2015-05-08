cmake_minimum_required(VERSION 3.2)

project(sfml_starter)
find_package(SFML REQUIRED)

file(GLOB SOURCES "src/*.cpp")
add_executable("sfml" ${SOURCES})
target_link_libraries(sfml sfml-graphics sfml-window sfml-system)

set_property(TARGET sfml PROPERTY CXX_STANDARD 11) # Use C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # Show all warnings
