#include "render.h"
#include <SFML/Graphics.hpp>
#include <iostream>

static bool draw_event_lt(DrawEvent de1, DrawEvent de2)
{
	return (de1.depth < de2.depth);
}

// Private functions
void Render::queue_draw_event(DrawEvent event)
{
	draw_queue.push_back(event);
}

void Render::clear_queue()
{
	draw_queue.clear();
}

// Public functions
Render::Render(sf::RenderTarget& target)
{
	render_target = &target;
}

void Render::render()
{
	// Sort the queue from highest depth to lowest
	sort(draw_queue.rbegin(), draw_queue.rend());

	// Iterate through the queue and draw all the objects
	for (int i=0; i<draw_queue.size(); i++)
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
	DrawEvent event;

	event.id = DRAW_DRAWABLE;
	event.depth = depth;
	event.drawable = object.get_current_frame().get_sfml_sprite();

	object.update_sprite();

	draw_queue.push_back(event);
}

