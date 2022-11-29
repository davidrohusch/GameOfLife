#pragma once
#include "CCamera.hpp"
#include "CGameboard.hpp"
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <iostream>
#include <memory>

class Game {
private:
  std::unique_ptr<sf::RenderWindow> window;
  int speed = 60;
  sf::Clock clock;
  size_t gameSpeed = 60;
  sf::Event eventBuffer;
  Camera camera{0, 0, 0};
  GameBoard gameboard;

  void handleEvents();
  void beginStep();
  void Step();
  void endStep();
  void handleKeyboardInputs();

public:
  Game(int height, int width);
  ~Game();

  void run();
};