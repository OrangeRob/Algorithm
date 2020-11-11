# CMakeList.txt : CMake project for AlgoritmDS, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("AlgorithmDS")

set(ALGORITHM_INC ${CMAKE_CURRENT_LIST_DIR}/algorithm)
set(UTILS_INC ${CMAKE_CURRENT_LIST_DIR}/utils)

include_directories(${ALGORITHM_INC} ${UTILS_INC})

set(CMAKE_CXX_STANDARD 17)

# Add source to this project's executable.
add_executable (AlgorithmDS "main.cpp" "test.cpp")

# TODO: Add tests and install targets if needed.
