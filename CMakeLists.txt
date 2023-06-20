cmake_minimum_required(VERSION 3.16)
project(QUICKSORT LANGUAGES C CXX)

#setting standard liberary, C and C+++
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


enable_testing()

add_library(QuickSortMain
    ./Algorithm/Sources/Quick_Sort/Quick_Sort.c
)


target_include_directories(QuickSortMain PUBLIC  ./Algorithm/Headers/Quick_Sort
)

add_subdirectory(Algorithm)
add_subdirectory(Test)