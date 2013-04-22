#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "ids.h"
#include "objectevent.hpp"
#include <vector>

class GameObject
{
	protected:
		GameObjectId id;
		vector<ObjectEvent> events;

		Vector2<double> position;
		Vector2f velocity;
		float mass;

	public:
		

};

#endif

