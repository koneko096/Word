cmake_minimum_required (VERSION 2.8.11)
project (adt)

add_library(adt SHARED
	array.c
	map.c
    matriks.c
    mesinkar.c
    mesinkata.c
    multilist.c
    point.c
    pqueue.c
    queue.c
    set.c
    stack.c
    tree.c
    lqstring.c
    jam.c
    user.c
    tanggal.c
)

set_target_properties(adt PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries(adt)