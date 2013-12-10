#####
# Config

SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

CPP_FILES = $(wildcard src/*.cpp)  # All of the c++ files
OBJ_FILES = $(wildcard bin/*.o)    # Existing .o files
TEST_FILES = $(wildcard *.test)    # Built test files
ENGINE_DIR = ../../src/            # Where the engine files are stored

# Find image files
IMAGES := $(shell find resources/images)

####
# Builds

# Main build
animation.test: src/main.cpp $(wildcard engbin/*) src/resourceids.h
	cd ../..; make obj
	cp ../../bin/* engbin/
	g++ $< $(wildcard engbin/*) -g -Wall -std=c++11 -o $@ -I$(ENGINE_DIR) $(SFML_FLAGS)
	chmod +x $@

### Dependencies

# Resource IDs
src/resourceids.h: $(IMAGES) resources/update.py
	python resources/update.py

# Build .o files from .cpp
bin/%.o: src/%.cpp src/resourceids.h
	g++ $^ -Wall -o $@ -c $(SFML_FLAGS)

# Copy compiled engine .o files to our folder
engbin/%.o: ../../bin/%.o
	cd ../..; make obj; cp ../../bin/* engbin/

engobj:
	cd ../..; make obj;
	cp ../../bin/* engbin/

### Cleaning
clean: cleanbin cleangen cleantests engclean

cleanbin:
	rm -rf bin
	mkdir -p bin/engine

cleantests:
	rm -f $(TEST_FILES)

cleangen:
	rm -f src/resourceids.h

engclean:
	cd ../..; make clean
