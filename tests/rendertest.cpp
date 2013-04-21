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
	sf::Sprite sprite, sprite2, sprite3;
	sprite.setTexture(texture);
	sprite2.setTexture(texture);
	sprite3.setTexture(texture);
	sprite.setPosition(130, 130);
	sprite2.setPosition(180, 150);
	sprite3.setPosition(170, 170);

	while (window.isOpen())
	{
		input.update();
		window_status = input.window_events();
		if (window_status.closed)
			window.close();
	
		render.draw(sprite3, -1);
		render.draw(sprite2, 2);
		render.draw(sprite);
		render.clear();
		render.render();
		window.display();

	}
	return 0;
}

