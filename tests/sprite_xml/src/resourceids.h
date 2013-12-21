/*
Resources file that maps names to each file in the resources file.
Sprites are mapped to consts based on their path in the resource file. i.e.
images/path/to/file.jpg -> IMG_PATH_TO_FILE
*/


#ifndef __RESOURCE_IDS__

#include <string>
#include <engine.h>

#define __RESOURCE_IDS__

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

 ANIM_COUNT};

AnimationStripConfig predefined_animations[] = {
  {IMG_CROSS, 0, 0, 32, 32, 0, 0, 4, 4},
  {IMG_CROSS, 0, 0, 32, 32, 0, 0, 2, 2}
};

////////// Sounds //////////
enum ResourceSound: unsigned int
{

 SND_COUNT
};

std::string sound_paths[] = {
};


#endif
