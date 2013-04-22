#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "ids.h"
#include "objectevent.hpp"
#include "sprite.h"
#include "vector.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class GameObject
{
	protected:
		GameObjectId id;
		int instance_id;
		std::vector<ObjectEvent<> > events;

		std::vector< std::vector<Sprite> > animations;
		int depth;

		Vector2<double> position;
		Vector2<float> velocity;
		Vector2<float> acceleration;

	public:
		/////////////////////
		// Movement methods

		template <class T>
		void set_position(Vector2<T>);
		void set_position(double x, double y);
		// MODIFIES: Position
		// EFFECTS:  Sets the position of the object

		template <class T>
		void move(Vector2<T>);
		void move(double x, double y);
		// MODIFIES: Position
		// EFFECTS:  Moves the object by the given vector

		template <class T>
		void set_velocity(Vector2<T>);
		void set_velocity(double x, double y);
		// MODIFIES: Velocity
		// EFFECTS:  Sets the velocity of the object

		template <class T>
		void add_velocity(Vector2<T>);
		void add_velocity(float x, float y);
		// MODIFIES: Velocity
		// EFFECTS:  Adds to the velocity of the object

		template <class T>
		void set_acceleration(Vector2<T>);
		void set_acceleration(float x, float y);
		// MODIFIES: Acceleration
		// EFFECTS:  Sets the acceleration of the object

		template <class T>
		void add_acceleration(Vector2<T>);
		void add_acceleration(float x, float y);
		// MODIFIES: Acceleration
		// EFFECTS:  Adds to the acceleration of the object

		//////////////////
		// Event Methods

		template <class T=bool>
		void register_event(bool*, void (*response(T)));
		void register_event(bool*, void (*response()));
		// REQUIRES: bool* is not null, response function exists for the duration
		//           of the object
		// MODIFIES: This
		// EFFECTS:  Adds an event that the object will respond to. When
		//           obj.process_events()/process_events(T) is called,
		//           if bool* points to true, response()/response(T) is called.

		template <class T=bool>
		void process_events(T);
		void process_events();
		// REQUIRES: Only valid events are registered
		// EFFECTS:  Any registered events currently pointing to a true bool
		//           will have their response functions called

		void remove_event(bool*);
		// EFFECTS: Removes any registered events that point to the given pointer

		/////////////////////////////
		// Sprite/Animation Methods

		void append_frame(int animation, Sprite* sprite);
		// REQUIRES: That the animation exists
		// MODIFIES: This
		// EFFECTS:  Adds a frame to the end of the given animation

		void add_frame(int animation, Sprite* sprite, int n);
		// REQUIRES: That the animation exists
		// MODIFIES: This
		// EFFECTS:  Inserts a frame into the given animation at the given
		//           position
		
		int add_animation();
		// MODIFIES: This
		// EFFECTS:  Creates an animation and returns the number that is used
		//           to reference. It starts at 0 and increments by 1 for every
		//           additional animation. If you add animations in order,
		//           you can use enums to reference animations

		void next_frame();
		// MODIFIES: This
		// EFFECTS:  Changes sprite to the next frame in the current animation.
		//           If the end of the animation is reached, sprite changes
		//           to the first frame of the animation

		void set_frame(int n);
		// MODIFIES: This
		// EFFECTS:  Sets the sprite to the nth frame of the current animation

		void set_animation(int animation);
		// MODIFIES: This
		// EFFECTS:  Sets the current animation and changes to the first frame

		Sprite* get_current_frame();
		// EFFECTS: Returns a pointer to a Sprite that represents the current
		//          frame of the current animation

		Sprite* get_frame(int n);
		// EFFECTS: Returns a pointer to the Sprite that represents the
		//          nth frame of the current animation

		Sprite* get_frame(int animation, int n);
		// EFFECTS: Returns the nth frame of the given animation

};

#endif

