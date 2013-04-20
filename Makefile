SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
lib/input.o: src/input.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)

input_test: lib/input.o tests/inputtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

