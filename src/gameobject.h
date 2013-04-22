#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "ids.h"
#include "objectevent.hpp"
#include <SFML/system.hpp>
#include <vector>

class GameObject
{
	protected:
		GameObjectId id;
		vector<ObjectEvent> events;
		int depth;

		Vector2<double> position;
		Vector2f velocity;
		float mass;

	public:
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

};

#endif

