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

void Render::construct(double width, double height, std::string title)
{
  // Set our render target to a window
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(width, height, 32),
                                                  title.c_str());
  window->setFramerateLimit(60);

  // Add a view to the render window
  view = new sf::View();
  view->reset(sf::FloatRect(0, 0, width, height));
  window->setView(*view);
  printf("init view is at (%f, %f) with a size of (%f, %f)\n",
         view->getCenter().x, view->getCenter().y,
         view->getSize().x, view->getSize().y);
  
  render_window = window;
}

// Public functions

Render::Render()
{
  construct(640, 480, "");
}

Render::Render(double width, double height, std::string title)
{
  construct(width, height, title);
}

Render::~Render()
{
  delete render_window;
  render_window = NULL;
}

void Render::render()
{
  // Resize the view
  fit_view_to_window();
  
  // Sort the queue from highest depth to lowest
  sort(draw_queue.rbegin(), draw_queue.rend());

  // Set the view
  render_window->setView(*view);

  // Iterate through the queue and draw all the objects
  for (unsigned int i=0; i<draw_queue.size(); i++)
  {
    switch(draw_queue[i].id)
    {
      case DRAW_DRAWABLE:
        render_window->draw(*draw_queue[i].drawable);
      break;

      case DRAW_CLEAR:
        render_window->clear(draw_queue[i].color);
      break;

      default:
      break;
    }
  }

  render_window->display();

  clear_queue();
}

sf::View* Render::get_view()
{
  return view;
}

void Render::fit_view_to_window()
{
  sf::Vector2u wsize = render_window->getSize();
  view->setSize(sf::Vector2f(wsize.x, wsize.y));
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

sf::RenderWindow* Render::get_render_window()
{
  return render_window;
}

