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
src/resourceids.h: $(IMAGES) resources/update.py
	python resources/update.py

# Build .o files from .cpp
bin/%.o: src/%.cpp src/resourceids.h
	g++ $^ -o $@ -c $(SFML_FLAGS)

# Engine .o files
bin/engine/%.o: src/engine/%.cpp src/resourceids.h
	g++ $^ -o $@ -c $(SFML_FLAGS)

# Cleaning
clean: cleanbin cleantests cleangen

cleanbin:
	rm -r bin
	mkdir -p bin/engine

cleantests:
	rm $(TEST_FILES)

cleangen:
	rm src/resourceids.h

# Main build
resourceorg.test: src/main.cpp bin/engine/resourcemanager.o
	g++ $^ -o $@ -c $(SFML_FLAGS)
	chmod +x resourceorg.test
