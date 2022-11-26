#include "CGame.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

#include<iostream>

Game::Game(int height, int width){
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), "Game of Life");
        window->setFramerateLimit(60);
};

Game::~Game(){

};


void Game::handleEvents(){
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
};

void Game::run(){
    if (clock.getElapsedTime().asSeconds() >= 1.0f / speed){
    while (window->isOpen())
    {
        handleEvents();
        std::cout << "hey" << std::endl;
        window->clear();
        window->display();
        clock.restart();
    }
    }
}