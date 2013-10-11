#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

enum ResourceImage {};
enum ResourceSound {};

class ResourceManager
{
	private:
		std::map<std::string, sf::Texture*> loaded_textures;

	public:
		// Constructor and destructor
		ResourceManager();
		~ResourceManager();

		void load_texture(std::string filename);
		void load_texture(ResourceImage rimage);
		// REQUIRES: The given file exists
		// MODIFIES: This
		// EFFECTS:  If the given image is not already loaded, it is loaded into
		//           memory as a sf::Texture

		void free_texture(std::string filename);
		void free_texture(ResourceImage rimage);
		// REQUIRES: file is loaded
		// MODIFIES: this
		// EFFECTS:  frees the texture and removes it from the manager

		bool texture_loaded(std::string filename);
		bool texture_loaded(ResourceImage rimage);
		// EFFECTS: Returns whether the given file is loaded

		sf::Texture* get_texture(std::string filename);
		sf::Texture* get_texture(ResourceImage rimage);
		// REQUIRES: The image is loaded
		// EFFECTS:  Returns a pointer to the loaded texture. Loads the image if
		//           it is not yet loaded
};

#endif
