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

template <class T>
unsigned int ObjectManager::add_object(int x, int y)
{
  GameObject *new_object = new T(current_obj_id);
  object_list[current_obj_id] = new_object;
  current_obj_id++;
  new_object->set_position(x, y);
  return (current_obj_id-1);
}

void ObjectManager::destroy_object(unsigned int id)
{
  delete object_list[id];
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
