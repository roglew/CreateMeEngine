SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

clean: cleanlib cleantests

cleanlib:
	rm lib/*

cleantests:
	rm *.test


lib/input.o: src/input.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)

lib/render.o: src/render.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)

lib/objectevent.o: src/objectevent.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)

lib/sprite.o: src/sprite.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)

lib/gameobject.o: src/gameobject.cpp
	g++ $^ -c -o $@ $(SFML_FLAGS)


input.test: lib/input.o tests/inputtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

render.test: lib/render.o lib/input.o tests/rendertest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

event.test: src/objectevent.hpp tests/eventtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

object_draw.test: lib/gameobject.o lib/objectevent.o src/ids.h lib/render.o lib/input.o tests/object_drawtest.cpp
	g++ $^ -o $@ $(SFML_FLAGS)

