#ifndef __OBJECTEVENT_HPP__
#include "objectevent.hpp"
#endif

static void NOFUNCTION(){}

template<class T>
static void NOFUNCTION(T){}

// Response with argument
template <class T>
ObjectEvent<T>::ObjectEvent(bool* new_trigger, void (*new_response)(T))
{
	trigger = new_trigger;
	response = NOFUNCTION;
	response_arg = new_response;
}

template <class T>
ObjectEvent<T>::ObjectEvent(bool* new_trigger, void (*new_response)())
{
	trigger = new_trigger;
	response = new_response;
	response_arg = NOFUNCTION;
}

template <class T>
void ObjectEvent<T>::set_trigger(bool* new_trigger)
{
	trigger = new_trigger;
}

template <class T>
void ObjectEvent<T>::set_response(void (*new_response)(T))
{
	response = NOFUNCTION;
	response_arg = new_response;
}

template <class T>
void ObjectEvent<T>::set_response(void (*new_response)())
{
	response = new_response;
	response_arg = NOFUNCTION;
}

template <class T>
void ObjectEvent<T>::set(bool* new_trigger, void (*new_response)(T))
{
	trigger = new_trigger;
	response = new_response;
}

template <class T>
void ObjectEvent<T>::process(T arg)
{
	if (*trigger && response_arg)
		response_arg(arg);
}

template <class T>
void ObjectEvent<T>::process()
{
	if (*trigger && response)
		response();
}

