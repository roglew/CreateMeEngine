#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceManager
{
	private:
		std::map<std::string, sf::Texture*> loaded_textures;

	public:
		// Constructor and destructor
		ResourceManager();
		~ResourceManager();

		void load_texture(std::string filename);
		// REQUIRES: The given file exists
		// MODIFIES: This
		// EFFECTS:  If the given image is not already loaded, it is loaded into
		//           memory as a sf::Texture

		void free_texture(std::string filename);
		// REQUIRES: file is loaded
		// MODIFIES: this
		// EFFECTS:  frees the texture and removes it from the manager

		bool texture_loaded(std::string filename);
		// EFFECTS: Returns whether the given file is loaded

		sf::Texture* get_texture(std::string filename);
		// REQUIRES: The image is loaded
		// EFFECTS:  Returns a pointer to the loaded texture. Returns NULL if
		//           the texture is not loaded
};

#endif
