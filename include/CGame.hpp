#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class Game{
private:
    std::unique_ptr<sf::RenderWindow> window;
    int speed = 60;
    sf::Clock clock;
    void handleEvents();
public:
    Game(int height, int width);
    ~Game();

    void run();
};