#include <SFML/Graphics.hpp>
#include "objects.cpp"

int main(int argc, const char *argv[])
{
	// Create the game window
	Render render;
	sf::RenderWindow *window = render.get_created_window();
	Input (*window);
	return 0;
}
