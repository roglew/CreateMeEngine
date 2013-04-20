#include "input.h"
#include <vector>
#include <string>
#include <SFML/Window.hpp>

const std::string keyboard_key_names[] = {
"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
"O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",

"Num0", "Num1", "Num2", "Num3", "Num4", "Num5", "Num6",
"Num7", "Num8", "Num9",

"Escape", "LControl", "LShift", "LAlt", "LSystem",
"RControl", "RShift", "RAlt", "RSystem", "Menu",

"LBracket", "RBracket", "SemiColon", "Comma", "Period", "Quote",
"Slash", "BackSlash", "Tilde", "Equal", "Dash", "Space", "Return",
"Back", "Tab", "PageUp", "PageDown", "End", "Home", "Insert", "Delete",
"Add", "Subtract", "Multiply", "Divide",

"Left", "Right", "Up", "Down",

"Numpad0", "Numpad1", "Numpad2", "Numpad3", "Numpad4", "Numpad5",
"Numpad6", "Numpad7", "Numpad8", "Numpad9",

"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9",
"F10", "F11", "F12", "F13", "F14", "F15", "Pause"
};

const std::string mouse_button_names[] = {
  "Left", "Right", "Middle",
  "XButton1", "XButton2"
};

Input::Input(sf::Window* reference_window)
{
	// Make the vectors the right size
	key_states.reserve(sf::Keyboard::KeyCount);
	mouse_states.reserve(sf::Mouse::ButtonCount);

	// Save the reference window
	window = reference_window;

	// Prevent the window from repeating key presses
	window->setKeyRepeatEnabled(false);

	// Initialize everything to default values

	outstream = NULL;
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

Input::~Input()
{
	return;
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
				if (outstream) *outstream << "Window closed\n";
			break;

			case sf::Event::Resized:
				window_status.resized = true;
				if (outstream) *outstream << "Window resized\n";
			break;

			case sf::Event::LostFocus:
				window_status.lost_focus = true;
				window_status.has_focus = false;
				if (outstream) *outstream << "Window lost focus\n";
			break;

			case sf::Event::GainedFocus:
				window_status.gained_focus = true;
				window_status.has_focus = true;
				if (outstream) *outstream << "Window gained focus\n";
			break;

			case sf::Event::TextEntered:
			break;

			case sf::Event::KeyPressed:
				keyboard_key = event.key.code;
				key_states[keyboard_key].pressed = true;
				key_states[keyboard_key].down = true;
				if (outstream)
					*outstream << keyboard_key_names[keyboard_key] << " pressed\n";
			break;

			case sf::Event::KeyReleased:
				keyboard_key = event.key.code;
				key_states[keyboard_key].released = true;
				key_states[keyboard_key].down = false;
				if (outstream)
					*outstream << keyboard_key_names[keyboard_key] << " released\n";
			break;

			case sf::Event::MouseWheelMoved:
			break;

			case sf::Event::MouseButtonPressed:
				mouse_button = event.mouseButton.button;
				mouse_states[mouse_button].pressed = true;
				mouse_states[mouse_button].down = true;
				if (outstream)
					*outstream << mouse_button_names[mouse_button] << " pressed\n";
			break;

			case sf::Event::MouseButtonReleased:
				mouse_button = event.mouseButton.button;
				mouse_states[mouse_button].released = true;
				mouse_states[mouse_button].down = false;
				if (outstream)
					*outstream << mouse_button_names[mouse_button] << " released\n";
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
				if (outstream) *outstream << "Mouse has entered the window\n";
			break;

			case sf::Event::MouseLeft:
				window_status.mouse_is_in_window = false;
				if (outstream) *outstream << "Mouse has left the window\n";
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

WindowStatus Input::window_events()
{
	return window_status;
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

void Input::start_logging(std::ostream &logstream)
{
	outstream = &logstream;
}

void Input::stop_logging()
{
	outstream = NULL;
}

