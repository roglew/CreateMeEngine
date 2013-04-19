#include <input.h>
#include <vector>
#include <SFML/Window.hpp>

void Input::update(sf::Window window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
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
			break;

			case sf::Event::MouseButtonReleased:
			break;

			case sf::Event::MouseMoved:
			break;

			case sf::Event::MouseEntered:
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
//ButtonStatus Input::mouse_button_state(sf::Mouse::Button);
//
//sf::Vector2f Input::mouse_pos();
//
//sf::Vector2f Input::mouse_pos(const sf::Window & relativeTo);

