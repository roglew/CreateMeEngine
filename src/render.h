#ifndef __RENDER_H__
#define __RENDER_H__

#include "gameobject.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

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

		void queue_draw_event(DrawEvent);
		// Adds a draw event to the queue

		void clear_queue();
		// MODIFIES: this
		// EFFECTS:  Clears the draw queue

	public:
		Render(sf::RenderTarget&);

		void render();
		// MODIFIES: RenderWindow
		// EFFECTS:  Draws everything in the draw queue to the window


		void clear(sf::Color = sf::Color::Black, int depth = 99999999);
		// MODIFIES: this
		// EFFECTS:  clears the screen at the given depth

		void draw(const sf::Drawable&, int depth = 0);
		// REQUIRES: Drawable exists when render() is called
		// MODIFIES: this
		// EFFECTS:  Draws the sprite at the given depth

		void draw(GameObject&, int depth = 0);
		// REQUIRES: Object exists when render() is called
		// MODIFIES: this, object
		// EFFECTS:  Updates the sprite on the object and draws the
		//           object at the given depth

};


#endif

