/*
Resources file that maps names to each file in the resources file.
Sprites are mapped to consts based on their path in the resource file. i.e.
images/path/to/file.jpg -> IMG_PATH_TO_FILE
*/


#ifndef __RESOURCE_IDS__
#define __RESOURCE_IDS__

#include <string>

////////// Images //////////
enum ResourceImage
{
 IMG_COOKIEMONSTER,
 IMG_SUBDIR1_SUBDIR2_SUBDIRIMAGE,

 IMG_COUNT
};

std::string image_paths[] = {
 "images/cookiemonster.png",
 "images/subdir1/subdir2/subdirimage.png"
};
////////// Sounds //////////
enum ResourceSound
{

 SND_COUNT
};

std::string sound_paths[] = 
};

#endif