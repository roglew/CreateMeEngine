#include "../src/render.h"
#include "../src/input.h"
#include <SFML/Graphics.hpp>

int main(int argc, const char *argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Render test");

	WindowStatus window_status;
	Input input(window);
	Render render(window);

	sf::Texture texture;
	texture.loadFromFile("tests/testimage.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(128, 128);

	while (window.isOpen())
	{
		input.update();
		window_status = input.window_events();
		if (window_status.closed)
			window.close();
	
		render.clear();
		render.draw(sprite);
		render.render();
		window.display();

	}
	return 0;
}

