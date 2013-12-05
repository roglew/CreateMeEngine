#include "sprite.h"
#include <vector>

#ifndef __RESOURCE_IDS__
enum ResourceImage: unsigned int;
enum ResourceSound: unsigned int;
#endif

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

    void generate_from_strip(sf::Texture texture, int start_x, int start_y, int w, int h,
                             int hsep, int vsep, int frames_per_row, int count);

    Sprite* get_frame(int n);
    // EFFECTS: Returns a pointer to the nth frame
}
