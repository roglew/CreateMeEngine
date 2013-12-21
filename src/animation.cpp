#include "animation.h"
#include "resourcemanager.h"
#include "sprite.h"
#include "ids.h"
#include <vector>
#include <iostream>
#include <stdio.h>

extern AnimationStripConfig predefined_animations[];

void default_animation_strip_config(AnimationStripConfig *config)
{
  config->start_x        = 0;
  config->start_y        = 0;
  config->w              = 32;
  config->h              = 32;
  config->hsep           = 0;
  config->vsep           = 0;
  config->frames_per_row = 1;
  config->frame_count    = 1;
}

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

void Animation::generate_from_id(ResourceAnimation animation_id)
{
  generate_from_strip(&predefined_animations[animation_id]);
}

void Animation::generate_from_strip(AnimationStripConfig *settings)
{
  int frame_count, frames_per_row;
  if (settings->frame_count <= 0 || settings->frames_per_row <= 0)
  {
    // DOES NOTHING
    std::cerr << "Calculating frames for entire strip not yet implemented\n";
  }
  else
  {
    frame_count    = settings->frame_count;
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
        new_sprite->set_image(settings->image, section);
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
