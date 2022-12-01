#include "CGame.hpp"
#include "CCamera.hpp"
#include "CGameboard.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <bits/iterator_concepts.h>
#include <cstddef>
#include <fmt/core.h>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

Game::Game(int height, int width)
    : window(std::make_shared<sf::RenderWindow>(
          sf::VideoMode(width, height), "Game of Life", sf::Style::Close)),
      camera(0, 0, 0, window) {
  window->setFramerateLimit(frameRate);
  window->setKeyRepeatEnabled(false);
};

Game::~Game(){

};

void Game::debug_print(
    std::optional<std::string_view> text = std::nullopt) const {
  if (text.has_value()) {
    fmt::print("{}\n", text.value());
  }
}

void Game::handleEvents() {
  while (window->pollEvent(eventBuffer)) {
    handleKeyboardInputs();
    handleMouseInputs();

    if (eventBuffer.type == sf::Event::Closed)
      window->close();
  }
};

void Game::endStep() {
  window->display();
  framerateClock.restart();
}

void Game::handleMouseInputs(){
  
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && eventBuffer.type == sf::Event::MouseMoved){
    static size_t previousMouse_x, previousMouse_y;
    //fmt::print("|x:{}|x:{},y:{}\n", previousMouse_x,eventBuffer.mouseMove.x, eventBuffer.mouseMove.y);

    camera.move(previousMouse_x - eventBuffer.mouseMove.x, previousMouse_y - eventBuffer.mouseMove.y , Camera::MOVE_METHOD::RELATIVE);
    previousMouse_x = eventBuffer.mouseMove.x;
    previousMouse_y = eventBuffer.mouseMove.y;
  }

  if (eventBuffer.type == sf::Event::MouseWheelMoved) {
    switch (eventBuffer.mouseWheel.delta) {
    case -1:
      camera.zoomUp();
      break;
    case 1:
      camera.zoomDown();
      break;
    }
  }
}

void Game::handleKeyboardInputs() {
  if (eventBuffer.type == sf::Event::KeyPressed) {
    if (eventBuffer.key.code == sf::Keyboard::Right) {
      fmt::print("Speed up\n");
      tickSpeed = std::min(tickSpeedMAX, tickSpeed + 1);
    }
    if (eventBuffer.key.code == sf::Keyboard::Left) {
      fmt::print("Speed down\n");
      tickSpeed = std::max(tickSpeedMIN, std::min(tickSpeed - 1, tickSpeed));
    }
    if (eventBuffer.key.code == sf::Keyboard::Escape) {
      window->close();
    }

    if (eventBuffer.key.code == sf::Keyboard::D) {
      debug_print(std::to_string(tickSpeed));
    }
  }

}

void Game::beginStep() { window->clear(backgroundColor); }

void Game::Step() {
  handleEvents();
  camera.drawScene(gameboard, tickSpeed);
}

void Game::run() {

  while (window->isOpen()) {
    if (framerateClock.getElapsedTime().asSeconds() >= 1.0f / frameRate) {
      beginStep();
      Step();
      endStep();
    }
  }
}