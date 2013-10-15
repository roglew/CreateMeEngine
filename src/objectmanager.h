#ifndef __OBJECTMANAGER_H__
#define __OBJECTMANAGER_H__

#include <map>
#include "game.h"
#include "gameobject.h"
#include "render.h"

class ObjectManager
{
  private:
    int current_obj_id;
    map<unsigned int, *GameObject> object_list;
    Game *game;
  
  public:
    ObjectManager(Game* game);
    // Constructor, needs a game to get info from
    
    ~ObjectManager();

    add_object(GameObject *object);
    // MODIFIES: This
    // EFFECTS:  Stores the given object into the manager

    process_events();
    // MODIFIES: Objects stored in this
    // EFFECTS:  Performs process_events() for all of the objects stored in the
    //           manager
    
    draw_objects();
    // MODIFIES: Render
    // EFFECTS:  Draws the objects stored in manager to the render
};

#endif
