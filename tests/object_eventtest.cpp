#include "../src/gameobject.h"
#include "../src/objectevent.h"
#include "../src/render.h"
#include "../src/input.h"
#include "../src/vector.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

void move_up(ResponseInfo* info)
{
	GameObjectEventInfo* obj = static_cast<GameObjectEventInfo*>(info);
	obj->object->move(0, -2);
}

void move_down(ResponseInfo* info)
{
	GameObjectEventInfo* obj = static_cast<GameObjectEventInfo*>(info);
	obj->object->move(0, 2);
}

void move_left(ResponseInfo* info)
{
	GameObjectEventInfo* obj = static_cast<GameObjectEventInfo*>(info);
	obj->object->move(-2, 0);
}

void move_right(ResponseInfo* info)
{
	GameObjectEventInfo* obj = static_cast<GameObjectEventInfo*>(info);
	obj->object->move(2, 0);
}

int main(int argc, const char *argv[])
{
	Render render;
	sf::RenderWindow* window = render.get_created_window();
	Input input(*window);
	WindowStatus window_status;
	ButtonStatus button_status;

	// Create the object
	sf::Texture tex;
	Sprite *spr = new Sprite;
	GameObject obj;
	tex.loadFromFile("resources/sprite.png");
	spr->setTexture(tex);
	obj.add_animation();
	obj.append_frame(0, spr);
	obj.set_position(64, 64);

	// Create events
	ButtonStatus but_up, but_down, but_left, but_right;
	obj.register_event(&but_up.down, move_up);
	obj.register_event(&but_down.down, move_down);
	obj.register_event(&but_left.down, move_left);
	obj.register_event(&but_right.down, move_right);

	while (window->isOpen())
	{
		input.update(); // Get the input events
		window_status = input.window_events();
		but_up = input.key_state(sf::Keyboard::Up);
		but_down = input.key_state(sf::Keyboard::Down);
		but_left = input.key_state(sf::Keyboard::Left);
		but_right = input.key_state(sf::Keyboard::Right);

		obj.process_events();
		obj.update_sprite();

		if (window_status.closed)
			window->close();

		render.draw(obj, -1);
		render.clear();
		render.render();
	}

	delete spr;
	return 0;
}


