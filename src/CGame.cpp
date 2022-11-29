#include "CGame.hpp"
#include <SFML/Graphics.hpp>
#include <bits/iterator_concepts.h>
#include <memory>
#include <fmt/core.h>
#include <iostream>

Game::Game(int height, int width) {
  window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height),
                                              "Game of Life");
  window->setFramerateLimit(gameSpeed);
};

Game::~Game(){

};

void Game::handleEvents() {
  sf::Event event;
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window->close();
  }
};

void Game::endStep() {
  window->clear();
  window->display();
  clock.restart();
}

void Game::run() {

  while (window->isOpen()) {
    if (clock.getElapsedTime().asSeconds() >= 1.0f / speed) {
      fmt::print("Step\n");
      endStep();
    } else {
      handleEvents();
    }
  }
}