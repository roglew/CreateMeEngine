#ifndef __GAME_H__
#define __GAME_H__

#include "engine_classes.h"
#include "input.h"
#include "render.h"
#include "objectmanager.h"
#include "resourcemanager.h"

struct GameSettings
{
  char         end_on_escape       = true;
  char         end_on_window_close = true;
  unsigned int fps                 = 60;
  char         limit_fps           = true;
};

class Game
{
  private:
    GameSettings *settings;
    char game_is_running;

    Render *render;
    Input *input;
    ResourceManager *resources;
    ObjectManager *objects;

  public:
    Game(GameSettings *settings);
    // REQUIRES: settings stay alive while game is running

    ~Game();
    // Destructor

    void init();
    // Initializes the game

    void update();
    // Updates the game

    bool is_running();
    // EFFECTS: Returns true if the game is running, false otherwise

    void update_input();
    // MODIFIES: input
    // EFFECTS:  Updates the input

    void update_objects();
    // MODIFIES: objects
    // EFFECTS:  updates all of the objects

    void update_draw();
    // MODIFIES: render
    // EFFECTS:  Draws the objects onto the render and updates the render
  
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
