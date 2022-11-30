#pragma once
#include "CCamera.hpp"
#include "CGameboard.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <cstddef>
#include <iostream>
#include <memory>
#include <optional>

class Game {
private:
  const size_t frameRate = 60;
  const size_t tickSpeedMAX = 10;
  const size_t tickSpeedMIN = 1;
  size_t tickSpeed = 5;

  std::shared_ptr<sf::RenderWindow> window;
  sf::Clock framerateClock;

  sf::Event eventBuffer;
  Camera camera;
  GameBoard gameboard;
  sf::Color backgroundColor{255, 255, 255, 255};

  void handleEvents();
  void beginStep();
  void Step();
  void endStep();
  void handleKeyboardInputs();

  void debug_print(std::optional<std::string_view> text) const;

public:
  Game(int height, int width);
  ~Game();

  void run();
};