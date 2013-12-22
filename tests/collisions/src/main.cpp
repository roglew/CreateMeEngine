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

  virtual ~CrossObj()
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
  printf("Obj1 id: %d\n", object1->get_id());
  printf("Obj2 id: %d\n", object2->get_id());
  ObjectManager *man = game.get_object_manager();
  //man->destroy_object(object2->get_id());
  man->destroy_object(object1->get_id());
  unsigned int count = game.get_object_manager()->count_objects(OBJ_CROSS);
  printf("There are %d crosses\n", count);

  // Run the game
  while (game.is_running())
    game.update();

  printf("Ending game...\n");

  return 0;
}
