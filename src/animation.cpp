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
    this->frames[i] = NULL; // Null the deleted value
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
    exit(0);
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

        // Update the sprite's texture
        new_sprite->set_image(settings->image, section);
        new_sprite->update_texture();

        // Check if it has a collision
        if (ANIMATION_HAS_COLLISION[settings->image])
        {
          // Get where in the data loc array we start
          int stored_frame_data_loc = PREDEFINED_COLLISION_DATA_FRAME[settings->image];

          // Remember, the frame_data_loc stores the index+1 and a 0 means we generate
          // the bounding box ourselves
          if (stored_data_loc > 0)
          {
            //// Add the data for each frame
            unsigned int frame_data_loc = stored_frame_data_loc-1; // The REAL start index
            for (int data_loc_pos = 0; data_loc_pos < frame_count; data_loc_pos++)
            {
              // Get where in the data array this frame is
              // We start getting the data_loc from frame_data_loc and increment by 1
              // for each frame. Data loc is in the form {pos, len}
              unsigned int pos = PREDEFINED_COLLISION_DATA_LOC[frame_data_loc +
                                                               data_loc_pos][0];
              unsigned int len = PREDEFINED_COLLISION_DATA_LOC[frame_data_loc +
                                                               data_loc_pos][1];

              // Every time we read data, we have to increment our position by 1
              int data_pos = pos;

              // Iterate until we've covered more positions than our length
              while (data_pos - pos < len)
              {
                // Loop MUST start with data_pos at the start on a collision ID

                // Get the type ID and increment the data_pos location
                CollisionType type = static_cast<CollisionType>(
                  PREDEFINED_COLLISION_DATA[data_pos++]); // Note the ++

                switch (type)
                {
                  case BOUNDING_BOX:
                    int x, y, w, h;
                    // Store the data and increment the position
                    x = PREDEFINED_COLLISION_DATA[data_pos++];
                    y = PREDEFINED_COLLISION_DATA[data_pos++];
                    w = PREDEFINED_COLLISION_DATA[data_pos++];
                    h = PREDEFINED_COLLISION_DATA[data_pos++];

                    // Append the bounding box to our sprite
                    new_sprite->collision.bounding_boxes.push_back(
                      BoundingBox(x, y, w, h) );
                    break;

                  default:
                    std::cerr << "Unknown collision type " << type << "\n";
                    exit(0);
                    break;
                }
              }
            }
          }
          else
          {
            // Make a bounding box that covers the entire image
            new_sprite->collision.bounding_boxes.push_back(
              BoundingBox(0, 0, section.w, section.h));
          }
        }
        
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
