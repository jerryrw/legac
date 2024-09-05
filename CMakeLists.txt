cmake_minimum_required(VERSION 3.0.0)
project(legac)

include_directories(./include)

add_library(lexer lexer.cpp)
add_library(sourcefile sourcefile.cpp)

#find_package(NAME REQUIRED)
#include_directories(${NAME_INCLUDE_DIRS})
#target_link_libraries(${PROJECT_NAME} ${NAME_LIBRARIES})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} lexer)
target_link_libraries(${PROJECT_NAME} sourcefile)