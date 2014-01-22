#ifndef __OBJECTMANAGER_H__
#define __OBJECTMANAGER_H__

#include "engine_classes.h"
#include <map>
#include <vector>
#include "ids.h"
#include "game.h"
#include "gameobject.h"
#include "render.h"

class ObjectManager
{
  private:
    int current_obj_id;
    std::map<unsigned int, GameObject*> object_list;
    Game *game;
  
  public:
    ObjectManager(Game* game);
    // Constructor, needs a game to get info from
    
    virtual ~ObjectManager();

    unsigned int add_object(GameObject* object);
    // REQUIRES: object was already instantiated
    // MODIFIES: This
    // EFFECTS:  Stores the given object into the manager
    
    GameObject* get_object(unsigned int object_id);
    // EFFECTS: Returns a pointer to the object with the given id
    
    void destroy_object(unsigned int object_id);
    // REQUIRES: Object is stored in the manager
    // EFFECTS:  Destroys the object

    unsigned int find_object(ObjectType type, unsigned int n);
    // EFFECTS: Returns the id of the nth object of the given type. If there are no
    //          objects of the given type, it returns 0

    unsigned int count_objects(ObjectType type);
    // EFFECTS: Returns the number of active objects of the given type

    void process_events();
    // MODIFIES: Objects stored in this
    // EFFECTS:  Performs process_events() for all of the objects stored in the
    //           manager
    
    void draw_objects();
    // MODIFIES: Render
    // EFFECTS:  Draws the objects stored in manager to the render

    template<typename T>
      void instance_create(T obj, int x, int y);
    // MODIFIES: Active objects
    // EFFECTS:  Creates an object at the desired (x,y)
};
#endif
