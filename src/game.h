#ifndef __GAME_H__
#define __GAME_H__

#include "input.h"
#include "render.h"
#include "objectmanager.h"
#include "resourcemanager.h"

class Game
{
  private:
  Render *render;
  Input *input;
  ResourceManager *resources;
  ObjectManager *objects;

  public:
  Game();
  // Constructor
  
  ~Game();
  // Destructor
  
  void init();
  // Initializes the game

  Render* get_render();
  // EFFECTS: Returns a pointer to the game's render
  
  Input* get_input();
  // EFFECTS: Returns a pointer to the game's input
  
  ResourceManager* get_resource_manager();
  // EFFECTS: Returns a pointer to the game's resource manager

  ObjectManager* get_object_manager();
  // EFFECTS: Returns a pointer to the game's object manager
};

#endif
