#include <map>
#include "objectmanager.h"

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

ObjectManager::add_object(GameObject *object)
{
  object_list[current_obj_id] = object;
}

ObjectManager::process_events()
{
  
}

ObjectManager::draw_objects()
{
  

}
