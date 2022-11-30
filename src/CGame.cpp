#include "CGame.hpp"
#include "CCamera.hpp"
#include "CGameboard.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <bits/iterator_concepts.h>
#include <cstddef>
#include <fmt/core.h>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

Game::Game(int height, int width) : window (std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height),
                                              "Game of Life")), camera(0,0,0,window) {
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
        debug_print();
      }
    }
    if (eventBuffer.type == sf::Event::Closed)
      window->close();
  }
};

void Game::endStep() {
  window->display();
  framerateClock.restart();
}

[[maybe_unused]] void Game::handleKeyboardInputs() {
  // TODO: zoom in zoom out with cooldown
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
  //   fmt::print("xD\n");
  // }
}

void Game::beginStep() {
  window->clear(backgroundColor);
  handleEvents();
}

void Game::Step() {
  handleKeyboardInputs();
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