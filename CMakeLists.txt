# Project Configuration

# Project name
set(PNAME SfmlStarter)

# SFML version - set the minimum version you'd like to use.
set(SFML_VERSION 2.3)

# SFML components - list all you want to use.
# The provided framework requires graphics, window, and system.
set(SFML_COMPONENTS graphics window system)

# You shouldn't have to edit anything below this line to get started.

cmake_minimum_required(VERSION 3.2)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(${PNAME})
find_package(SFML ${SFML_VERSION} COMPONENTS ${SFML_COMPONENTS} REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

file(GLOB SOURCES "src/*.cpp")
add_executable(${PNAME} ${SOURCES})
target_link_libraries(${PNAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

set_property(TARGET ${PNAME} PROPERTY CXX_STANDARD 11) # Use C++11

if(NOT WIN32 OR MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # Show all warnings for GCC
endif()
