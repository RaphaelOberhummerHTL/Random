cmake_minimum_required(VERSION 3.22.1)

if(WIN32)
    set(EXECUTABLE_OUTPUT_PATH ../../bin/Windows)
elseif(UNIX)
    set(EXECUTABLE_OUTPUT_PATH ../../bin/Linux)
endif()

project(Random)

add_executable(${PROJECT_NAME} main.c)
add_library(Parameter Parameter/Parameter.h Parameter/Parameter.c)
target_link_libraries(${PROJECT_NAME} PRIVATE Parameter)
