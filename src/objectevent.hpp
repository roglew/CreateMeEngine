#ifndef __OBJECTEVENT_HPP__
#define __OBJECTEVENT_HPP__

class AbstractObjectEvent
{
	public:
		virtual ~AbstractObjectEvent() = 0;
};

template <class T=bool>
class ObjectEvent: AbstractObjectEvent
{
	private:
		bool* trigger;
		void (*response)();
		void (*response_arg)(T);

	public:
		ObjectEvent(bool* trigger, void (*new_response)(T));
		ObjectEvent(bool* trigger, void (*new_response)());
		// Creates an instance of an ObjectEvent that points to the given
		// bool and associates it with the given response


		void set_trigger(bool* trigger);
		// MODIFIES: this
		// EFFECTS:  Sets the event trigger to a new bool

		void set_response(void (*response)(T));
		void set_response(void (*response)());
		// MODIFIES: this
		// EFFECTS:  Sets the event response to a new function

		void set(bool*, void (*response)(T));
		void set(bool*, void (*response)());
		// MODIFIES: this
		// EFFECTS:  Sets both the trigger and the response of the event

		void process(T arg);
		void process();
		// EFFECTS: Checks if the value pointed to by the trigger is true.
		//          If it is, it executes response() with the same argument
		//          as process()
		
};

#include "objectevent.cpp"

#endif

