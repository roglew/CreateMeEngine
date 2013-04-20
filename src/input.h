#ifndef __INPUT_H__
#define __INPUT_H__

#include <vector>
#include <string>
#include <SFML/Window.hpp>

std::string keyboard_key_names[] = {
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
"F10", "F11", "F12", "F13", "F14", "F15", "Pause",
"KeyCount"
};

std::string mouse_button_names[] = {
  "Left", "Right", "Middle",
  "XButton1", "XButton2",
  "ButtonCount"
};

struct ButtonStatus
{
	bool pressed;
	bool released;
	bool down;
};

struct WindowStatus
{
	bool closed, resized, lost_focus, gained_focus, text_entered;
	bool mouse_is_in_window, has_focus;
	std::string entered_text;
};

class Input
{
	private:
		sf::Window *window;
		sf::Vector2f mouse_position, mouse_position_rel;
		std::vector<ButtonStatus> key_states;
		std::vector<ButtonStatus> mouse_states;
		WindowStatus window_status;
		std::ostream *outstream;
	
	public:
		Input(sf::Window*);
		// Constructor
		// reference_window is the window that will pass events to the input and
		// be used for getting relative mouse pos.

		~Input();
		// Destructor

		void update();
		// MODIFIES: this, reference_window
		// EFFECTS:  Updates the input state from the given event. Should only
		//           be called once per frame

		WindowStatus window_events();
		// EFFECTS: Returns a WindowStatus struct to handle window events

		ButtonStatus key_state(sf::Keyboard::Key);
		// EFFECTS: Returns a ButtonState struct that contains if the key is
		//          held down,has been pressed this frame, or released this frame

		ButtonStatus mouse_state(sf::Mouse::Button);
		// EFFECTS: Returns a ButtonState struct that contains if the button is
		//          held down, has been pressed this frame, or released this frame


		sf::Vector2f mouse_pos();
		// EFFECTS: Returns a vector containing the position of the mouse cursor
		//          in desktop coordinates

		sf::Vector2f mouse_pos_rel();
		// EFFECTS: Returns a vector containing the position of the mouse cursor
		//          relative to the given window's view

		void start_logging(std::ostream*);
		// EFFECTS: Begins outputting any input events to the given output stream

		void stop_logging();
		// EFFECTS: Stops outputting input events

};

#endif
