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
ANIM_STRUCTVAR = 'PREDEFINED_ANIMATIONS' # Should be hardcoded

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

  def_string += '\n};\n\n'

  # return the string
  return def_string

def get_animation_definition_string(animation_files, anim_prefix, img_prefix,
                                    enum_name, list_name):
  # Returns the c++ code that defines an enum with a corresponding array of
  # animations and an array of collision structs for each animation
  # animation_files - list of the paths to the animation xml files
  # anim_prefix - prefix for the enum (ie ANIM)
  # img_prefix - prefix for image names
  # name - The name to use to describe the definition in the header file
  # enum_name - name to give the enum
  # list_name - name to give the list of animation classes
  def_string = "////////// ANIMATIONS //////////\n" # Header

  # Create dictionary pairing image file NAMES to animation files and
  # animation names
  image_pairs = {}
  anim_name_bases = {}
  for anim_file in animation_files:
    # Since animation files have to have the same name as the image, we can use
    # the normal naming scheme, but use the xml file with the image prefix
    image_name = get_resource_name(img_prefix, anim_file)
    anim_name_bases[image_name] = get_resource_name(anim_prefix, anim_file)
    image_pairs[image_name] = anim_file


  # Create a dictionaries to pair animations to images and one to store
  # animation info
  anim_pairs = {}
  anim_list = []
  # Loop through the animations by name
  for image_name in image_pairs:
    # Get list of animations from xml file

    # Remember, this gets called from the parent directory. This string has the
    # resources/images/etc part in it, which we want. This script can't be called
    # from the directory that the script is in
    xml_file = image_pairs[image_name]
    print "Parsing %s" % xml_file
    xml_tree = ET.parse(xml_file)
    xml_root = xml_tree.getroot()

    # Iterate through the children
    for child in xml_root.findall("animation"):
      # Set default values for animation info
      name           = "untitled"
      res_image      = image_name
      start_x        = 0
      start_y        = 0
      w              = 32
      h              = 32
      hsep           = 0
      vsep           = 0
      frames_per_row = 1
      frame_count    = 1
      collision_data = []

      # Get info from the xml file
      # Only save it if it has a name
      if (child.find("name") is not None):
        name = child.find("name").text
        print "Animation: %s" % name

        if (child.find("xstart") is not None):
          xstart = int(child.find("xstart").text)

        if (child.find("ystart") is not None):
          start_y = int(child.find("ystart").text)

        if (child.find("width") is not None):
          w = int(child.find("width").text)

        if (child.find("height") is not None):
          h = int(child.find("height").text)

        if (child.find("xsep") is not None):
          hsep = int(child.find("xsep").text)

        if (child.find("ysep") is not None):
          vsep = int(child.find("ysep").text)

        if (child.find("framesperrow") is not None):
          frames_per_row = int(child.find("framesperrow").text)

        if (child.find("framecount") is not None):
          frame_count = int(child.find("framecount").text)

        # Only get collision data if child.collide="true"
        collision_data = []
        # This is a list that will contain a list of collision components and
        # which frames each iece is active on
        if ("collides" in child.attrib and child.attrib["collides"] == "true"):
          collides = True
          # Create our list of collision dictionaries
          collroots = child.findall("collision")
          for collroot in collroots:
            # Find out which frames this group is active on

            # Split by commas and strip whitespace around the commas
            active_frames = collroot.find("activeframes").text.split(",")
            for i in active_frames:
              i.strip()

            # Convert the frames to ints
            for i in range(len(active_frames)):
              active_frames[i] = int(active_frames[i])

            # Find bounding boxes
            bounding_boxes = collroot.findall("boundingbox")
            for bounding_box in bounding_boxes:
              add_data = {}
              bb_x = int( bounding_box.attrib["x"] )
              bb_y = int( bounding_box.attrib["y"] )
              bb_w = int( bounding_box.attrib["w"] )
              bb_h = int( bounding_box.attrib["h"] )
              add_data["type"]          = "boundingbox"
              add_data["active_frames"] = active_frames
              add_data["x"]             = bb_x
              add_data["y"]             = bb_y
              add_data["w"]             = bb_w
              add_data["h"]             = bb_h
              collision_data.append(add_data) # add the box to our list
        else:
          collides = False


        # Store the info in the animation list
        new_anim = {}
        new_anim["name"]           = name
        new_anim["res_image"]      = res_image
        new_anim["start_x"]        = start_x
        new_anim["start_y"]        = start_y
        new_anim["w"]              = w
        new_anim["h"]              = h
        new_anim["hsep"]           = hsep
        new_anim["vsep"]           = vsep
        new_anim["frames_per_row"] = frames_per_row
        new_anim["frame_count"]    = frame_count
        new_anim["collides"]       = collides
        new_anim["collision_data"] = collision_data
        anim_list.append(new_anim)

  ##### ENUM #####
  def_string += "enum %s: unsigned int\n{\n" % enum_name
  for animation in anim_list:
    animation["enum_name"] = '%s_%s' % (anim_name_bases[animation["res_image"]],
                                        animation["name"].upper())
    def_string += ' %s,\n' % animation["enum_name"]
  def_string += '\n %s_COUNT' % anim_prefix
  def_string += '\n};\n\n'

  ##### DATA ARRAY #####
  # Create the data array. This is a constant stream of data of all the frames
  # and all the collision pieces
  def_string += 'AnimationStripConfig %s[] = {\n' % list_name
  for animation in anim_list:
    def_string += '  {%s, %d, %d, %d, %d, %d, %d, %d, %d},\n' % \
        ( animation["res_image"], animation["start_x"], animation["start_y"],
          animation["w"], animation["h"], animation["hsep"], animation["vsep"],
          animation["frames_per_row"], animation["frame_count"], )

  def_string = def_string[:-2] # Remove the last comma
  def_string += '\n};\n\n' # Close the definition

  # Print the raw data array
  def_string += 'const unsigned int PREDEFINED_COLLISION_DATA[] = {\n'
  pos = 0
  close = False
  for animation in anim_list:
    if animation["collides"]:
      def_string += '  // %s\n' % animation["enum_name"]
      for collision in animation["collision_data"]:
        if collision["type"] is "boundingbox":
          close = True
          # We store the data location in the collision dict
          collision["data_loc"] = [pos, 5]

          # Add the data to the file
          def_string += "  %s, %d, %d, %d, %d,\n" % \
              ("COLLISION_BOUNDING_BOX", collision["x"], collision["y"],
               collision["w"], collision["h"])

          # Update the current position in the array
          pos += 5
  
  if (close):
    def_string = def_string[:-2] # Remove the last comma and space
  def_string += '\n};\n\n' # Close the definition

  ###### DATA LOC #####
  # Add info about where the collision info is in the array for each frame of
  # each animation
  def_string += 'const int PREDEFINED_COLLISION_DATA_LOC[][2] = {\n'

  # This is an array of frames that tell where in the data array each frame's
  # collision data is
  for animation in anim_list:
    if animation["collides"]:
      def_string += '  // %s\n' % animation["enum_name"]
      for frame in range(animation["frame_count"]):
        pos = -1
        length = 0

        for collision in animation["collision_data"]:
          if frame in collision["active_frames"]:
            if pos == -1:
              pos = collision["data_loc"][0]
              length = 0
            length += collision["data_loc"][1]

        if pos is -1:
          pos = 0
          length = 0
        def_string += "  {%d, %d},\n" % (pos, length)

  if (close):
    def_string = def_string[:-2] # Remove the last comma and space
  def_string += '\n};\n\n' # Close the definition

  ##### DATA_LOC START #####
  # This tells which frame each animation starts at
  def_string +=\
"""// Stores the index+1 of where in the data_loc array each frame is. It
// stores index+1 of the array so that we can use 0 to tell the program to create
// its own bounding box\n"""
  def_string += 'const unsigned int PREDEFINED_COLLISION_DATA_FRAME[] = {\n'

  cur_frame = 0
  for animation in anim_list:
    if (animation['collides']):
      def_string += '  // %s\n' % animation['enum_name']
      if len(animation["collision_data"]) > 0:
        def_string += '  %d,\n\n' % ( cur_frame+1 )
        cur_frame += animation['frame_count']
      else:
        def_string += '  0,\n\n'

  if (close):
    def_string = def_string[:-3] # Remove the last comma and space
  def_string += '\n};\n\n' # Close the definition

  # Create the array saying whether we have collision data for the animation
  def_string += 'const char ANIMATION_HAS_COLLISION[] = {\n'

  ##### HAS_COLLISION #####
  for animation in anim_list:
    def_string += '  // %s\n' % animation['enum_name']
    if len(animation['collision_data']) > 0:
      def_string += '  true,\n\n'
    else:
      def_string += '  false,\n\n'
  
  if (close):
    def_string = def_string[:-3] # Remove the last comma and space
  def_string += '\n};\n\n' # Close the definition
  

  return def_string

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
"""/************
Resource IDs header. This was generated by update.py and contains information
on the locations of resources for loading, generated resource enum names, and
animation info. Later, I plan on making the storage for all this stuff more
efficient (especially animations), but for now I just want it to work.

DON'T MANUALLY CHANGE THE FILE! This file will be overwritten every build
************/

#ifndef __RESOURCE_IDS__


#include <string>
#include <engine.h>

#define __RESOURCE_IDS__

#ifndef __COLL_ENUM__
#define __COLL_ENUM__
// This is an int to allow us to store it in the collision data array
enum CollisionType : int
{
  COLLISION_NONE,
  COLLISION_BOUNDING_BOX,

  COLLISION_COUNT
};
#endif


"""
)

image_write = get_definition_string(images, IMAGE_PREFIX, 'Images',
                                    IMAGE_ENUM, IMAGE_PATHVAR)

animation_write = get_animation_definition_string(animations, ANIM_PREFIX,
                                                  IMAGE_PREFIX, ANIM_ENUM,
                                                  ANIM_STRUCTVAR)

sound_write = get_definition_string(sounds, SOUND_PREFIX, 'Sounds',
                                    SOUND_ENUM, SOUND_PATHVAR)
include_file.write(image_write)
include_file.write(animation_write)
include_file.write(sound_write)
include_file.write('\n#endif\n')
