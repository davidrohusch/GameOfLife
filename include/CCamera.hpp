#pragma once

#include "CGameboard.hpp"
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <vector>

class Camera {
private:
  int x, y, zoom;
  const size_t maxZoom = 10;
  std::shared_ptr<sf::RenderWindow> window;
  void drawGrid();
  void drawText(const int &gameSpeed);

public:
  Camera(int _x, int _y, int _zoom, std::shared_ptr<sf::RenderWindow> window);
  void drawScene(GameBoard &gamebaord, const int &gameSpeed);
  void zoomUp();
  void zoomDown();
};