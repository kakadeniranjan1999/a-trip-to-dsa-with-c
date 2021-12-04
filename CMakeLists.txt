cmake_minimum_required(VERSION 3.20)
project(A_Trip_to_DSA_with_C C)

set(CMAKE_C_STANDARD 11)

add_executable(A_Trip_to_DSA_with_C DataStructures/Arrays/arrays.c DataStructures/Arrays/headers/ArrayAbstract.h DataStructures/Arrays/headers/BasicArrayOps.h DataStructures/Arrays/headers/AdvancedArrayOps.h)

add_executable(demo demo.c)