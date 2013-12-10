#include "animation.h"
#include "resourcemanager.h"
#include "sprite.h"
#include <vector>
#include <iostream>
#include <stdio.h>

#ifndef __RESOURCE_IDS__
enum ResourceImage: unsigned int;
enum ResourceSound: unsigned int;
#endif

Animation::Animation(ResourceManager *res)
{
  this->resource_manager = res;
}

Animation::~Animation()
{
  // Clean up sprites contained in the animation
  for (unsigned int i = 0; i < frames.size(); i++)
  {
    Sprite *frame;
    frame = this->frames[i];
    delete frame;
  }
}

void Animation::append_frame(Sprite *sprite)
{
  this->frames.push_back(sprite);
}

void Animation::insert_frame(int animation, Sprite* sprite, int n)
{
  if (n < 0)
    this->frames.insert(this->frames.begin(), sprite);
  else if (n >= int(this->frames.size()))
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
        Sprite* new_sprite = new Sprite(this->resource_manager);
        Square section;

        // Calculate the section
        section.x = settings->start_x + col * (settings->w + settings->hsep);
        section.y = settings->start_y + row * (settings->h + settings->vsep);
        section.w = settings->w;
        section.h = settings->h;

        // Set the sprite's info
        new_sprite->set_image(image, section);
        new_sprite->update_texture();

        // Add the frame
        this->append_frame(new_sprite);
        frames_added++;
      }
    }
  }

}

int Animation::size()
{
  return this->frames.size();
}

Sprite* Animation::get_frame(int n)
{
  if (n > 0)
    return this->frames[n];
  else
    return this->frames[0];
}
