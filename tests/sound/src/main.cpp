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
    set_depth(-2);
    
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

void update_view(Game* game)
{
  if (game->get_input()->key[sf::Keyboard::Space].pressed)
  {
    sf::View *view = game->get_render()->get_view();
    int x, y;
    x = game->get_input()->mouse_position.x;
    y = game->get_input()->mouse_position.y;
    view->setCenter(x, y);
  }
}

int main()
{
  GameSettings gamesettings;
  Game game(&gamesettings);
  game.init();
  
  // Instantiate the objects
  CrossObj *cross = new CrossObj(&game);
  CookieMonsterObj *cookie = new CookieMonsterObj(&game);
  cookie->set_position(128, 128);

  // Run the game
  while (game.is_running())
  {
    update_view(&game);
    game.update();
  }

  printf("Ending game...\n");

  return 0;
}
