cmake_minimum_required(VERSION 3.18)
project(HotNCold CUDA CXX)

set(CMAKE_CUDA_STANDARD 20)
set(CMAKE_CXX_STANDARD 11)

add_executable(HotNCold
        src/main.cpp
        src/Grid.cpp
)

set_target_properties(HotNCold PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON
        LINKER_LANGUAGE CXX
)
