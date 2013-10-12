#include <iostream>
#include <cassert>
#include "../src/collision.h"

BoundingBox create_box(int x, int y, int w, int h)
{
	BoundingBox ret;
	ret.x = x;
	ret.y = y;
	ret.w = w;
	ret.h = h;
	return ret;
}

bool test_boxes(const BoundingBox& box1, const BoundingBox& box2)
{
	std::cout << "----------\n";
	std::cout << "Box 1: (" << box1.x << ", " << box1.y << ")"
	                 << "[" << box1.w << ", " << box1.h << "]\n";
	std::cout << "Box 2: (" << box2.x << ", " << box2.y << ")"
	                 << "[" << box2.w << ", " << box2.h << "]\n";
	std::cout << "Do they collide: ";
	if ( collides(box1, box2) )
	{
		std::cout << "Yes\n";
		return true;
	}
	else
	{
		std::cout << "No\n";
		return false;
	}
}

void assert_boxes_not(int x1, int y1, int w1, int h1,
                      int x2, int y2, int w2, int h2)
{
	BoundingBox box1, box2;
	box1 = create_box(x1, y1, w1, h1);
	box2 = create_box(x2, y2, w2, h2);
	assert(!test_boxes(box1, box2));
}

void assert_boxes(int x1, int y1, int w1, int h1,
                  int x2, int y2, int w2, int h2)
{
	BoundingBox box1, box2;
	box1 = create_box(x1, y1, w1, h1);
	box2 = create_box(x2, y2, w2, h2);
	assert(test_boxes(box1, box2));
}


int main(int argc, const char *argv[])
{
	// Two bounding boxes that shouldn't collide
	assert_boxes_not(0, 0, 3, 3,
	                 4, 4, 3, 3);

	// Boarder on each side
	assert_boxes_not(0, 0, 3, 3,
	                 3, 0, 3, 3);

	assert_boxes_not(0, 0, 3, 3,
	                 0, 3, 3, 3);

	assert_boxes_not(0, 0, 3, 3,
	                 -3, 0, 3, 3);

	assert_boxes_not(0, 0, 3, 3,
	                 0, -3, 3, 3);

	// Boxes that should collide
	assert_boxes(0, 0, 3, 3,
	             2, 2, 3, 3);

	return 0;
}
