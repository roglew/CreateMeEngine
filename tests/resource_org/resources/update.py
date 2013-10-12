#!/usr/bin/python

import os

### SETTINGS ###

# EXTS variables can be [] to include all extensions

IMAGE_SUBDIR = 'images'
IMAGE_EXTS = ['png', 'bmp', 'jpg', 'tiff']
IMAGE_ENUM = 'ResourceImage'
IMAGE_PATHVAR = 'image_paths'

SOUND_SUBDIR = 'sounds'
SOUND_EXTS = ['wav', 'mp3']
SOUND_ENUM = 'ResourceSound'
SOUND_PATHVAR = 'sound_paths'
### END SETTINGS ###

# Global vars
WORKING_DIR = os.path.dirname(os.path.realpath(__file__))

#### Functions


def walk_directory(dir_name, exts=[]):
  walk_dir = '%s/%s' % (WORKING_DIR, dir_name)
  file_list = []
  if exts:
    for root, sub_folders, files in os.walk(walk_dir):
      # Get dir relative to the script
      cur_dir = root.replace('%s/' % WORKING_DIR, '')

      # Iterate through the files in the current dir
      for file in files:
        # Get the extension without the dot
        file_ext = os.path.splitext(file)[1][1:]

        # Only append if it's in the set
        if file_ext in exts:
          file_list.append('%s/%s' % (cur_dir, file))
          print '-> %s' % file
  else:
    # No extensions are given
    for root, sub_folders, files in os.walk(walk_dir):
      cur_dir = root.replace('%s/' % WORKING_DIR, '')
      for file in files:
        file_list.append('%s/%s' % (cur_dir, file))

  return file_list


def get_resource_name(prefix, path):
  # Converts type/path/to/object.ext to PFX_PATH_TO_OBJECT

  # Put in the prefix
  name = '%s_' % prefix.upper()
  parts = path.split('/')  # split the path
  # Add each part of the path to the name except the last one
  for part in parts[1:-1]:
    name += '%s_' % part.upper()

  # Add the file name part to the name
  name += os.path.splitext(parts[-1])[0].upper()

  return name


def get_definition_string(resources, prefix, name, enum_name, list_name):
  def_string = "////////// %s //////////\n" % name
  pairs = {}
  for resource in resources:
    res_name = get_resource_name(prefix, resource)
    pairs[res_name] = resource

  # Define the enum
  def_string += 'enum %s\n{\n' % enum_name
  for res_name in pairs:
    def_string += ' %s,\n' % res_name
  def_string += '\n %s_COUNT\n' % prefix
  def_string += '};\n\n'

  # Map each enum to a string
  def_string += 'std::string %s[] = {\n' % list_name
  for res_name in pairs:
    def_string += ' "%s",\n' % pairs[res_name]
  # remove the last comma
  def_string = def_string[:-2]

  def_string += '\n};\n'

  # return the string
  return def_string


#### Script

# Walk the image and sound directory
print 'Searching images...'
images = walk_directory(IMAGE_SUBDIR, IMAGE_EXTS)

print 'Searching sounds...'
sounds = walk_directory(SOUND_SUBDIR, SOUND_EXTS)

include_file = open('%s/../src/resourceids.h' % WORKING_DIR, 'w')

header =\
"""/*
Resources file that maps names to each file in the resources file.
Sprites are mapped to consts based on their path in the resource file. i.e.
images/path/to/file.jpg -> IMG_PATH_TO_FILE
*/


"""

include_file.write(header)

# includes
include_file.write(
"""#ifndef __RESOURCE_IDS__
#define __RESOURCE_IDS__

#include <string>

"""
)

image_write = get_definition_string(images, 'IMG', 'Images',
                                    IMAGE_ENUM, IMAGE_PATHVAR)
sound_write = get_definition_string(sounds, 'SND', 'Sounds',
                                    SOUND_ENUM, SOUND_PATHVAR)
include_file.write(image_write)
include_file.write(sound_write)
include_file.write('\n#endif')
