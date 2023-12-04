cmake_minimum_required(VERSION 3.24)
project(gwajae)

set(CMAKE_CXX_STANDARD 17)

add_executable(gwajae main.cpp sudoku/sudoku_solver.h sudoku/Random.h sudoku/sudoku_game_generator.h)
