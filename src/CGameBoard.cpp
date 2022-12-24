#include "CGameboard.hpp"
#include<iostream>

GameBoard::GameBoard(int max_x, int max_y): max_x(max_x), max_y(max_y) {
for(int i = 0; i < max_x ; i++){
    board.emplace_back(std::vector<bool>(max_y, false));
}
}