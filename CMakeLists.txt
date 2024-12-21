cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

set(CMAKE_C_STANDARD 99)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(HelloWorld main.c print.c)