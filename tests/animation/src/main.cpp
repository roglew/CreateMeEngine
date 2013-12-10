#include <iostream>
#include <stdio.h>
#include <string>
#include <SFML/Graphics.hpp>
#include "resourceids.h"
#include <engine.h>

void print_strip_config(AnimationStripConfig *config)
{
  std::cout << "Strip config at " << config << ":\n";
  printf("start_x: %d\n", config->start_x);
  printf("start_y: %d\n", config->start_y);
  printf("w: %d\n", config->w);
  printf("h: %d\n", config->h);
  printf("hsep: %d\n", config->hsep);
  printf("vsep: %d\n", config->vsep);
  printf("frames_per_row: %d\n", config->frames_per_row);
  printf("count: %d\n", config->count);
}

// Our object that follows the mouse
class CrossObj: public GameObject
{
  public:
  
  CrossObj(Game *game) : GameObject(game)
  {
    // Make my sprite cookie monster
    AnimationStripConfig strip_config;
    strip_config.w              = 32;
    strip_config.h              = 32;
    strip_config.count          = 4;
    strip_config.frames_per_row = 4;
    ResourceManager *resources = this->game->get_resource_manager();
    Animation *my_animation = new Animation(resources);
    my_animation->generate_from_strip(IMG_CROSS, &strip_config);
    this->set_animation(my_animation);
    this->set_position(0, 128);
  }

  ~CrossObj()
  {
    delete this->get_animation();
  }
  
  void process_events()
  {
    move(1, 1);
    next_frame();
  }
};

int main()
{
  GameSettings gamesettings;
  Game game(&gamesettings);
  game.init();
  
  // Instantiate the objects
  CrossObj *object1 = new CrossObj(&game);
  CrossObj *object2 = new CrossObj(&game);
  object1->set_position(0,128);
  object2->set_position(128,0);

  // Run the game
  while (game.is_running())
    game.update();

  return 0;
}
