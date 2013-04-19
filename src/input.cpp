#include <input.h>
#include <vector>
#include <SFML/Window.hpp>

Input::Input()
{
	key_states.reserve(sf::Keyboard::KeyCount);
	mouse_states.reserve(sf::Mouse::ButtonCount);
}

void Input::update(sf::Window window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		int mouse_button;
		int keyboard_key;
		switch(event.type)
		{
			case sf::Event::Closed:
			break;

			case sf::Event::Resized:
			break;

			case sf::Event::LostFocus:
			break;

			case sf::Event::GainedFocus:
			break;

			case sf::Event::TextEntered:
			break;

			case sf::Event::KeyPressed:
			break;

			case sf::Event::KeyReleased:
			break;

			case sf::Event::MouseWheelMoved:
			break;

			case sf::Event::MouseButtonPressed:
				mouse_button = event.mouseButton.button;
				mouse_states[mouse_button].pressed = true;
				mouse_states[mouse_button].down = true;
			break;

			case sf::Event::MouseButtonReleased:
				mouse_button = event.mouseButton.button;
				mouse_states[mouse_button].released = true;
				mouse_states[mouse_button].down = false;
			break;

			case sf::Event::MouseMoved:
				mouse_position.x = event.mouseMove.x;
				mouse_position.y = event.mouseMove.y;
			break;

			case sf::Event::MouseEntered:
				mouse_position.x = event.mouseMove.x;
				mouse_position.y = event.mouseMove.y;
			break;

			case sf::Event::MouseLeft:
			break;

			case sf::Event::JoystickButtonPressed:
			break;

			case sf::Event::JoystickButtonReleased:
			break;

			case sf::Event::JoystickMoved:
			break;

			case sf::Event::JoystickConnected:
			break;

			case sf::Event::JoystickDisconnected:
			break;

			default:
			break;
		}
	}
}

//ButtonStatus Input::key_state(sf::Keyboard::Key);
//
//ButtonStatus Input::mouse_states(sf::Mouse::Button);
//
//sf::Vector2f Input::mouse_pos();
//
//sf::Vector2f Input::mouse_pos(const sf::Window & relativeTo);

