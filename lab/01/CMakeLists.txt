cmake_minimum_required(VERSION 3.15...3.30)

project(
  Lab
  VERSION 1.0
  LANGUAGES CXX)

add_library(Bag Bag.cpp Bag.h)

add_executable(Lab main.cpp)

target_link_libraries(Lab PRIVATE Bag)
