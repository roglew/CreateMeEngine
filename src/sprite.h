#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "collision.h"
#include "resourcemanager.h"
#include "square.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#ifndef __RESOURCE_IDS__
enum ResourceImage: unsigned int;
enum ResourceSound: unsigned int;
#endif

class Sprite: public sf::Sprite
{
  protected:
    ResourceManager *resources;
    std::vector<Collision> collisions;
    ResourceImage image;
    Square image_pos;
    bool is_part, image_defined;
  
  public:
    Sprite(ResourceManager *resource_manager);
    // set_collision(const &Collision);
    // MODIFIES: This
    // EFFECTS:  Sets the collision struct of the sprite

    bool collides(Sprite& other_sprite);
    // EFFECTS: Returns whether the two sprites collide
    
    void set_image(ResourceImage image);
    // MODIFIES: This
    // Sets the image to the entire texture
    
    void set_image(ResourceImage image, Square &position);
    void set_image(ResourceImage image, int x, int y, int w, int h);
    // MODIFIES: This
    // EFFECTS: Sets the image and section to load when load() is called

    void update_texture();
    // MODIFIES: This
    // EFFECTS:  Updates the sfml texture to match the image. Also loads the image if
    //           neccesary
    
    void load();
    // REQUIRES: Image must have been set

};


#endif

