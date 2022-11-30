#include "CCamera.hpp"
#include <SFML/Graphics/Font.hpp>
#include <string>

Camera::Camera(int _x, int _y, int _zoom,
               std::shared_ptr<sf::RenderWindow> _window)
    : x(_x), y(_y), zoom(_zoom), window(_window) {}

void Camera::drawScene(GameBoard &gamebaord, const int &gameSpeed) {
  drawGrid();
  drawText(gameSpeed);
}

void Camera::drawGrid() {}

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
  
  std::string format = "X: " + std::to_string(x) + " Y: " + std::to_string(y) + "  Zoom:" + std::to_string(zoom) + "%" + "   Speed: " + speed;

  // set the string to display
  text.setString(format);   // jak to udělt lépe ?

  // set the character size
  text.setCharacterSize(16); // in pixels, not points!

  // set the color
  text.setFillColor(sf::Color::Black);

  // set the text style
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  window->draw(text);
}