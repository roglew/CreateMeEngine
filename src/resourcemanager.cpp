#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include "resourcemanager.h"

extern std::string IMAGE_PATHS[];
extern std::string SOUND_PATHS[];

ResourceManager::ResourceManager()
{
  // Do nothing
}

ResourceManager::~ResourceManager()
{
  // Iterate through all the loaded textures, free them, and delete the
  // pointers
  std::map<std::string, sf::Texture*>::iterator it;
  
  for (it = loaded_textures.begin(); it != loaded_textures.end(); it++)
  {
    delete it->second;
    it->second = NULL;
  }
}

void ResourceManager::load_texture(std::string filename)
{
  if (!texture_loaded(filename))
  {
    // If the texture is not in the map, load it
    sf::Texture* new_tex = new sf::Texture;
    new_tex->loadFromFile(filename);
    loaded_textures[filename] = new_tex;
  }
}

void ResourceManager::load_texture(ResourceImage rimage)
{
  load_texture(IMAGE_PATHS[rimage]);
}

bool ResourceManager::texture_loaded(std::string filename)
{
  if (loaded_textures.find(filename) == loaded_textures.end())
    return false;
  else
    return true;
}

bool ResourceManager::texture_loaded(ResourceImage rimage)
{
  return texture_loaded(IMAGE_PATHS[rimage]);
}

sf::Texture* ResourceManager::get_texture(std::string filename)
{
  load_texture(filename);
  return loaded_textures[filename];
}

sf::Texture* ResourceManager::get_texture(ResourceImage rimage)
{
  return get_texture(IMAGE_PATHS[rimage]);
}
