#include <vector>
#include <SFML/system.hpp>

struct ButtonStatus
{
	bool pressed;
	bool released;
	bool down;
};

class Input
{
	private:
		sf::Vector2f mouse_position;
		std::vector<ButtonStatus> key_state(sf::Keyboard::KeyCount);
		std::vector<ButtonStatus> mouse_button_state(sf::Mouse::ButtonCount);
	
	public:
		void update(sf::Event);
		// MODIFIES: this
		// EFFECTS:  Updates the input state from the given event. Should only
		//           be called once per frame

		ButtonStatus key_state(sf::Keyboard::Key);
		// EFFECTS: Returns a ButtonState struct that contains if the key is
		//          held down,has been pressed this frame, or released this frame

		ButtonStatus mouse_button_state(sf::Mouse::Button);
		// EFFECTS: Returns a ButtonState struct that contains if the button is
		//          held down, has been pressed this frame, or released this frame


		sf::Vector2f mouse_pos();
		// EFFECTS: Returns a vector containing the position of the mouse cursor
		//          in desktop coordinates

		sf::Vector2f mouse_pos(const sf::Window & relativeTo);
		// EFFECTS: Returns a vector containing the position of the mouse cursor
		//          relative to the given window's view

};
