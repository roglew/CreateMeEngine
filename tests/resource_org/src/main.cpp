#include <iostream>
#include <SFML/Graphics.hpp>
#include <render.h>
#include <input.h>
#include "resourceids.h"


int main()
{
  Render render;
  sf::RenderWindow *window = render.get_created_window();
  Input input(*window);

  while(window->isOpen()) {
    input.update();
    if (input.window.closed)
      window->close();
    render.clear();
    render.render();
  }
  return 0;
}
