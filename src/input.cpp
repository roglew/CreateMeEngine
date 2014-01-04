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

void Input::update_mouse_position()
{
  sf::Vector2i raw_coords;
  raw_coords = sf::Mouse::getPosition(*reference_window);
  mouse_position = reference_window->mapPixelToCoords(raw_coords);
}

Input::Input(sf::RenderWindow& ref_window)
{
  // Make the vectors the right size
  key.resize(sf::Keyboard::KeyCount);
  mouse.resize(sf::Mouse::ButtonCount);

  // Save the reference window
  reference_window = &ref_window;

  // Prevent the window from repeating key presses
  ref_window.setKeyRepeatEnabled(false);

  // Initialize everything to default values

  outstream = NULL;
  // Window events
  window.closed             = false;
  window.resized            = false;
  window.lost_focus         = false;
  window.gained_focus       = false;
  window.has_focus          = true;
  window.mouse_is_in_window = true;
  window.text_entered       = "";

  // Keyboard events
  for (unsigned int i=0; i < key.size(); i++)
  {
    key[i].pressed  = false;
    key[i].released = false;
    key[i].down     = false;
  }

  // Mouse events
  for (unsigned int i=0; i < mouse.size(); i++)
  {
    mouse[i].pressed  = false;
    mouse[i].released = false;
    mouse[i].down     = false;
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
  std::vector<ButtonStatus>::iterator it;
  for (it = key.begin(); it != key.end(); it++)
  {
    (*it).pressed  = false;
    (*it).released = false;
  }

  // Mouse
  for (unsigned int i=0; i < mouse.size(); i++)
  {
    mouse[i].pressed  = false;
    mouse[i].released = false;
  }

  // Window
  window.closed       = false;
  window.resized      = false;
  window.lost_focus   = false;
  window.gained_focus = false;

  //// Get the new events

  // Always update the mouse position
  update_mouse_position();

  while (reference_window->pollEvent(event))
  {
    int mouse_button;
    int keyboard_key;
    sf::Vector2i newcoords;
    switch(event.type)
    {
      case sf::Event::Closed:
        window.closed = true;
        if (outstream) *outstream << "Window closed\n";
      break;

      case sf::Event::Resized:
        window.resized = true;
        if (outstream) *outstream << "Window resized\n";
      break;

      case sf::Event::LostFocus:
        window.lost_focus = true;
        window.has_focus = false;
        if (outstream) *outstream << "Window lost focus\n";
      break;

      case sf::Event::GainedFocus:
        window.gained_focus = true;
        window.has_focus = true;
        update_mouse_position();
        if (outstream) *outstream << "Window gained focus\n";
      break;

      case sf::Event::TextEntered:
      break;

      case sf::Event::KeyPressed:
        keyboard_key = event.key.code;
        key[keyboard_key].pressed = true;
        key[keyboard_key].down = true;
        if (outstream)
          *outstream << keyboard_key_names[keyboard_key] << " pressed\n";
      break;

      case sf::Event::KeyReleased:
        keyboard_key = event.key.code;
        key[keyboard_key].released = true;
        key[keyboard_key].down = false;
        if (outstream)
          *outstream << keyboard_key_names[keyboard_key] << " released\n";
      break;

      case sf::Event::MouseWheelMoved:
      break;

      case sf::Event::MouseButtonPressed:
        mouse_button = event.mouseButton.button;
        mouse[mouse_button].pressed = true;
        mouse[mouse_button].down = true;
        if (outstream)
          *outstream << mouse_button_names[mouse_button] << " pressed\n";
      break;

      case sf::Event::MouseButtonReleased:
        mouse_button = event.mouseButton.button;
        mouse[mouse_button].released = true;
        mouse[mouse_button].down = false;
        mouse[mouse_button].pressed = false;
        if (outstream)
          *outstream << mouse_button_names[mouse_button] << " released\n";
      break;

      case sf::Event::MouseMoved:
      break;

      case sf::Event::MouseEntered:
        update_mouse_position();
        window.mouse_is_in_window = true;
        if (outstream) *outstream << "Mouse has entered the window\n";
      break;

      case sf::Event::MouseLeft:
        update_mouse_position();
        window.mouse_is_in_window = false;
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

void Input::start_logging(std::ostream &logstream)
{
  outstream = &logstream;
}

void Input::stop_logging()
{
  outstream = NULL;
}

