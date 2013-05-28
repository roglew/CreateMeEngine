#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "collision.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Sprite: public sf::Sprite
{
	private:
		Collision collision;
	
	public:
		// set_collision(const &Collision);
		// MODIFIES: This
		// EFFECTS:  Sets the collision struct of the sprite

		bool collides(Sprite& other_sprite);
		// EFFECTS: Returns whether the two sprites collide
};


#endif

