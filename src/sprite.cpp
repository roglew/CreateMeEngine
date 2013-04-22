#include "sprite.h"
#include <SFML/Graphics.hpp>

Sprite::~Sprite()
{
	delete sprite;
}

