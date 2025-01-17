cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Output directories
set(BIN_DIR ${CMAKE_BINARY_DIR}/bin)
set(OBJ_DIR ${CMAKE_BINARY_DIR}/obj)
set(ASM_DIR ${CMAKE_BINARY_DIR}/asm)

# Include directories for header files
include_directories(${CMAKE_SOURCE_DIR})

# Source files
set(SOURCES main.c Max.c)
set(HEADERS Max.h)

# Add executables
add_executable(HelloWorld ${SOURCES})
set_target_properties(HelloWorld PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

add_executable(TestMax UTD/test_max.c Max.c)
set_target_properties(TestMax PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

# Target: "config"
add_custom_target(config
    COMMAND ${CMAKE_COMMAND} -E make_directory ${BIN_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${OBJ_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${ASM_DIR}
    COMMENT "Setting up folder structure: bin, obj, asm"
)

# Target: "build"
# Build executables, object files, and assembly files
add_custom_target(build ALL
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target HelloWorld
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target TestMax
    COMMAND ${CMAKE_C_COMPILER} -c ${CMAKE_SOURCE_DIR}/main.c -o ${OBJ_DIR}/main.o
    COMMAND ${CMAKE_C_COMPILER} -S ${CMAKE_SOURCE_DIR}/main.c -o ${ASM_DIR}/main.s
    COMMAND ${CMAKE_C_COMPILER} -c ${CMAKE_SOURCE_DIR}/Max.c -o ${OBJ_DIR}/Max.o
    COMMAND ${CMAKE_C_COMPILER} -S ${CMAKE_SOURCE_DIR}/Max.c -o ${ASM_DIR}/Max.s
    COMMENT "Building executables, object files, and assembly files"
    DEPENDS HelloWorld TestMax
)

# Target: "clean_all"
add_custom_target(clean_all ALL
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BIN_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${OBJ_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${ASM_DIR}
    COMMENT "Cleaning up build artifacts"
)
