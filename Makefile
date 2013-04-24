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

input.test: bin/input.o tests/inputtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

render.test: bin/render.o bin/input.o tests/rendertest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

event.test: src/objectevent.hpp tests/eventtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

object_draw.test: bin/gameobject.o bin/objectevent.o src/ids.h bin/render.o bin/input.o tests/object_drawtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

object_events.test: bin/gameobject.o bin/objectevent.o src/ids.h bin/render.o bin/input.o tests/object_eventtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

