cmake_minimum_required(VERSION 3.24)

project(gameoflife)
set (CMAKE_CXX_STANDARD 20)
# add_compile_options(-Wall -Wextra -pedantic -g -fsanitize=address)
# add_link_options(-fsanitize=address)
add_compile_options(-Wall -Wextra -pedantic -g)
include_directories(include src)
link_libraries(sfml-graphics sfml-window sfml-system fmt)
add_executable(gameoflife src/main.cpp src/CGame.cpp src/CCamera.cpp src/CGameBoard.cpp)

