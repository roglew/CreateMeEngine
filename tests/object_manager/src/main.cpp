#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "resourceids.h"
#include <engine.h>

// Our object that follows the mouse
class CookieMonsterObj: private GameObject
{
  public:
  
  CookieMonsterObj(Game *game) : GameObject(game)
  {
    // Make my sprite cookie monster
    game->resources->load_texture(IMG_COOKIEMONSTER);
    Sprite *mysprite = new Sprite;
    sf::Texture *tex = game->resources->get_texture(IMG_COOKIEMONSTER);
    std::cout << tex << "\n";
    mysprite->setTexture(*tex);
    this->add_animation();
    this->append_frame(0, mysprite);
    this->input = input;
    this->set_position(0,128);
  }

  void process_events()
  {
    //set_position(input->mouse_position.x, input->mouse_position.y);
  }
};

int main()
{
  Game game;
  game->init();
  
  // Instantiate the objects
  CookieMonsterObj object1(game);
  CookieMonsterObj object2(game);
  object1.set_position(0,128);
  object2.set_position(128,0);

  // Run the game
  while (game->is_running())
    game->update();

  return 0;
}
