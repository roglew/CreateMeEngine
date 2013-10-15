#include "game.h"

Game::Game(GameSettings *settings)
{
  this->settings = settings;
  game_is_running = false;
}

Game::~Game()
{
  delete render;
  delete input;
  delete resources;
  delete objects;
}

void Game::init()
{
  game_is_running = true;
  render     = new Render;
  input      = new Input(*(this->render->get_created_window()));
  resources  = new ResourceManager;
  objects    = new ObjectManager(this);
}

void Game::update()
{
  // Update the game
  update_input();
  update_objects();

  // See if we died by clicking the X
  if (settings->end_on_window_close)
  {
    if (input->window.closed)
    {
      game_is_running = false;
    }
  }
  
  // See if we died by hitting escape
  if (settings->end_on_escape)
  {
    if (input->key[sf::Keyboard::Escape].pressed)
    {
      game_is_running = false;
    }
  }

  // If we died, kill the window
  if (!game_is_running)
  {
    render->get_created_window()->close();
  }
  
  // Last thing we do is draw
  update_draw();
}

bool Game::is_running()
{
  return game_is_running;
}

void Game::update_input()
{
  input->update();
}

void Game::update_objects()
{
  objects->process_events();
}

void Game::update_draw()
{
  render->clear();
  objects->draw_objects();
  render->render();
}


Render* Game::get_render()
{
  return render;
}

Input* Game::get_input()
{
  return input;
}

ResourceManager* Game::get_resource_manager()
{
  return resources;
}

ObjectManager* Game::get_object_manager()
{
  return objects;
}
