#include "sprite.h"
#include <vector>

#ifndef __RESOURCE_IDS__
enum ResourceImage: unsigned int;
enum ResourceSound: unsigned int;
#endif

struct AnimationStripConfig
{
  int start_x;
  int start_y;
  int w;
  int h;
  int hsep;
  int vsep;
  int frames_per_row;
  int count;

  // Default Values
  AnimationStripConfig()
  {
    start_x        = 0;
    start_y        = 0;
    w              = 32;
    h              = 32;
    hsep           = 0;
    vsep           = 0;
    frames_per_row = -1;
    count          = 1;
  }
};

Class Animation
{
  protected:
    std::vector<*Sprite> frames;

  public:
    void append_frame(Sprite *sprite);
    // MODIFIES: This
    // EFFECTS:  Appends the given sprite to the end of the animation

    void insert_frame(int animation, Sprite* sprite, int n);
    // MODIFIES: This
    // EFFECTS:  Inserts a frame into the given animation at the given
    //           position (First frame is 0)

    void generate_from_strip(ResourceImage image, AnimationStripConfig settings);
    // MODIFIES: This
    // EFFECTS:  Makes the animation from an animation strip

    Sprite* get_frame(int n);
    // EFFECTS: Returns a pointer to the nth frame
}
