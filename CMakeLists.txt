cmake_minimum_required(VERSION 3.15) 
project(NumericalRecipes C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(C_EXTENSIONS OFF)

include_directories(modules include src)

add_executable(numerical_recipes src/main.c modules/linear_algebraic_equations/gauss_jordan.c)

