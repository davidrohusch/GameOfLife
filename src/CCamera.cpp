#include "CCamera.hpp"
#include <SFML/Graphics/Font.hpp>

Camera::Camera(int _x, int _y, int _zoom, std::shared_ptr<sf::RenderWindow> _window): x(_x), y(_y), zoom(_zoom), window(_window){}

void Camera::drawScene(GameBoard &gamebaord){
  drawGrid();
  drawText();
}

void Camera::drawGrid(){

}

void Camera::drawText(){
sf::Text text;

// select the font
text.setFont(sf::Font()); // font is a sf::Font

// set the string to display
text.setString("Hello world");

// set the character size
text.setCharacterSize(24); // in pixels, not points!

// set the color
text.setFillColor(sf::Color::Red);

// set the text style
text.setStyle(sf::Text::Bold | sf::Text::Underlined);
window->clear();
//window->draw(text);
}