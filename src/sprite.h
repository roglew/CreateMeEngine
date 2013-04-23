#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <SFML/Graphics.hpp>
#include <vector>

struct Collision{
	std::vector< sf::Rect<int> > bounding_box;
};

class Sprite: public sf::Sprite
{
	private:
		Collision collision;
	
	public:
		// set_collision(const &Collision);
		// MODIFIES: This
		// EFFECTS:  Sets the collision struct of the sprite

};

//bool collides(const &Sprite, const &Sprite);
// EFFECTS: Returns whether the two sprites collide

#endif

