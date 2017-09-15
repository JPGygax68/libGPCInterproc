cmake_minimum_required(VERSION 3.8)

project(GPCInterproc)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(lib)

enable_testing()
add_subdirectory(tests)