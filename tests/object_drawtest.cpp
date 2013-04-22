#include "../src/render.h"
#include "../src/gameobject.hpp"
#include "../src/sprite.h"
#include "../src/input.h"
#include "../src/render.h"
#include <SFML/Graphics.hpp>

int main(int argc, const char *argv[])
{
	GameObject obj;
	sf::Sprite* spr = new sf::Sprite;
	sf::Texture tex;
	tex.load_from_file("resources/sprite.png");
	spr->setTexture(tex);
	int anim;
	anim = obj.add_animation();
	obj.append_frame(anim, spr);
	obj.set_position(64, 64);

	sf::RenderWindow window;
	Render render(window);
	Input input(window);
	WindowStatus window_status;

	while (window.isOpen())
	{
		input.update();
		window_status = input.window_events();
		if (window_status.closed())
			window.close();
		render.draw(object);
		render.clear();
		render.display();
	}

	delete spr;
	return 0;
}

