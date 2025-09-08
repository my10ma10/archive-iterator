cmake_minimum_required(VERSION 3.10)

project(IteratorPattern)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(iter main.cpp 
    src/archive/archive.cpp  src/archive/archive.hpp
    src/iterators/iterarors.cpp src/iterators/iterators.hpp
    src/nodes/nodes.cpp src/nodes/nodes.hpp
    src/ranges/ranges.cpp src/ranges/ranges.hpp
)

target_include_directories(iter PUBLIC
    src
    src/archive
    src/iterators
    src/nodes
    src/ranges
)

target_compile_options(iter PRIVATE
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:Debug>:-Og>
)

target_compile_options(iter PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)