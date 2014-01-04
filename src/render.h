#ifndef __RENDER_H__
#define __RENDER_H__

#include "gameobject.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class GameObject;

enum DrawEventId{DRAW_OBJECT, DRAW_DRAWABLE, DRAW_CLEAR,
  DrawEventIdSize};

struct DrawEvent
{
  DrawEventId id;
  int depth;
  const sf::Drawable* drawable;
  sf::Color color;

  bool operator < (const DrawEvent& event) const
  {
    return depth < event.depth;
  }
};

class Render
{
  private:
    std::vector<DrawEvent> draw_queue;
    sf::RenderTarget *render_target;
    sf::View *view;
    bool owns_render_target;

    void queue_draw_event(DrawEvent to_queue);
    // Adds a draw event to the queue

    void clear_queue();
    // MODIFIES: this
    // EFFECTS:  Clears the draw queue

    void construct(double width, double height, std::string title);
    // Basic constructor function

  public:
    Render();
    // Normal constructor. Creates a 640x480 window with no title as default
    // render target

    Render(double width, double height, std::string title);
    // Initializes render target as a sf::RenderWindow with the given width,
    // height, and title

    Render(sf::RenderTarget& target);
    // Render to a different render target

    ~Render();
    // Destructor

    void render();
    // MODIFIES: RenderWindow
    // EFFECTS:  Draws everything in the draw queue to the window

    sf::View* get_view();
    // EFFECTS: Returns a pointer to the sf::View associated with the render

    void clear(sf::Color clear_to = sf::Color::Black, int depth = 99999999);
    // MODIFIES: this
    // EFFECTS:  clears the screen at the given depth

    void draw(const sf::Drawable& to_draw, int depth = 0);
    // REQUIRES: Drawable exists when render() is called
    // MODIFIES: this
    // EFFECTS:  Draws the sprite at the given depth

    void draw(GameObject& to_draw, int depth = 0);
    // REQUIRES: Object exists when render() is called
    // MODIFIES: this, object
    // EFFECTS:  Updates the sprite on the object and draws the
    //           object at the given depth

    sf::RenderTarget* get_render_target();
    // EFFECTS: Returns a pointer to the Render's target

    sf::RenderWindow* get_created_window();
    // EFFECTS: If the Render created a window, it returns a
    //          pointer to it. Otherwise, it returns NULL.

};


#endif

