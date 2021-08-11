cmake_minimum_required (VERSION 2.8.11)
project (word)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory (adt)
add_subdirectory (display)

add_executable (wordament main.c)
target_link_libraries(wordament interface adt)