#include "collision.h"

// Struct defenitions
struct bounding_box
{
	// A basic box with a position and a size
	float x, y;
	float w, h;
};

bool collides(bounding_box& box1, bounding_box& box2)
{
	float box1_right  = box1.x + box1.w;
	float box1_bottom = box1.y + box1.h;
	float box2_right  = box2.x + box2.w;
	float box2_bottom = box2.y + box2.h;

	if (box1_bottom < box2.y) return(0);
	if (box1.y > box2_bottom) return(0);
	if (box1_right < box2.x) return(0);
	if (box1.x > box2_right) return (0);

	return(1);
}

