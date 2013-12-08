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
    std::cout << "1\n";
    AnimationStripConfig strip_config;
    std::cout << "2\n";
    strip_config.w              = 250;
    strip_config.h              = 224;
    strip_config.start_x        = 0;
    strip_config.start_y        = 0;
    strip_config.hsep           = 0;
    strip_config.vsep           = 0;
    strip_config.frames_per_row = 1;
    strip_config.count          = 1;
    Animation *my_animation = new Animation(this->game->get_resource_manager());
    std::cout << "3n\n";
    my_animation->generate_from_strip(IMG_COOKIEMONSTER, &strip_config);
    std::cout << "4\n";
    this->set_animation(my_animation);
    std::cout << "5\n";
    this->set_position(0,128);
    std::cout << "6\n";
  }

  ~CookieMonsterObj()
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
