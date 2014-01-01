#ifndef __COLLISION_H__
#define __COLLISION_H__

#include <vector>
#include <string>

#ifndef __COLL_ENUM__
#define __COLL_ENUM__
enum CollisionType : int // This is an int to allow for predefining
{
  COLLISION_NONE,
  COLLISION_BOUNDING_BOX,

  COLLISION_COUNT
};
#endif

// Struct defenitions
// THEY ALL ONLY HAVE INTS FOR DATA
// This allows us to predefine collisions in an array of ints in resources.h

struct BoundingBox
{
  // A basic box with a position and a size
  int x, y;
  int w, h;
};
// A box that contains an int x, y, w, h that can be used to detect collisions

struct Collision{
  int x, y;
  std::vector< BoundingBox > bounding_boxes;
};
// A collision object that contains lists of bounding boxes (possibly other things in
// the future)

class CollisionException{};
// An exception class

// Collision checks

bool collides(Collision& col1, Collision& col2);
// MODIFIES: Iterates through values of col1 and col2
// EFFECTS: Checks if any 2 generic collisions collide

bool collides(const BoundingBox& box1, int x1, int y1,
              const BoundingBox& box2, int x2, int y2);
// EFFECTS: Checks if 2 bounding boxes at the given positions collide

bool collides(std::vector<BoundingBox>& boxes1, int x1, int y1,
              std::vector<BoundingBox>& boxes2, int x2, int y2);
// MODIFIES: Iterates over the vectors
// EFFECTS: Checks if any bounding boxes at the given position in the first list
//          collide with any boxes at the second position in the second list

#endif

