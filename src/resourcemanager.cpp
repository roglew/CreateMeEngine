#include <SFML/Graphics.hpp>
#include <map>
#include "resourcemanager.h"

ResourceManager::~ResourceManager()
{
	// Iterate through all the loaded textures, free them, and delete the
	// pointers
	std::map<std::string, sf::Texture*>::iterator it;
	
	for (it = loaded_textures.begin(); it != loaded_textures.end(); it++)
	{
		delete (*it).second;
	}
}

void ResourceManager::load_texture(std::string filename)
{
	if (!texture_loaded(filename))
	{
		// If the texture is not in the map, load it
		sf::Texture* new_tex = new sf::Texture;
		new_tex->loadFromFile(filename);
	}
}

bool ResourceManager::texture_loaded(std::string filename)
{
	if (loaded_textures.find(filename) == loaded_textures.end())
		return false;
	else
		return true;
}

sf::Texture* ResourceManager::get_texture(std::string filename)
{
	return loaded_textures[filename];
}
