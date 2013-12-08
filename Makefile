#####
# Config

SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Find cpp files and their corresponding.o
CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(wildcard bin/*.o)
TEST_FILES = $(wildcard *.test)
ALL_OBJ_FILES = $(addprefix bin/, $(addsuffix .o, $(basename $(notdir $(wildcard src/*.h)))))

####
# Builds

build: newinput.test
	./newinput.test

obj: $(ALL_OBJ_FILES)

# Cleaning
clean: cleanbin cleantests

cleanbin:
	rm $(OBJ_FILES)

cleantests:
	rm $(TEST_FILES)

# Build .o files from .cpp
bin/%.o: src/%.cpp
	g++ $^ -Wall -o $@ -c -std=c++11 $(SFML_FLAGS)

####
# Basic tests

newinput.test: tests/newinputtest.cpp bin/gameobject.o bin/render.o bin/input.o bin/sprite.o
	g++ $^ -o $@ $(SFML_FLAGS)

collisions.test: tests/collisiontest.cpp bin/collision.o
	g++ $^ -o $@ $(SFML_FLAGS)

resourceorg.test: tests/resource_org/Makefile bin/resourcemanager.o
	g++ $^ -o $@ $(SFML_FLAGS) -symbolic
