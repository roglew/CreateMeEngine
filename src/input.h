#ifndef __INPUT_H__
#define __INPUT_H__

#include <vector>
#include <string>
#include <SFML/Window.hpp>

struct ButtonStatus
{
	bool pressed;
	bool released;
	bool down;
};

struct WindowStatus
{
	bool closed, resized, lost_focus, gained_focus, text_entered;
	std::string entered_text;
};

class Input
{
	private:
		sf::Vector2f mouse_position;
		std::vector<ButtonStatus> key_states;
		std::vector<ButtonStatus> mouse_states;
		WindowStatus window_status;
	
	public:
		Input();
		// Constructor

		~Input();
		// Destructor

		void update(sf::Window);
		// MODIFIES: this
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

		sf::Vector2f mouse_pos(const sf::Window & relativeTo);
		// EFFECTS: Returns a vector containing the position of the mouse cursor
		//          relative to the given window's view

};

#endif
