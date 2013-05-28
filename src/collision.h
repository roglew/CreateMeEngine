#ifndef __COLLISION_H__
#define __COLLISION_H__

#include <vector>
#include <string>

enum COLLISION_TYPE {
	COLLISION_BOUNDING_BOX,

	COLLISION_COUNT
};

struct BoundingBox;
struct Collision;

class CollisionException{};

bool collides(const Collision& col1, const Collision& col2);
bool collides(const BoundingBox& box1, const BoundingBox& box2);
bool collides(const std::vector<BoundingBox>& boxes1,
              const std::vector<BoundingBox>& boxes2);

#endif

