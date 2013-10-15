#include "game.h"

Game::Game()
{
  // pass
}

Game::~Game()
{
  delete render;
  delete input;
  delete resources;
  delete objects;
}

Game::init()
{
  render    = new Render;
  input     = new Input;
  resources = new ResourceManager;
  objects   = new ObjectManager;
}


Render* get_render()
{
  return render;
}

Input* get_input()
{
  return input;
}

ResourceManager* get_resource_manager()
{
  return resources;
}

ObjectManager* get_object_manager()
{
  return objects;
}
