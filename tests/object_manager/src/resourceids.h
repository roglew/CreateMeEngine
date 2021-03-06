/*
Resources file that maps names to each file in the resources file.
Sprites are mapped to consts based on their path in the resource file. i.e.
images/path/to/file.jpg -> IMG_PATH_TO_FILE
*/


#ifndef __RESOURCE_IDS__
#define __RESOURCE_IDS__

#include <string>

////////// Images //////////
enum ResourceImage: unsigned int
{
 IMG_COOKIEMONSTER,
 IMG_SUBDIR1_SUBDIR2_SUBDIRIMAGE,
 IMG_TESTIMAGE,

 IMG_COUNT
};

std::string image_paths[] = { 
 "resources/images/cookiemonster.png",
 "resources/images/subdir1/subdir2/subdirimage.png",
 "resources/images/testimage.png"
};
////////// Sounds //////////
enum ResourceSound: unsigned int
{

 SND_COUNT
};

std::string sound_paths[] = {
};

#endif
