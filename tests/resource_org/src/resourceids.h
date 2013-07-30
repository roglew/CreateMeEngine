/*
Resources file that maps names to each file in the resources file.
Sprites are mapped to consts based on their path in the resource file. i.e.
images/path/to/file.jpg -> SPR_PATH_TO_FILE
*/


#include <string>

////////// Images //////////
enum ResourceImage
{
	IMG_IMAGES_SUBDIR1_SUBDIR2_SUBDIRIMAGE,
	IMG_IMAGES_TESTIMAGE,

	IMG_COUNT
};

std::string image_paths[] = {
	"images/subdir1/subdir2/subdirimage.png",
	"images/testimage.png"
};
////////// Sounds //////////
enum ResourceSound
{
	SND_IMAGES_TESTIMAGE,
	SND_IMAGES_SUBDIR1_SUBDIR2_SUBDIRIMAGE,

	SND_COUNT
};

std::string sound_paths[] = {
	"images/testimage.png",
	"images/subdir1/subdir2/subdirimage.png"
};
