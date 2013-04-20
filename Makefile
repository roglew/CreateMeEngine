SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm lib/*;
	rm *.test;

lib/input.o: src/input.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)

input.test: lib/input.o tests/inputtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

