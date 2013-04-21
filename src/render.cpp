#include "render.h"
#include <SFML/Graphics.hpp>

static bool draw_event_lt(DrawEvent de1, DrawEvent de2)
{
	return (de1.depth < de2.depth);
}

// Private functions
void Render::queue_draw_event(DrawEvent event)
{
	draw_queue.push_back(event);
}

// Public functions
Render::Render(sf::RenderTarget* target)
{
	render_target = target;
}

void Render::render(sf::RenderWindow)
{
	// Sort the queue from highest depth to lowest
	sort(draw_queue.begin(), draw_queue.end(), std::greater<int>());

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

}

void Render::clear_queue()
{
	draw_queue.clear();
}

//void clear(sf::Color = sf::Color::Black, depth = 9999999999);

void Render::draw(sf::Drawable* drawable, int depth)
{
	DrawEvent event;

	event.id = DRAW_DRAWABLE;
	event.depth = depth;
	event.drawable = drawable;

	draw_queue.push_back(event);
}

