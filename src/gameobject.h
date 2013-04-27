#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "ids.h"
#include "vector.hpp"
#include "objectevent.h"
#include "sprite.h"
#include <SFML/Graphics.hpp>
#include <vector>

class GameObject;

class GameObjectEventInfo: public ResponseInfo
{
	public:
		GameObject* object;
		GameObjectEventInfo();
		GameObjectEventInfo(GameObject* obj);
};

class GameObject
{
	protected:
		GameObjectId id;
		int instance_id;
		std::vector< ObjectEvent* > events;

		std::vector< std::vector<Sprite*> > animations;
		int current_animation, current_frame;
		int depth;

		Vector2<double> position;
		Vector2<double> velocity;
		Vector2<double> acceleration;

	public:
		/////////////////////////////////
		// Constructors and destructors
		~GameObject();

		/////////////////////
		// Movement methods

		void set_position(const Vector2<double>& set_to);
		void set_position(double x, double y);
		// MODIFIES: Position
		// EFFECTS:  Sets the position of the object

		void move(const Vector2<double>& move_vector);
		void move(double x, double y);
		// MODIFIES: Position
		// EFFECTS:  Moves the object by the given vector

		void set_velocity(const Vector2<double>& velocity_vector);
		void set_velocity(double x, double y);
		// MODIFIES: Velocity
		// EFFECTS:  Sets the velocity of the object

		void add_velocity(const Vector2<double>& velocity_vector);
		void add_velocity(float x, float y);
		// MODIFIES: Velocity
		// EFFECTS:  Adds to the velocity of the object

		void set_acceleration(const Vector2<double>& acceleration_vector);
		void set_acceleration(float x, float y);
		// MODIFIES: Acceleration
		// EFFECTS:  Sets the acceleration of the object

		void add_acceleration(const Vector2<double>& acceleration_vector);
		void add_acceleration(float x, float y);
		// MODIFIES: Acceleration
		// EFFECTS:  Adds to the acceleration of the object

		Vector2<double> get_position();

		//////////////////
		// Event Methods

		void register_event(bool*, void (*new_response)(ResponseInfo*) );
		// REQUIRES: bool* is not null, response function exists for the duration
		//           of the object
		// MODIFIES: This
		// EFFECTS:  Adds an event that the object will respond to. When
		//           obj.process_events()/process_events(T) is called,
		//           if bool* points to true, response()/response(T) is called.

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

		void update_sprite();
		// MODIFIES: Sprite pointed to by sprite
		// EFFECTS:  Adjusts the sprite to match the object

};

#endif

