#ifndef __COLLISION_H__
#define __COLLISION_H__

#include <vector>
#include <string>

enum COLLISION_TYPE
{
  COLLISION_BOUNDING_BOX,

  COLLISION_COUNT
};

// Struct defenitions

struct BoundingBox
{
  // A basic box with a position and a size
  int x, y;
  int w, h;
};
// A box that contains an int x, y, w, h that can be used to detect collisions

struct Collision{
  COLLISION_TYPE type;
  std::vector< BoundingBox > bounding_boxes;
};
// A collision object that can be many types of collision

class CollisionException{};
// An exception class

// Collision checks

bool collides(Collision& col1, Collision& col2);
// MODIFIES: Iterates through values of col1 and col2
// EFFECTS: Checks if any 2 generic collisions collide

bool collides(const BoundingBox& box1, const BoundingBox& box2);
// EFFECTS: Checks if 2 bounding boxes collide

bool collides(std::vector<BoundingBox>& boxes1,
              std::vector<BoundingBox>& boxes2);
// MODIFIES: Iterates over the vectors
// EFFECTS: Checks if any bounding boxes in the first list collide with any
//          boxes in the second list

#endif

