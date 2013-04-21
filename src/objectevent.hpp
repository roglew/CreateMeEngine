#ifndef __OBJECTEVENT_HPP__
#define __OBJECTEVENT_HPP__

template <class T>
struct ObjectEvent
{
	bool* trigger;
	void (*response)(T);
};

#endif

