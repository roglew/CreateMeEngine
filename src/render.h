#ifndef __RENDER_H__
#define __RENDER_H__

enum DrawEventId{DRAW_OBJECT, DRAW_SPRITE}

struct DrawEvent
{
	DrawEventId id;
	int depth;
	double x;
	double y;
	sf::Sprite* sprite;
}


class Render
{
	private:
		vector<DrawEvent> draw_queue;

		void queue_draw_event(DrawEvent);
		// Adds a draw event to the queue

	public:
		void render(sf::RenderWindow);
		// MODIFIES: RenderWindow
		// EFFECTS:  Draws everything in the draw queue to the window

		void clear_queue();
		// MODIFIES: this
		// EFFECTS:  Clears the draw queue

		void clear(sf::Color = sf::Color::Black, depth = 9999999999);
		// MODIFIES: this
		// EFFECTS:  clears the screen at the given depth

		void draw_sprite(sf::Sprite*, depth = 0);
		// MODIFIES: this
		// EFFECTS:  Draws the sprite at the given depth

};


#endif

