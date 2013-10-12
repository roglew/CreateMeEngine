#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "resourceids.h"
#include <engine.h>

// Our object that follows the mouse
class CookieMonsterObj: public GameObject
{
  private:
    Input* input;

  public:
  CookieMonsterObj(Input* input, ResourceManager* resources)
  {
    resources->load_texture(IMG_COOKIEMONSTER);
    Sprite *mysprite = new Sprite;
    sf::Texture *tex = resources->get_texture(IMG_COOKIEMONSTER);
    std::cout << tex << "\n";
    mysprite->setTexture(*tex);
    this->add_animation();
    this->append_frame(0, mysprite);
    this->input = input;
    this->set_position(0,128);
  }

  void process_events()
  {
    set_position(input->mouse_position.x, input->mouse_position.y);
  }
};

int main()
{
  Render render;
  ResourceManager resources;
  sf::RenderWindow *window = render.get_created_window();
  Input input(*window);
  
  CookieMonsterObj object(&input, &resources);

  while(window->isOpen()) {
    input.update();
    if (input.window.closed)
      window->close();
    object.process_events();
    render.clear();
    render.draw(object);
    render.render();
  }
  return 0;
}
