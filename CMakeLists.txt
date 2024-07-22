cmake_minimum_required(VERSION 3.28)
project(cash_c C)

set(CMAKE_C_STANDARD 11)

add_executable(cash_c main.c
        constants.h
        cash.c
        cash.h
        builtins.c
        builtins.h
        utils.c
        utils.h)
