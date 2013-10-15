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
  input     = new Input(this);
  resources = new ResourceManager;
  objects   = new ObjectManager(this);
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
