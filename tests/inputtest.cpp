#include "../src/input.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, const char *argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Input Debug");
	Input input(&window);
	input.start_logging(std::cout);
	WindowStatus window_status;
	while (window.isOpen())
	{
		input.update();
		window_status = input.window_events();
		if (window_status.closed)
			window.close();

		window.clear();
		window.display();
	}
	return 0;
}

