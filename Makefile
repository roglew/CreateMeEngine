SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

clean: cleanlib cleantests

cleanbin:
	rm bin/*

cleantests:
	rm *.test


bin/input.o: src/input.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)

bin/render.o: src/render.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)

bin/objectevent.o: src/objectevent.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)

bin/sprite.o: src/sprite.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)

bin/gameobject.o: src/gameobject.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)


input.test: bin/input.o tests/inputtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

render.test: bin/render.o bin/input.o tests/rendertest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

event.test: src/objectevent.hpp tests/eventtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

object_draw.test: bin/gameobject.o bin/objectevent.o src/ids.h bin/render.o bin/input.o tests/object_drawtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

