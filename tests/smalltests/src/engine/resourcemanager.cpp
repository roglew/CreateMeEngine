#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include "resourcemanager.h"

extern std::string IMAGE_PATHS[];
extern std::string SOUND_PATHS[];
extern std::string MUSIC_PATHS[];

static bool sound_is_stopped(sf::Sound *sound)
{
  return ( sound->getStatus() == sf::SoundSource::Stopped );
}

static bool music_is_stopped(sf::Music *music)
{
  return ( music->getStatus() == sf::SoundSource::Stopped );
}

ResourceManager::ResourceManager()
{
  // Do nothing
}

ResourceManager::~ResourceManager()
{
  free_all();
}

// Misc

void ResourceManager::free_all()
{
  // Free loaded textures
  std::map<std::string, sf::Texture*>::iterator it;
  for (it = loaded_textures.begin(); it != loaded_textures.end(); it++)
    free_texture(it->first);

  // Free loaded sounds
  std::map<std::string, sf::SoundBuffer*>::iterator it2;
  for (it2 = loaded_sounds.begin(); it2 != loaded_sounds.end(); it2++)
    free_sound(it2->first);
}

// Texture loading

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

// Sound loading

void ResourceManager::load_sound(std::string filename)
{
  if (!sound_loaded(filename))
  {
    // If the sound is not in the map, load it
    sf::SoundBuffer* new_snd = new sf::SoundBuffer;
    new_snd->loadFromFile(filename);
    loaded_sounds[filename] = new_snd;
  }
}

void ResourceManager::load_sound(ResourceSound rsound)
{
  load_sound(SOUND_PATHS[rsound]);
}

// Texture freeing
void ResourceManager::free_texture(std::string filename)
{
  if (texture_loaded(filename))
  {
    delete loaded_textures[filename];
    loaded_textures[filename] = NULL;
    loaded_textures.erase(filename);
  }
}

void ResourceManager::free_texture(ResourceImage rimage)
{
  free_texture(IMAGE_PATHS[rimage]);
}

// Sound freeing
void ResourceManager::free_sound(std::string filename)
{
  if (sound_loaded(filename))
  {
    delete loaded_sounds[filename];
    loaded_sounds[filename] = NULL;
    loaded_sounds.erase(filename);
  }
}

void ResourceManager::free_sound(ResourceSound rsound)
{
  free_sound(IMAGE_PATHS[rsound]);
}

// Checking if textue is loaded

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

// Checking if sound is loaded

bool ResourceManager::sound_loaded(std::string filename)
{
  if (loaded_sounds.find(filename) == loaded_sounds.end())
    return false;
  else
    return true;
}

bool ResourceManager::sound_loaded(ResourceSound rsound)
{
  return sound_loaded(SOUND_PATHS[rsound]);
}

// Accessing textures

sf::Texture* ResourceManager::get_texture(std::string filename)
{
  load_texture(filename);
  return loaded_textures[filename];
}

sf::Texture* ResourceManager::get_texture(ResourceImage rimage)
{
  return get_texture(IMAGE_PATHS[rimage]);
}

// Accessing sounds

sf::SoundBuffer* ResourceManager::get_sound(std::string filename)
{
  load_sound(filename);
  return loaded_sounds[filename];
}

sf::SoundBuffer* ResourceManager::get_sound(ResourceSound rsound)
{
  return get_sound(SOUND_PATHS[rsound]);
}

// Playing sounds
void ResourceManager::play_sound(std::string filename)
{
  // Clean the audio if we have to
  if (count_active_audio() >= 256)
    clean_audio();

  // If there's room for another sound, play it
  if (count_active_audio() < 256)
  {
    sf::SoundBuffer *buf = get_sound(filename);
    sf::Sound *sound = new sf::Sound;
    sound->setBuffer(*buf);
    active_sounds.push_back(sound);
    sound->play();
  }
}

void ResourceManager::play_sound(ResourceSound rsound)
{
  play_sound(SOUND_PATHS[rsound]);
}

// Playing music
void ResourceManager::play_music(std::string filename)
{
  // Clean the audio if we have to
  if (count_active_audio() >= 256)
    clean_audio();

  // If there's room for another sound, play it
  if (count_active_audio() < 256)
  {
    sf::Music *music = new sf::Music;
    active_music.push_back(music);
    if (!music->openFromFile(filename))
    {
      std::cerr << "Error opening " << filename << "\n";
      exit(1);
    }
    music->play();
  }
}

void ResourceManager::play_music(ResourceMusic rmusic)
{
  play_music(MUSIC_PATHS[rmusic]);
}

void ResourceManager::clean_audio()
{
  printf("Cleaning audio\n");
  // Erase stopped sounds
  std::vector<sf::Sound*>::iterator new_sound_end;
  new_sound_end = remove_if(active_sounds.begin(), active_sounds.end(), sound_is_stopped);

  // Delete the sounds
  for (std::vector<sf::Sound*>::iterator it = new_sound_end; it != active_sounds.end();
       it++)
  {
    delete (*it);
  }

  // Remove the sounds from the vector
  active_sounds.erase(new_sound_end, active_sounds.end());

  // Erase stopped music
  std::vector<sf::Music*>::iterator new_music_end;
  new_music_end = remove_if(active_music.begin(), active_music.end(), music_is_stopped);

  // Delete the sounds
  for (std::vector<sf::Music*>::iterator it = new_music_end; it != active_music.end();
       it++)
  {
    delete (*it);
  }

  // Remove the music from the vector
  active_music.erase(new_music_end, active_music.end());
}

unsigned int ResourceManager::count_active_audio()
{
  return ( active_sounds.size() + active_music.size() );
}


