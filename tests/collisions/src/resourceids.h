/*
Resources file that maps names to each file in the resources file.
Sprites are mapped to consts based on their path in the resource file. i.e.
images/path/to/file.jpg -> IMG_PATH_TO_FILE
*/


#ifndef __RESOURCE_IDS__

#include <string>
#include <engine.h>

#define __RESOURCE_IDS__

#ifndef __COLL_ENUM__
#define __COLL_ENUM__
enum COLLISION_TYPE : int // This is an int to allow for predefining
{
  COLLISION_NONE,
  COLLISION_BOUNDING_BOX,

  COLLISION_COUNT
};
#endif

////////// Images //////////
enum ResourceImage: unsigned int
{
 IMG_CROSS,
 IMG_SUBDIR1_SUBDIR2_SUBDIRIMAGE,
 IMG_TESTIMAGE,
 IMG_COOKIEMONSTER,

 IMG_COUNT
};

std::string image_paths[] = { 
 "resources/images/cross.png",
 "resources/images/subdir1/subdir2/subdirimage.png",
 "resources/images/testimage.png",
 "resources/images/cookiemonster.png"
};

////////// ANIMATIONS //////////
enum ResourceAnimation: unsigned int
{
 ANIM_CROSS_SPIN,
 ANIM_CROSS_TATER,
 ANIM_COOKIEMONSTER_STILL,

 ANIM_COUNT
};

AnimationStripConfig predefined_animations[] = {
  {IMG_CROSS, 0, 0, 32, 32, 0, 0, 4, 4},
  {IMG_CROSS, 0, 0, 32, 32, 0, 0, 2, 2},
  {IMG_COOKIEMONSTER, 0, 0, 250, 224, 0, 0, 1, 1}
};

int predefined_collision_data[] = {
  // ANIM_CROSS_SPIN
  COLLISION_BOUNDING_BOX, 0, 0, 32, 16,
  COLLISION_BOUNDING_BOX, 0, 0, 16, 32,
  COLLISION_BOUNDING_BOX, 0, 0, 14, 16,
  COLLISION_BOUNDING_BOX, 0, 0, 16, 40,
  // ANIM_CROSS_TATER
  COLLISION_BOUNDING_BOX, 0, 0, 14, 12
};

int predefined_collision_data_loc[][2] = {
  // ANIM_CROSS_SPIN
  {0, 10},
  {10, 10},
  {0, 10},
  {10, 10},
  // ANIM_CROSS_TATER
  {0, 0},
  {20, 5}
};

int predefined_collision_data_frame[] = {
  0,
  4
};

////////// Sounds //////////
enum ResourceSound: unsigned int
{

 SND_COUNT
};

std::string sound_paths[] = {
};


#endif
