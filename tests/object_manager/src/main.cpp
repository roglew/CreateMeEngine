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
    AnimationStripConfig strip_config;
    strip_config->w = 250;
    strip_config->h = 224;
    Animation *my_animation = new Animation(strip_config);
    this->set_animation(my_animation);
    this->set_position(0,128);
  }

  ~CookieMonsterObj() : ~GameObject()
  {
    delete this->get_animation();
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
