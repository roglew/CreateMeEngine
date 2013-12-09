#include "game.h"

void print_game_settings(GameSettings *settings)
{
  printf("Printing settings at %p:\n", settings);
  printf("end_on_escape: %d\n", settings->end_on_escape);
  printf("end_on_window_close: %d\n", settings->end_on_window_close);
  printf("fps: %d\n", settings->fps);
  printf("limit_fps: %d\n", settings->limit_fps);
}

Game::Game(GameSettings *config)
{
  this->settings = config;
  this->game_is_running = false;
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
  this->update_input();
  this->update_objects();

  // See if we died by clicking the X
  if (this->settings->end_on_window_close)
  {
    if (this->input->window.closed)
    {
      this->game_is_running = false;
    }
  }
  
  // See if we died by hitting escape
  if (this->settings->end_on_escape)
  {
    if (this->input->key[sf::Keyboard::Escape].pressed)
    {
      this->game_is_running = false;
    }
  }

  // If we died, kill the window
  if (!this->game_is_running)
  {
    this->render->get_created_window()->close();
  }
  
  // Last thing we do is draw
  this->update_draw();
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
