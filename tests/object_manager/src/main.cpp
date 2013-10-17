#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "resourceids.h"
#include <engine.h>

// Our object that follows the mouse
class CookieMonsterObj: public GameObject
{
  public:
  
  CookieMonsterObj(Game *game) : GameObject(game)
  {
    // Make my sprite cookie monster
    game->get_resource_manager()->load_texture(IMG_COOKIEMONSTER);
    Sprite *mysprite = new Sprite;
    sf::Texture *tex = game->get_resource_manager()->get_texture(IMG_COOKIEMONSTER);
    std::cout << tex << "\n";
    mysprite->setTexture(*tex);
    this->add_animation();
    this->append_frame(0, mysprite);
    this->set_position(0,128);
  }

  void process_events()
  {
    move(1, 1);
  }
};

int main()
{
  GameSettings gamesettings;
  Game game(&gamesettings);
  game.init();
  
  // Instantiate the objects
  CookieMonsterObj object1(&game);
  CookieMonsterObj object2(&game);
  object1.set_position(0,128);
  object2.set_position(128,0);

  // Run the game
  while (game.is_running())
    game.update();

  return 0;
}
