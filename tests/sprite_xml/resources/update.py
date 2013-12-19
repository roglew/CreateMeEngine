#!/usr/bin/python

import os
import xml.etree.ElementTree as ET

### SETTINGS ###

# EXTS variables can be [] to include all extensions

IMAGE_PREFIX = 'IMG'
IMAGE_SUBDIR = 'images'
IMAGE_EXTS = ['png', 'bmp', 'jpg', 'tiff']
IMAGE_ENUM = 'ResourceImage'
IMAGE_PATHVAR = 'image_paths'

SOUND_PREFIX = 'SND'
SOUND_SUBDIR = 'sounds'
SOUND_EXTS = ['wav', 'mp3']
SOUND_ENUM = 'ResourceSound'
SOUND_PATHVAR = 'sound_paths'

ANIM_PREFIX = 'ANIM'
ANIM_ENUM = 'ResourceAnimation'
ANIM_STRUCTVAR = 'predefined_animations'

### END SETTINGS ###

# Global vars
WORKING_DIR = os.path.dirname(os.path.realpath(__file__))

#### Functions


def walk_directory(dir_name, exts=[]):
  # Searches the given directory and returns a list of files that have one of the
  # given extensions (no leading .)

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
          file_list.append('resources/%s/%s' % (cur_dir, file))
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
  for part in parts[2:-1]:
    name += '%s_' % part.upper()

  # Add the file name part to the name
  name += os.path.splitext(parts[-1])[0].upper()

  return name


def get_definition_string(resources, prefix, name, enum_name, list_name):
  # Returns the c++ code that defines an enum and a corresponding array of file
  # paths
  # resources - list of resource paths
  # prefix - prefix for the enum (ie IMG)
  # name - The name to use to describe the definition in the header file
  # enum_name - name to give the enum
  # list_name - name to give the list of resource paths
  def_string = "////////// %s //////////\n" % name

  # Create a dict that pairs resource ids with paths
  pairs = {}
  for resource in resources:
    res_name = get_resource_name(prefix, resource)
    pairs[res_name] = resource

  # Define the enum
  def_string += 'enum %s: unsigned int\n{\n' % enum_name
  for res_name in pairs:
    def_string += ' %s,\n' % res_name
  def_string += '\n %s_COUNT\n' % prefix
  def_string += '};\n\n'

  # Map each enum to a string
  def_string += 'std::string %s[] = { \n' % list_name
  for res_name in pairs:
    def_string += ' "%s",\n' % pairs[res_name]
  # remove the last comma
  def_string = def_string[:-2]

  def_string += '\n};\n'

  # return the string
  return def_string

def get_animation_definition_string(animations, prefix, enum_name, list_name):
  # Returns the c++ code that defines an enum and a corresponding array of
  # animations
  # anumations - list of the paths to the animation xml files
  # prefix - prefix for the enum (ie ANIM)
  # name - The name to use to describe the definition in the header file
  # enum_name - name to give the enum
  # list_name - name to give the list of animation classes
  def_string = "////////// ANIMATIONS //////////\n"

  # Create a dict that pairs animation ids to the xml filepath
  pairs = {}
  for animation in animations:
    anim_name = get_resource_name(prefix, animation)
    pairs[anim_name] = animation

  # Create the enum
  def_string += "enum %s: unsigned int\n{\n" % enum_name
  for anim_name in pairs:
    def_string += ' %s,\n' % anim_name
  def_string += '\n %s_COUNT' % prefix
  def_string += '};\n\n'

  # Create an array with the correct size. Animations get loaded on-demand
  def_string += 'AnimationConfig %s[] = {\n' % list_name
  for anim_name in pairs:
    # WORK HERE
    def_string += '  {%d, %d, %d, %d, %d, %d, %d, %d},\n' % (start_x, start_y,
                                                             w, h, hsep, vsep,
                                                             frames_per_row,
                                                             frame_count)
    # done

  # remove the last comma
  def_string = def_string[:-2]

  def_string += '\n};\n'

#### Script

# Walk the image and sound directory
print 'Searching images...'
images = walk_directory(IMAGE_SUBDIR, IMAGE_EXTS)

print 'Searching animations...'
animations = walk_directory(IMAGE_SUBDIR, ["xml"])

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
#include <engine>

"""
)

image_write = get_definition_string(images, IMAGE_PREFIX, 'Images',
                                    IMAGE_ENUM, IMAGE_PATHVAR)

animation_write = get_animation_definition_string(animations, ANIM_PREFIX,
                                                  ANIM_ENUM, ANIM_STRUCTVAR)

sound_write = get_definition_string(sounds, SOUND_PREFIX, 'Sounds',
                                    SOUND_ENUM, SOUND_PATHVAR)
include_file.write(image_write)
include_file.write(animation_write)
include_file.write(sound_write)
include_file.write('\n#endif\n')
