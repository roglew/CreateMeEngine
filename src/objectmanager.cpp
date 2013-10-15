#include "objectmanager.h"
#include <map>

ObjectManager::ObjectManager(Game* game)
{
  this->current_obj_id = 0;
  this->game           = game;
}

ObjectManager::~ObjectManager()
{
  std::map<int, *GameObject>::iterator it;
  
  for (it = object_list.begin(); it != object_list.end(); it++)
  {
    delete (*it).second;
  }
}

unsigned int ObjectManager::add_object(GameObject *object)
{
  object_list[current_obj_id] = object;
  current_obj_id++; // We can probably just do return id++
  return (current_obj_id-1);
}

void ObjectManager::destroy_object(unsigned int id)
{
  // Delete the object and remove the entry from the list
  if (object_list.find(id) != object_list.end())
  {
    delete object_list[id];
    object_list.erase(id);
  }
}

void ObjectManager::process_events()
{
  std::map<int, *GameObject>::iterator it;
  
  for (it = object_list.begin(); it != object_list.end(); it++)
  {
    // For each object in our list, execute process_events with respect
    // to our current game object
    (*it).second->process_events(this->game);
  }
}

void ObjectManager::draw_objects()
{
  std::map<int, *GameObject>::iterator it;
  
  for (it = object_list.begin(); it != object_list.end(); it++)
  {
    // Have the render draw each object
    game->render->draw(*(*it).second);
  }

}
