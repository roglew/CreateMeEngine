#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "ids.h"
#include "objectevent.hpp"
#include <SFML/system.hpp>
#include <vector>

class GameObject
{
	protected:
		GameObjectId id;
		vector<ObjectEvent> events;
		int depth;

		Vector2<double> position;
		Vector2f velocity;
		float mass;

	public:
		void register_event(*bool, void (*response()));

};

#endif

