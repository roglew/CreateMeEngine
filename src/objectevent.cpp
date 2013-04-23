#include "objectevent.hpp"

ObjectEvent::ObjectEvent(bool* new_trigger, void (*new_response)())
{
	trigger = new_trigger;
	response = new_response;
}

void ObjectEvent::set_trigger(bool* new_trigger)
{
	trigger = new_trigger;
}


void ObjectEvent::set_response(void (*new_response)())
{
	response = new_response;
}

void ObjectEvent::set(bool* new_trigger, void (*new_response)())
{
	trigger = new_trigger;
	response = new_response;
}


void ObjectEvent::process()
{
	if (*trigger)
		response();
}

