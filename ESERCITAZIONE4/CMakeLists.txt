cmake_minimum_required(VERSION 3.20)
project(ESERCITAZIONE4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMALE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

#creo il target però eseguibile principale del mio progetto software
set(SRC_test_sorts timecounter.cpp measure_sort.cpp)
add_executable(meausure_sort ${SRC_test_sorts})

#creo i target per gli eserguibili che effettueranno i test unitari 
add_executable(test_bubblesort test_bubblesort.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)


add_executable(test_insertionsort insertion_sort.cpp)
add_test(NAME insertionsort COMMAND test_insertionsort)

add_executable(test_selectionsort selection_sort.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

enable_testing()