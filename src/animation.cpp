#include "animation.h"
#include "sprite.h"
#include "ids.h"
#include <vector>

void Animation::append_frame(Sprite *sprite)
{
  // MODIFIES: This
  // EFFECTS:  Appends the given sprite to the end of the animation
  
}

void Animation::insert_frame(int animation, Sprite* sprite, int n)
{
  // MODIFIES: This
  // EFFECTS:  Inserts a frame into the given animation at the given
  //           position (First frame is 0)
  
}

void Animation::generate_from_strip(ResourceImage image, AnimationStripConfig settings)
{
  // MODIFIES: This
  // EFFECTS:  Generates sprites and creates an animation using the given animation
  //           strip settings
  
}

SpriteAnimation::* get_frame(int n)
{
  // EFFECTS: Returns a pointer to the nth frame
  
}
