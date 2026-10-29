cmake_minimum_required(VERSION 3.15)
project(NumericalRecipes C)

include_directories(
    include
)

add_executable(
    nr
    src/nr.c
    src/common/utils.c
    src/linalg/gaussj.c
)