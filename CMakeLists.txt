cmake_minimum_required(VERSION 3.15)

project(oop_exercise_04)

include_directories(include)

# add_library(figure STATIC
#   functions.cpp
#   )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main
  src/main.cpp
  )

# target_link_libraries(main figure)
  
