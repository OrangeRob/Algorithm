cmake_minimum_required(VERSION 3.15)
project(Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Cpp
        sort/InsertionSort.h
        main.cpp
        sort/MergeSort.h
        sort/SelectionSort.h
        sort/SortTestHelper.h
        Student.h sort/QuickSort.h data/MaxHeap.h)
