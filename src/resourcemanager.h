#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "engine_classes.h"
#include "ids.h"

class ResourceManager
{
  private:
    std::map<std::string, sf::Texture*> loaded_textures;
    std::map<std::string, sf::SoundBuffer*> loaded_sounds;
    std::vector<sf::Sound*> active_sounds;
    std::vector<sf::Music*> active_music;

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

    void load_sound(std::string filename);
    void load_sound(ResourceSound rsound);
    // REQUIRES: The given file exists
    // MODIFIES: This
    // EFFECTS:  If the given sound is not already loaded, it is loaded into
    //           memory as a sf::SoundBuffer

    void free_texture(std::string filename);
    void free_texture(ResourceImage rimage);
    // REQUIRES: file is loaded
    // MODIFIES: this
    // EFFECTS:  frees the texture and removes it from the manager

    void free_sound(std::string filename);
    void free_sound(ResourceSound rsound);
    // REQUIRES: file is loaded
    // MODIFIES: this
    // EFFECTS:  frees the soundbuffer and removes it from the manager

    bool texture_loaded(std::string filename);
    bool texture_loaded(ResourceImage rimage);
    // EFFECTS: Returns whether the given texture is loaded

    bool sound_loaded(std::string filename);
    bool sound_loaded(ResourceSound rsound);
    // EFFECTS: Returns whether the given sound is loaded

    sf::Texture* get_texture(std::string filename);
    sf::Texture* get_texture(ResourceImage rimage);
    // REQUIRES: The image is loaded
    // EFFECTS:  Returns a pointer to the loaded texture. Loads the image if
    //           it is not yet loaded

    sf::SoundBuffer* get_sound(std::string filename);
    sf::SoundBuffer* get_sound(ResourceSound rsound);
    // REQUIRES: The sound is loaded
    // EFFECTS:  Returns a pointer to the loaded SoundBuffer. Loads the sound if
    //           it is not yet loaded

    void play_sound(std::string filename);
    void play_sound(ResourceSound rsound);
    // REQUIRES: < 256 sounds are currently playing
    // EFFECTS:  Plays a sound (loads it if not already loaded)

    void play_music(std::string filename);
    void play_music(ResourceMusic rmusic);
    // REQUIRES: < 256 sounds are currently playing
    // EFFECTS:  Plays a music

    void clean_audio();
    // MODIFIES: this
    // EFFECTS:  Prunes the list of active sounds and music for any audio that is stopped

    unsigned int count_active_audio();
    // EFFECTS: Returns the number of active audio instances
};

#endif
