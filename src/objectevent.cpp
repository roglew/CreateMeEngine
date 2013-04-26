#include "objectevent.h"

ObjectEvent::ObjectEvent(bool* new_trigger, void (*new_response)(GameObject*))
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


void ObjectEvent::set_response(void (*new_response)(GameObject*))
{
	response = new_response;
}

void ObjectEvent::set(bool* new_trigger, void (*new_response)(GameObject*))
{
	trigger = new_trigger;
	response = new_response;
}


void ObjectEvent::process(GameObject* obj)
{
	if (*trigger)
		response(obj);
}

