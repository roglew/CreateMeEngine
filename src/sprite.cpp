#include "sprite.h"
#include <SFML/Graphics.hpp>

Sprite::~Sprite()
{
	delete sprite;
}

sf::Sprite* Sprite::get_sfml_sprite()
{
	return sprite;
}

