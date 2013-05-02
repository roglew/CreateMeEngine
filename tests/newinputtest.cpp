#include <SFML/Graphics.hpp>
#include "../src/gameobject.h"
#include "../src/input.h"
#include "../src/sprite.h"
#include "../src/render.h"

class CookieMonsterObj: public GameObject
{
	private:
		Input* input;

	public:
	CookieMonsterObj(Input* input)
	{
		this->input = input;
	}

	void process_events()
	{
		set_position(input->mouse_position.x, input->mouse_position.y);
		//if (input->key[sf::Keyboard::Right].down)
		//{
		//	move(1, 0);
		//}
	}
};

int main(int argc, const char *argv[])
{
	Render render;
	sf::RenderWindow *window = render.get_created_window();
	Input input(*window);
	CookieMonsterObj object(&input);

	sf::Texture tex;
	tex.loadFromFile("resources/sprite.png");
	Sprite spr;
	spr.setTexture(tex);
	object.add_animation();
	object.append_frame(0, &spr);
	object.set_position(0, 128);

	while(window->isOpen())
	{
		input.update();
		if (input.window.closed)
			window->close();
		object.process_events();
		render.clear();
		render.draw(object);
		render.render();
	}
	return 0;
}
