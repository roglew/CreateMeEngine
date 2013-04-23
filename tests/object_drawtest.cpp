#include "../src/render.h"
#include "../src/gameobject.hpp"
#include "../src/sprite.h"
#include "../src/input.h"
#include "../src/render.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main(int argc, const char *argv[])
{
	GameObject obj;
	Sprite* spr = new Sprite;
	sf::Texture tex;
	tex.loadFromFile("resources/sprite.png");
	spr->setTexture(tex);
	int anim;
	anim = obj.add_animation();
	obj.append_frame(anim, spr);
	obj.set_position(64, 64);

	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Drawing an object");
	window.setFramerateLimit(60);
	Render render(window);
	Input input(window);
	WindowStatus window_status;

	int i=0;
	while (window.isOpen())
	{
		input.update();
		window_status = input.window_events();
		if (window_status.closed)
			window.close();
		
		i++;
		obj.set_position(320-64 + 64*std::cos(i/20.0), 240-64 + 64*std::sin(i/20.0));

		render.draw(obj, -1);
		render.clear();
		render.render();
		window.display();
	}

	delete spr;
	return 0;
}

