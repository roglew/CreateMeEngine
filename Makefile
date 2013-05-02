#####
# Config

SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Find cpp files and their corresponding.o
CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(wildcard bin/*.o)
TEST_FILES = $(wildcard *.test)

####
# Builds

# Cleaning
clean: cleanbin cleantests

cleanbin:
	rm $(OBJ_FILES)

cleantests:
	rm $(TEST_FILES)

# Build .o files from .cpp
bin/%.o: src/%.cpp
	g++ $^ -o $@ -c $(SFML_FLAGS)

####
# Basic tests

newinput.test: tests/newinputtest.cpp bin/gameobject.o bin/render.o bin/input.o bin/sprite.o
	g++ $^ -o $@ $(SFML_FLAGS)

