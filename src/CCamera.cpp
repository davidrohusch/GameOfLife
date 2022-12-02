#include "CCamera.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>
#include <fmt/core.h>

Camera::Camera(int _x, int _y, int _zoom,
               std::shared_ptr<sf::RenderWindow> _window)
    : x(_x), y(_y), zoom(_zoom), window(_window) {}

void Camera::drawScene(GameBoard &gamebaord, const int &gameSpeed) {
  drawGrid();
  drawText(gameSpeed);
}

void Camera::drawGrid() {

  sf::Color defaultColor = sf::Color::Blue;
  std::vector<sf::Vertex> vertices;
  unsigned int x_pos = 0, y_pos = 0;
  int spacing = (20 + zoom * 10); // calculate from zoom
  while (x_pos < window->getSize().x) {
    size_t position =  x_pos - x%spacing;
    vertices.push_back(sf::Vertex(sf::Vector2f(position, 0), defaultColor));
    vertices.push_back(
        sf::Vertex(sf::Vector2f(position, window->getSize().y), defaultColor));
    x_pos += spacing;
  }

  while (y_pos < window->getSize().y) {
    size_t position =  y_pos - y%spacing;
    vertices.push_back(sf::Vertex(sf::Vector2f(0, position), defaultColor));
    vertices.push_back(
        sf::Vertex(sf::Vector2f(window->getSize().x, position), defaultColor));
    y_pos += spacing;
  }
  // draw it

  window->draw(vertices.data(), vertices.size(), sf::Lines);
}

void Camera::drawText(const int &gameSpeed) {
  sf::Text text;

  /////////// TO DO   ///////////////
  /////////// TO DO   ///////////////
  /// Přenést do private body a font načítat s jistotou.
  // select the font
  sf::Font font;
  if (!font.loadFromFile("../arial.ttf")) {
    // error...
  }

  text.setFont(font); // font is a sf::Font
  /////////// TO DO   ///////////////
  /////////// TO DO   ///////////////

  std::string speed;
  if (gameSpeed == 0)
    speed = "PAUSED";
  else
    speed = std::to_string(gameSpeed);

  std::string format = "X: " + std::to_string(x) + " Y: " + std::to_string(y) +
                       "  Zoom:" + std::to_string(zoom * 10) + "%" +
                       "   Speed: " + speed;

  // set the string to display
  text.setString(format); // jak to udělt lépe ?

  // set the character size
  text.setCharacterSize(16); // in pixels, not points!

  // set the color
  text.setFillColor(sf::Color::Black);

  // set the text style
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  window->draw(text);
}

void Camera::zoomDown() {
  if (zoom < maxZoom)
    zoom++;
}

void Camera::zoomUp() {
  if (zoom > 0)
    zoom--;
}

void Camera::move(int _x, int _y, MOVE_METHOD method) {
  if (method == MOVE_METHOD::RELATIVE) {
    x += _x;
    y += _y;

    fmt::print("moved by {} {} \n", _x, _y);
  }
}
