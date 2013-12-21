#ifndef __INPUT_H__
#define __INPUT_H__

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

extern const std::string keyboard_key_names[sf::Keyboard::KeyCount];
extern const std::string mouse_button_names[sf::Keyboard::KeyCount];

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
    sf::RenderWindow *reference_window;
    std::ostream *outstream;

    // Private functions
    void update_mouse_position();
  
  public:
    // Reference variables
    sf::Vector2f mouse_position;
    std::vector<ButtonStatus> key;
    std::vector<ButtonStatus> mouse;
    WindowStatus window;

    Input(sf::RenderWindow& reference_window);
    // Constructor
    // reference_window is the window that will pass events to the input and
    // be used for getting relative mouse pos.

    ~Input();
    // Destructor

    void update();
    // MODIFIES: this, reference_window
    // EFFECTS:  Updates the input state from the given event. Should only
    //           be called once per frame

    void start_logging(std::ostream &logstream);
    // EFFECTS: Begins outputting any input events to the given output stream

    void stop_logging();
    // EFFECTS: Stops outputting input events

};

#endif
