#include "objectmanager.h"
#include <map>

ObjectManager::ObjectManager(Game* game)
{
  this->current_obj_id = 0;
  this->game           = game;
}

ObjectManager::~ObjectManager()
{
  std::map<unsigned int, GameObject*>::iterator it;
  
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
  std::map<unsigned int, GameObject*>::iterator it = this->object_list.find(id);
  if (it != this->object_list.end())
  {
    GameObject *to_delete;
    to_delete = object_list[id];
    object_list.erase(it);
    delete to_delete;
  }
}

GameObject* ObjectManager::find_object(ObjectType type, unsigned int n)
{
  // I plan on storing each object list in its own vector to make this faster
  // Right now using this to iterate through objects is going to be pretty slow
  // OPTIMIZE HERE

  unsigned int togo = n; // We use this to count how many we've passed
  GameObject *last_found;
  
  // Iterate through the map
  std::map<unsigned int, GameObject*>::iterator it = this->object_list.begin();
  while (it != this->object_list.end() && togo >= 0)
  {
    if ( it->second->type == type )
    {
      last_found = it->second;

      // If we have no more to count, return the last one we found
      if (togo == 0)
        return last_found;

      togo --;
    }
  }

  return NULL;
}

unsigned int ObjectManager::count_objects(ObjectType type)
{
  // OPTIMIZE HERE TOO
  
  unsigned int found = 0;
  
  // Iterate through the map and count the number of objects with the given type
  std::map<unsigned int, GameObject*>::iterator it = this->object_list.begin();
  printf("1\n");
  while (it != this->object_list.end())
  {
    printf("2\n");
    if ( it->second->type == type )
    {
      printf("3\n");
      found ++;
    }
    it++;
  }

  return found;
}

void ObjectManager::process_events()
{
  std::map<unsigned int, GameObject*>::iterator it;
  
  for (it = object_list.begin(); it != object_list.end(); it++)
  {
    // For each object in our list, execute process_events with respect
    // to our current game object
    (*it).second->process_events();
  }
  it++;
}

void ObjectManager::draw_objects()
{
  std::map<unsigned int, GameObject*>::iterator it;
  
  for (it = object_list.begin(); it != object_list.end(); it++)
  {
    // Have the render draw each object
    GameObject *obj;
    obj = it->second;
    Render *render;
    render = game->get_render();
    render->draw(*obj, obj->get_depth());
  }

}
