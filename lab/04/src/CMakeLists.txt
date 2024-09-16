add_executable(Lab lab04Test.cpp week04Lab.cpp week04Lab.h)

target_include_directories(Lab PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
  Lab
  PRIVATE project_options
)
