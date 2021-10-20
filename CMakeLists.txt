cmake_minimum_required(VERSION 3.17)
project(Sort_Algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sort_Algorithm main.cpp bubbleSort.cpp selectSort.cpp insertSort.cpp shellSort.cpp mergeSort.cpp quickSort.cpp heapSort.cpp bucketSort.cpp)