#include "CGame.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <bits/iterator_concepts.h>
#include <fmt/core.h>
#include <iostream>
#include <memory>

Game::Game(int height, int width) {
  window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height),
                                              "Game of Life");
  window->setFramerateLimit(gameSpeed);
};

Game::~Game(){

};

void Game::handleEvents() {

  while (window->pollEvent(eventBuffer)) {

    if (eventBuffer.type == sf::Event::Closed)
      window->close();
  }
};

void Game::endStep() {
  window->display();
  clock.restart();
}

void Game::handleKeyboardInputs() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    fmt::print("Speed up\n");
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    fmt::print("Speed up\n");
  }

}

void Game::beginStep() {
  window->clear();

}

void Game::Step() { handleKeyboardInputs(); }

void Game::run() {

  while (window->isOpen()) {
    if (clock.getElapsedTime().asSeconds() >= 1.0f / speed) {
      beginStep();
      Step();
      endStep();
    } else {
      handleEvents();
    }
  }
}