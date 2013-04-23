#ifndef __OBJECTEVENT_HPP__
#define __OBJECTEVENT_HPP__

class ObjectEvent
{
	private:
		bool* trigger;
		void (*response)();

	public:
		ObjectEvent();
		ObjectEvent(bool* trigger, void (*new_response)());
		// Creates an instance of an ObjectEvent that points to the given
		// bool and associates it with the given response


		void set_trigger(bool* trigger);
		// MODIFIES: this
		// EFFECTS:  Sets the event trigger to a new bool

		void set_response(void (*response)());
		// MODIFIES: this
		// EFFECTS:  Sets the event response to a new function

		void set(bool*, void (*response)());
		// MODIFIES: this
		// EFFECTS:  Sets both the trigger and the response of the event

		void process();
		// EFFECTS: Checks if the value pointed to by the trigger is true.
		//          If it is, it executes response() with the same argument
		//          as process()
		
};

#endif

