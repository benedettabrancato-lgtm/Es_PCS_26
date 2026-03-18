cmake_minimum_required(VERSION 3.20)
project(ESERCITAZIONE2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SOURCES ES2.cpp)

add_executable(ES2 ES2.cpp)
add_executable(ES1 ES1.cpp )

