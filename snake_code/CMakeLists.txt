cmake_minimum_required(VERSION 3.21)
project(snake)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

include_directories(include)

set(SOURCE_FILES
        src/snake.cpp
        src/fruit.cpp
        src/menu.cpp
        src/universal.cpp
        src/game.cpp
        src/menu_map.cpp)

add_executable(snake ${SOURCE_FILES} main.cpp)
