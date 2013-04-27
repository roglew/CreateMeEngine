#ifndef __OBJECTEVENT_H__
#define __OBJECTEVENT_H__

class ResponseInfo
{
	public:
		virtual ~ResponseInfo()
		{
		};
};

class ObjectEvent
{
	private:
		bool* trigger;
		void (*response)(ResponseInfo*);

	public:
		ObjectEvent();
		ObjectEvent(bool* trigger, void (*new_response)(ResponseInfo*));
		// Creates an instance of an ObjectEvent that points to the given
		// bool and associates it with the given response


		void set_trigger(bool* trigger);
		// MODIFIES: this
		// EFFECTS:  Sets the event trigger to a new bool

		bool* get_trigger();
		// EFFFECTS: Returns the pointer to the bool that triggers this event

		void set_response(void (*response)(ResponseInfo*));
		// MODIFIES: this
		// EFFECTS:  Sets the event response to a new function

		void set(bool*, void (*response)(ResponseInfo*));
		// MODIFIES: this
		// EFFECTS:  Sets both the trigger and the response of the event

		void process(ResponseInfo*);
		// EFFECTS: Checks if the value pointed to by the trigger is true.
		//          If it is, it executes response() with the same argument
		//          as process()
		
};

#endif

