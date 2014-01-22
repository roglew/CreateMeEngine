#####
# Config

SFML_FLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
COMPILE_FLAGS = -g -Wall -Werror -pedantic -Wvla -std=c++11

CPP_FILES = $(wildcard src/*.cpp)  # All of the c++ files
OBJ_FILES = $(wildcard bin/*.o)    # Existing .o files
ALL_OBJ_FILES = $(addprefix bin/, $(addsuffix .o, $(basename $(notdir $(wildcard src/*.cpp)))))
ALL_ENG_OBJ_FILES = $(addprefix engbin/, $(addsuffix .o, $(basename $(notdir $(wildcard src/engine/*.cpp)))))
ENG_FILES = $(wildcard engbin/*.o) # Engine objects
HPP_FILES = $(wildcard src/*.hpp) $(wildcard src/**/*.hpp)  # All of the c++ files
TEST_FILES = $(wildcard *.test)    # Built test files

# Find image files
IMAGES := $(shell find resources/images)

####
# Builds

# Main build
#g++ $< $(wildcard engbin/*) -o $@ -I$(ENGINE_DIR) $(COMPILE_FLAGS) $(SFML_FLAGS)
ech:
	@echo $(ALL_ENG_OBJ_FILES)
	@echo $(ALL_OBJ_FILES)

sound.test: $(CPP_FILES) $(ENG_FILES) $(HPP_FILES) src/resourceids.h
	make $(ALL_OBJ_FILES)
	make $(ALL_ENG_OBJ_FILES)
	g++ $^ -o $@ $(COMPILE_FLAG) $(SFML_FLAGS)
	chmod +x $@

### Dependencies

# Get updated engine source (only for developing right now)
copyeng: $(wildcard ../../src/*)
	cp $^ src/engine/

# Resource IDs
src/resourceids.h: $(IMAGES) resources/update.py
	python resources/update.py

# Build game .o files from .cpp
bin/%.o: src/%.cpp src/resourceids.h
	g++ $^ -o $@ -c $(COMPILE_FLAGS) $(SFML_FLAGS)

# Build engine object files
engbin/%.o: src/engine/%.cpp
	g++ $^ -o $@ -c $(COMPILE_FLAGS) $(SFML_FLAGS)

### Cleaning
clean: cleanbin cleangen cleantests engclean copyeng

cleanbin:
	rm -rf bin
	mkdir -p bin/engine

cleantests:
	rm -f $(TEST_FILES)

cleangen:
	rm -f src/resourceids.h

engclean:
	rm -rf src/engine
	mkdir src/engine
