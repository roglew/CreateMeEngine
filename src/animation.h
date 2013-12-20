#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "sprite.h"
#include "ids.h"
#include "resourcemanager.h"
#include <vector>

struct AnimationStripConfig
{
  ResourceImage image;
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
    frames_per_row = 1;
    frame_count    = 1;
  }
};

class Animation
{
  protected:
    std::vector<Sprite*> frames;
    ResourceManager *resource_manager;

  public:
    Animation(ResourceManager *resource_manager);
    ~Animation();
    // Constructor/destructors
    
    void append_frame(Sprite *sprite);
    // MODIFIES: This
    // EFFECTS:  Appends the given sprite to the end of the animation

    void insert_frame(int animation, Sprite* sprite, int n);
    // MODIFIES: This
    // EFFECTS:  Inserts a frame into the given animation at the given
    //           position (First frame is 0)

    void generate_from_id(ResourceAnimation animation_id);
    // MODIFIES: This
    // EFFECTS:  Generates an animation from a given animation id

    void generate_from_strip(AnimationStripConfig *settings);
    // MODIFIES: This
    // EFFECTS:  Generates sprites and creates an animation using the given animation
    //           strip settings. If frames_per_row <= 0 or count <= 0, then the entire
    //           image will be split into a grid and all the frames will be used

    int size();
    // EFFECTS: Returns the number of frames in the animation

    Sprite* get_frame(int n);
    // EFFECTS: Returns a pointer to the nth frame
};

#endif
