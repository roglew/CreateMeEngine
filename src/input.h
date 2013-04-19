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
		ButtonStatus get_key_state(sf::Keyboard::Key);
		sf::Vector2f mouse_pos();

};
