#ifndef __RENDER_H__
#define __RENDER_H__

#include <SFML/Graphics.hpp>
#include <vector>

enum DrawEventId{DRAW_OBJECT, DRAW_DRAWABLE, DRAW_CLEAR,
	DrawEventIdSize};

struct DrawEvent
{
	DrawEventId id;
	int depth;
	sf::Drawable* drawable;
	sf::Color color;

	bool operator > (const DrawEvent& event)
	{
		return id > event.id;
	}
};

class Render
{
	private:
		std::vector<DrawEvent> draw_queue;
		sf::RenderTarget *render_target;

		void queue_draw_event(DrawEvent);
		// Adds a draw event to the queue

	public:
		Render(sf::RenderTarget*);

		void render(sf::RenderWindow);
		// MODIFIES: RenderWindow
		// EFFECTS:  Draws everything in the draw queue to the window

		void clear_queue();
		// MODIFIES: this
		// EFFECTS:  Clears the draw queue

		void clear(sf::Color = sf::Color::Black, int depth = 9999999999);
		// MODIFIES: this
		// EFFECTS:  clears the screen at the given depth

		void draw(sf::Drawable*, int depth = 0);
		// MODIFIES: this
		// EFFECTS:  Draws the sprite at the given depth

};


#endif

