#include "sprite.h"
#include "collision.h"
#include <SFML/Graphics.hpp>
#include <vector>

bool Sprite::collides(Sprite& other_sprite)
{
  /*
	// Just bounding boxes for now
	const std::vector< sf::Rect<int> > *bboxes = &collision.bounding_box;

	// Store iterator data
	std::vector< sf::Rect<int> >::iterator it1;
	std::vector< sf::Rect<int> >::iterator itbegin;
	std::vector< sf::Rect<int> >::iterator itend;
	itbegin = collision.bounding_box.begin();
	itend = collision.bounding_box.end();

	// Loop through our bounding boxes
	for (it1 = itbegin; it1 != itend; it1++)
	{
		// Other sprite's bounding box data
		std::vector< sf::Rect<int> >::iterator it2;
		std::vector< sf::Rect<int> >::iterator itbegin2;
		std::vector< sf::Rect<int> >::iterator itend2;
		itbegin2 = other_sprite.collision.bounding_box.begin();
		itend2 = other_sprite.collision.bounding_box.end();

		// Iterate through the other sprite's bounding boxes
		for (it2 = itbegin2; it2 != itend2; it2++)
		{

		}
	}
  */
}

