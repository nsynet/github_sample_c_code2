cmake_minimum_required(VERSION 3.0)

project(_nisy_ LANGUAGES C)

add_executable(_nisy_ main.c)

install(TARGETS _nisy_ RUNTIME DESTINATION bin)
