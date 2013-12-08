#include "animation.h"
#include "sprite.h"
#include "ids.h"
#include <vector>
#include <iostream>

Animation::Animation()
{
  // Do nothing
}

Animation::~Animation()
{
  // Clean up sprites contained in the animation
  for (unsigned int i = 0; i < frames.size(); i++)
  {
    delete this->frames[i];
  }
}

void Animation::append_frame(Sprite *sprite)
{
  this->frames.push_back(sprite);
}

void Animation::insert_frame(int animation, Sprite* sprite, int n)
{
  if (n < 0)
    this->frames.push_front(sprite);
  else if (n >= this->frames.size())
    this->frames.push_back(sprite);
  else
    this->frames.insert(this->frames.begin() + n, sprite);
}

void Animation::generate_from_strip(ResourceImage image, AnimationStripConfig *settings)
{
  int frame_count, frames_per_row;
  if (settings->count <= 0 || settings->frames_per_row <= 0)
  {
    // DOES NOTHING
    std::cerr << "Calculating frames for entire strip not yet implemented\n";
  }
  else
  {
    frame_count    = settings->count;
    frames_per_row = settings->frames_per_row;
  }

  int rowcount, frames_added;
  rowcount = ( frame_count/frames_per_row ) + 1;
  frames_added = 0;

  for (int row = 0; row <= rowcount; row++)
  {
    for (int col = 0; col < frames_per_row; col++)
    {
      if (frames_added < frame_count)
      {
        Sprite* new_sprite = new Sprite;
        Square section;

        // Calculate the section
        section.x = start_x + col * (settings->w + settings->hsep);
        section.y = start_y + row * (settings->h + settings->vsep);
        section.w = settings->w;
        section.h = settings->h;

        // Set the sprite's info
        new_sprite->set_image(image, &section);

        // Add the frame
        this->append_frame(new_sprite);
      }
    }
  }
}

SpriteAnimation::Sprite* get_frame(int n)
{
  return this->frames[n];
}
