#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <SFML/Graphics.hpp>
#include <vector>

struct Collision{
	std::vector< sf::Rect<int> > bounding_box;
};

Collision default_collision;

class Sprite{
	private:
		sf::Sprite* sprite;
		Collision collision;
	
	public:
		Sprite();
		// Constructor

		Sprite(sf::Sprite*, const &Collision = default_collision);
		// Constructor that holds a sprite and a collision

		~Sprite();
		// Destructor

		sf::Sprite* get_sfml_sprite();
		// EFFECTS: Returns a pointer to a sfml sprite that corresponds to this
		//          sprite

		set_collision(const &Collision);
		// MODIFIES: This
		// EFFECTS:  Sets the collision struct of the sprite

};

bool collides(const &Sprite, const &Sprite);
// EFFECTS: Returns whether the two sprites collide

#endif

