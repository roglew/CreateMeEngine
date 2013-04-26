#ifndef __OBJECTEVENT_H__
#define __OBJECTEVENT_H__

#include "gameobject.h"

class GameObject;

class ObjectEvent
{
	private:
		bool* trigger;
		void (*response)(GameObject*);

	public:
		ObjectEvent();
		ObjectEvent(bool* trigger, void (*new_response)(GameObject*));
		// Creates an instance of an ObjectEvent that points to the given
		// bool and associates it with the given response


		void set_trigger(bool* trigger);
		// MODIFIES: this
		// EFFECTS:  Sets the event trigger to a new bool

		bool* get_trigger();
		// EFFFECTS: Returns the pointer to the bool that triggers this event

		void set_response(void (*response)(GameObject*));
		// MODIFIES: this
		// EFFECTS:  Sets the event response to a new function

		void set(bool*, void (*response)(GameObject*));
		// MODIFIES: this
		// EFFECTS:  Sets both the trigger and the response of the event

		void process(GameObject*);
		// EFFECTS: Checks if the value pointed to by the trigger is true.
		//          If it is, it executes response() with the same argument
		//          as process()
		
};

#endif

