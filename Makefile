#####
# Config

SFML_FLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# Find cpp files and their corresponding.o
CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(wildcard bin/*.o)
TEST_FILES = $(wildcard *.test)
ALL_OBJ_FILES = $(addprefix bin/, $(addsuffix .o, $(basename $(notdir $(wildcard src/*.h)))))

####
# Builds

obj: $(ALL_OBJ_FILES)

# Cleaning
clean: cleanbin cleantests

cleanbin:
	rm -f $(OBJ_FILES)

cleantests:
	rm -f $(TEST_FILES)

# Build .o files from .cpp
bin/%.o: src/%.cpp
	g++ $^ -Wall -g -o $@ -c -std=c++11 $(SFML_FLAGS)
