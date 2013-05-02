#ifndef __COLLISION_H__
#define __COLLISION_H__

#include <SFML/System.hpp>

struct bounding_box;

bool collides(bounding_box& box1, bounding_box& box2);

#endif

