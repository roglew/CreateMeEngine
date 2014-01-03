#include "render.h"
#include "gameobject.h"
#include "sprite.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

// Private functions
void Render::queue_draw_event(DrawEvent event)
{
  draw_queue.push_back(event);
}

void Render::clear_queue()
{
  draw_queue.clear();
}

void Render::construct(int width, int height, std::string title)
{
  // Set our render target to a window
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(width, height, 32),
                                                  title.c_str());
  window->setFramerateLimit(60);
  owns_render_target = true;

  // Add a view to the render window
  view = new sf::View(sf::FloatRect(0, 0, width, height));
  window->setView(*view);
  
  render_target = window;
  
}

// Public functions

Render::Render()
{
  construct(640, 480, "");
}

Render::Render(int width, int height, std::string title)
{
  construct(width, height, title);
}

Render::Render(sf::RenderTarget& target)
{
  owns_render_target = false;
  render_target = &target;
}

Render::~Render()
{
  if (owns_render_target)
  {
    delete render_target;
    render_target = NULL;
  }
}

void Render::render()
{
  // Sort the queue from highest depth to lowest
  sort(draw_queue.rbegin(), draw_queue.rend());

  // Iterate through the queue and draw all the objects
  for (unsigned int i=0; i<draw_queue.size(); i++)
  {
    switch(draw_queue[i].id)
    {
      case DRAW_DRAWABLE:
        render_target->draw(*draw_queue[i].drawable);
      break;

      case DRAW_CLEAR:
        render_target->clear(draw_queue[i].color);
      break;

      default:
      break;
    }
  }

  if (owns_render_target)
    static_cast<sf::RenderWindow*>(render_target)->display();

  clear_queue();
}


void Render::clear(sf::Color color, int depth)
{
  DrawEvent event;
  event.id = DRAW_CLEAR;
  event.depth = depth;
  event.color = color;

  draw_queue.push_back(event);
}

void Render::draw(const sf::Drawable& drawable, int depth)
{
  DrawEvent event;

  event.id = DRAW_DRAWABLE;
  event.depth = depth;
  event.drawable = &drawable;

  draw_queue.push_back(event);
}

void Render::draw(GameObject& object, int depth)
{
  if (object.get_animation())
  {
    DrawEvent event;

    event.id = DRAW_DRAWABLE;
    event.depth = depth;
    event.drawable = object.get_current_frame();

    object.update_sprite();

    draw_queue.push_back(event);
  }
}

sf::RenderTarget* Render::get_render_target()
{
  return render_target;
}

sf::RenderWindow* Render::get_created_window()
{
  if (owns_render_target)
    return static_cast<sf::RenderWindow*>(render_target);
  else
    return NULL;
}

