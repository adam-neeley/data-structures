add_executable(Lab main.cpp A.h A.cpp)

target_include_directories(Lab PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
  Lab
  PRIVATE project_options
)
