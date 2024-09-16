cmake_minimum_required(VERSION 3.15...3.30)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(Lab CXX)

add_library(project_options INTERFACE )

add_subdirectory(src)

add_custom_target(run make all COMMAND ./bin/Lab)
