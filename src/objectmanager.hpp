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

    unsigned int add_object(GameObject* object);
    // REQUIRES: T is a child of GameObject
    // MODIFIES: This
    // EFFECTS:  Stores the given object into the manager
    
    void destroy_object(unsigned int object_id);
    // REQUIRES: Object is stored in the manager
    // EFFECTS:  Destroys the object

    void process_events();
    // MODIFIES: Objects stored in this
    // EFFECTS:  Performs process_events() for all of the objects stored in the
    //           manager
    
    void draw_objects();
    // MODIFIES: Render
    // EFFECTS:  Draws the objects stored in manager to the render
};

#include "objectmanager.cpp"
