#####
# Config

SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Find cpp files and their corresponding.o
CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(wildcard bin/*.o)
TEST_FILES = $(wildcard *.test)

IMAGES := $(shell find resources/images)

####
# Builds

# Resource IDs
src/resourceids.h: $(IMAGES)
	python resources/update.py

# Build .o files from .cpp
bin/%.o: src/%.cpp
	g++ $^ -o $@ -c $(SFML_FLAGS)

# Engine .o files
bin/engine/%.o: src/engine/%.cpp
	g++ $^ -o $@ -c $(SFML_FLAGS)

# Cleaning
clean: cleanbin cleantests

cleanbin:
	rm -r bin
	mkdir -p bin/engine

cleantests:
	rm $(TEST_FILES)

# Main build
resourceorg.test: bin/engine/resourcemanager.o src/resourceids.h
	g++ $^ -o $@ -c $(SFML_FLAGS)
