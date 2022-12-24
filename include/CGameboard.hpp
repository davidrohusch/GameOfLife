#pragma once

#include <vector>

class GameBoard{
private:
  std::vector<std::vector<bool>> board;
  int max_x, max_y;
public:
  GameBoard(int max_x, int max_y);
  bool get_position(int x, int  y);
};