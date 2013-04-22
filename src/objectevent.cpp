#ifndef __OBJECTEVENT_HPP__
#include "objectevent.hpp"
#endif

// Normal event
ObjectEvent::ObjectEvent()
{
	
}

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

// Response with argument
template <class T>
ObjectEventArg<T>::ObjectEventArg(bool* new_trigger, void (*new_response)(T))
{
	trigger = new_trigger;
	arg_response = new_response;
}

template <class T>
void ObjectEventArg<T>::set_response(void (*new_response)(T))
{
	arg_response = new_response;
}

template <class T>
void ObjectEventArg<T>::set(bool* new_trigger, void (*new_response)(T))
{
	trigger = new_trigger;
	arg_response = new_response;
}

template <class T>
void ObjectEventArg<T>::process(T arg)
{
	if (*trigger)
		arg_response(arg);
}

