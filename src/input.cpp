#include <input.h>
#include <vector>
#include <SFML/Window.hpp>

Input::Input(sf::Window* reference_window)
{
	// Make the vectors the right size
	key_states.reserve(sf::Keyboard::KeyCount);
	mouse_states.reserve(sf::Mouse::ButtonCount);

	// Save the reference window
	window = reference_window;

	// Initialize everything to default values

	// Window events
	window_status.closed             = false;
	window_status.resized            = false;
	window_status.lost_focus         = false;
	window_status.gained_focus       = false;
	window_status.has_focus          = true;
	window_status.mouse_is_in_window = true;
	window_status.text_entered       = "";

	// Keyboard events
	for (int i=0; i < key_states.size(); i++)
	{
		key_states[i].pressed  = false;
		key_states[i].released = false;
		key_states[i].down     = false;
	}

	// Mouse events
	for (int i=0; i < mouse_states.size(); i++)
	{
		mouse_states[i].pressed  = false;
		mouse_states[i].released = false;
		mouse_states[i].down     = false;
	}
}

void Input::update()
{
	sf::Event event;

	//// Reset the 1-frame events

	// Keyboard
	for (int i=0; i < key_states.size(); i++)
	{
		key_states[i].pressed  = false;
		key_states[i].released = false;
	}

	// Mouse
	for (int i=0; i < mouse_states.size(); i++)
	{
		mouse_states[i].pressed  = false;
		mouse_states[i].released = false;
	}

	// Window
	window_status.closed       = false;
	window_status.resized      = false;
	window_status.lost_focus   = false;
	window_status.gained_focus = false;

	//// Get the new events

	while (window->pollEvent(event))
	{
		int mouse_button;
		int keyboard_key;
		switch(event.type)
		{
			case sf::Event::Closed:
				window_status.closed = true;
			break;

			case sf::Event::Resized:
				window_status.resized = true;
			break;

			case sf::Event::LostFocus:
				window_status.lost_focus = true;
				window_status.has_focus = false;
			break;

			case sf::Event::GainedFocus:
				window_status.gained_focus = true;
				window_status.has_focus = true;
			break;

			case sf::Event::TextEntered:
			break;

			case sf::Event::KeyPressed:
				keyboard_key = event.key.code;
				key_states[keyboard_key].pressed = true;
				key_states[keyboard_key].down = true;
			break;

			case sf::Event::KeyReleased:
				keyboard_key = event.key.code;
				key_states[keyboard_key].released = true;
				key_states[keyboard_key].down = false;
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
				mouse_position_rel.x = sf::Mouse::getPosition(*window).x;
				mouse_position_rel.y = sf::Mouse::getPosition(*window).y;
			break;

			case sf::Event::MouseEntered:
				window_status.mouse_is_in_window = true;
				mouse_position.x = event.mouseMove.x;
				mouse_position.y = event.mouseMove.y;
				mouse_position_rel.x = sf::Mouse::getPosition(*window).x;
				mouse_position_rel.y = sf::Mouse::getPosition(*window).y;
			break;

			case sf::Event::MouseLeft:
				window_status.mouse_is_in_window = false;
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

ButtonStatus Input::key_state(sf::Keyboard::Key key)
{
	return key_states[key];
}

ButtonStatus Input::mouse_state(sf::Mouse::Button button)
{
	return mouse_states[button];
}

sf::Vector2f Input::mouse_pos()
{
	return mouse_position;
}

sf::Vector2f Input::mouse_pos_rel()
{
	return mouse_position_rel;
}

