cmake_minimum_required (VERSION 2.8.11)
project (interface)

add_library(interface SHARED
    menu.c
    board.c
    displayboard.c
    interface.c
)

set_target_properties(interface PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries(interface adt)