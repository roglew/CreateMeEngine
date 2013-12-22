#include "resourceids.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <engine.h>

enum ObjectType: unsigned int
{
  OBJ_CROSS,
  OBJ_COOKIEMONSTER,

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
    int mx, my;
    mx = game->get_input()->mouse_position.x;
    my = game->get_input()->mouse_position.y;
    this->set_position(mx, my);
    if (this->collides(OBJ_COOKIEMONSTER))
    {
      next_frame();
    }
  }
};

// Cookie monster blocker
class CookieMonsterObj: public GameObject
{
  public:

  CookieMonsterObj(Game *game) : GameObject(game)
  {
    type = OBJ_COOKIEMONSTER;

    // Make the sprite
    Animation *my_animation = new Animation(game->get_resource_manager());
    my_animation->generate_from_id(ANIM_COOKIEMONSTER_STILL);
    this->set_animation(my_animation);
  }

  virtual ~CookieMonsterObj()
  {
    delete this->get_animation();
  }
};

int main()
{
  GameSettings gamesettings;
  Game game(&gamesettings);
  game.init();
  
  // Instantiate the objects
  CrossObj *cross1 = new CrossObj(&game);
  CrossObj *cross2 = new CrossObj(&game);
  CrossObj *cross3 = new CrossObj(&game);
  CrossObj *cross4 = new CrossObj(&game);
  CookieMonsterObj *cookie = new CookieMonsterObj(&game);
  cookie->set_position(128, 128);
  //ObjectManager *man = game.get_object_manager();
  //man->destroy_object(object2->get_id());
  //man->destroy_object(object1->get_id());
  unsigned int count = game.get_object_manager()->count_objects(OBJ_CROSS);
  printf("There are %d crosses\n", count);

  // Run the game
  while (game.is_running())
    game.update();

  printf("Ending game...\n");

  return 0;
}
