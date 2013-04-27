#include "objectevent.h"

ObjectEvent::ObjectEvent(bool* new_trigger, void (*new_response)(ResponseInfo*))
{
	trigger = new_trigger;
	response = new_response;
}

void ObjectEvent::set_trigger(bool* new_trigger)
{
	trigger = new_trigger;
}

bool* ObjectEvent::get_trigger()
{
	return trigger;
}


void ObjectEvent::set_response(void (*new_response)(ResponseInfo*))
{
	response = new_response;
}

void ObjectEvent::set(bool* new_trigger, void (*new_response)(ResponseInfo*))
{
	trigger = new_trigger;
	response = new_response;
}


void ObjectEvent::process(ResponseInfo* info)
{
	if (*trigger)
		response(info);
}

