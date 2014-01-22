#include <map>

ObjectManager::ObjectManager(Game* game)
{
  this->current_obj_id = 1; // We start at 1 so we can use 0 as a "no object" id
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

GameObject* ObjectManager::get_object(unsigned int object_id)
{
  return this->object_list[object_id];
}

void ObjectManager::destroy_object(unsigned int id)
{
  // Delete the object and remove the entry from the list
  std::map<unsigned int, GameObject*>::iterator it = this->object_list.find(id);
  std::map<unsigned int, GameObject*>::iterator to_remove;
  if (it != this->object_list.end())
  {
    GameObject *to_delete;
    to_delete = it->second;
    this->object_list.erase(it);
    if (to_delete)
      delete to_delete;
  }
}

unsigned int ObjectManager::find_object(ObjectType type, unsigned int n)
{
  // I plan on storing each object list in its own vector to make this faster
  // Right now using this to iterate through objects is going to be pretty slow
  // OPTIMIZE HERE

  unsigned int togo = n; // We use this to count how many we've passed
  unsigned int last_found;
  
  // Iterate through the map
  std::map<unsigned int, GameObject*>::iterator it = this->object_list.begin();
  while (it != this->object_list.end() && togo >= 0)
  {
    if ( it->second->type == type )
    {
      last_found = it->first;

      // If we have no more to count, return the last one we found
      if (togo == 0)
        return last_found;

      togo --;
    }
    it++;
  }

  // Return no object
  return 0;
}

unsigned int ObjectManager::count_objects(ObjectType type)
{
  // OPTIMIZE HERE TOO
  
  unsigned int found = 0;
  
  // Iterate through the map and count the number of objects with the given type
  std::map<unsigned int, GameObject*>::iterator it = this->object_list.begin();
  while (it != this->object_list.end())
  {
    if ( it->second->type == type )
    {
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
