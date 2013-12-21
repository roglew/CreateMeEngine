#include "resourceids.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <engine.h>

enum ObjectType: unsigned int
{
  OBJ_CROSS,

  OBJ_COUNT
};

// Our object that follows the mouse
class CrossObj: public GameObject
{
  public:
  
  CrossObj(Game *game) : GameObject(game)
  {
    type = OBJ_CROSS;
    
    // Make the spinning crosses
    Animation *my_animation = new Animation(game->get_resource_manager());
    my_animation->generate_from_id(ANIM_CROSS_SPIN);
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
