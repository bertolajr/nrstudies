cmake_minimum_required(VERSION 3.15) 
project(NumericalRecipes C)

include_directories(modules include src)

add_executable(
    numerical_recipes
    src/main.c
    modules/linear_algebra/gauss_jordan.c
    include/utils.c
)

