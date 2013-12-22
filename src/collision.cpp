#include "collision.h"
#include <vector>

bool collides(Collision& col1, Collision& col2)
{
  if (collides(col1.bounding_boxes, col1.x, col1.y,
               col2.bounding_boxes, col2.x, col2.y))
    return true;

  // As we implement more collisions, check each combination with the appropriate function
  // here

  return false;
}

bool collides(const BoundingBox& box1, int x1, int y1,
              const BoundingBox& box2, int x2, int y2)
{
  int box1_right  = (box1.x + x1) + box1.w;
  int box1_bottom = (box1.y + y1) + box1.h;
  int box2_right  = (box2.x + x2) + box2.w;
  int box2_bottom = (box2.y + y2) + box2.h;

  if (box1_bottom <= (box2.y + y2)) return(0);
  if ((box1.y + y1) >= box2_bottom) return(0);
  if (box1_right <= (box2.x + x2)) return(0);
  if ((box1.x + x1) >= box2_right) return (0);
  return 1;
}

bool collides(std::vector<BoundingBox>& boxes1, int x1, int y1,
              std::vector<BoundingBox>& boxes2, int x2, int y2)
{
  std::vector<BoundingBox>::iterator it1;
  std::vector<BoundingBox>::iterator it2;
  for (it1 = boxes1.begin(); it1 != boxes1.end(); it1++)
  {
    for (it2 = boxes2.begin(); it2 != boxes2.end(); it2++)
    {
      if ( collides(*it1, x1, y1, *it2, x2, y2) )
        return true;
    }
  }

  return false;
}
