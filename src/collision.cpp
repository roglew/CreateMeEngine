#include "collision.h"
#include <vector>

bool collides(const BoundingBox& box1, const BoundingBox& box2)
{
  int box1_right  = box1.x + box1.w;
  int box1_bottom = box1.y + box1.h;
  int box2_right  = box2.x + box2.w;
  int box2_bottom = box2.y + box2.h;

  if (box1_bottom <= box2.y) return(0);
  if (box1.y >= box2_bottom) return(0);
  if (box1_right <= box2.x) return(0);
  if (box1.x >= box2_right) return (0);
  return 1;
}

bool collides(std::vector<BoundingBox>& boxes1,
              std::vector<BoundingBox>& boxes2)
{
  std::vector<BoundingBox>::iterator it1;
  std::vector<BoundingBox>::iterator it2;
  for (it1 = boxes1.begin(); it1 != boxes1.end(); it1++)
  {
    for (it2 = boxes2.begin(); it2 != boxes2.end(); it2++)
    {
      if ( collides(*it1, *it2) )
        return true;
    }
  }

  return false;
}
