cmake_minimum_required(VERSION 3.10)
project(jogoDaBola)

set(CMAKE_C_STANDARD 11) 

include_directories(inc) 

file(GLOB SRC_FILES "src/*.c")

add_executable(${PROJECT_NAME} main.c ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} raylib GL m pthread dl rt X11)

