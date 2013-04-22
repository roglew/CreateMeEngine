#include "gameobject.h"
#include "ids.h"
#include "objectevent.hpp"
#include "sprite.h"
#include "vector.hpp"
#include <SFML/Graphics.hpp>
#include <vector>


/////////////////////
// Movement methods

template <class T>
void set_position(Vector2<T>);
void set_position(double x, double y);
// MODIFIES: Position
// EFFECTS:  Sets the position of the object

template <class T>
void move(Vector2<T>);
void move(double x, double y);
// MODIFIES: Position
// EFFECTS:  Moves the object by the given vector

template <class T>
void set_velocity(Vector2<T>);
void set_velocity(double x, double y);
// MODIFIES: Velocity
// EFFECTS:  Sets the velocity of the object

template <class T>
void add_velocity(Vector2<T>);
void add_velocity(float x, float y);
// MODIFIES: Velocity
// EFFECTS:  Adds to the velocity of the object

template <class T>
void set_acceleration(Vector2<T>);
void set_acceleration(float x, float y);
// MODIFIES: Acceleration
// EFFECTS:  Sets the acceleration of the object

template <class T>
void add_acceleration(Vector2<T>);
void add_acceleration(float x, float y);
// MODIFIES: Acceleration
// EFFECTS:  Adds to the acceleration of the object


//////////////////
// Event Methods

template <class T=bool>
void register_event(bool*, void (*response(T)))
{
	
}

void register_event(bool*, void (*response()))
{
	
}


template <class T=bool>
void process_events(T)
{
	
}

void process_events()
{
	
}


void remove_event(bool*)
{
	
}


/////////////////////////////
// Sprite/Animation Methods

void append_frame(int animation, Sprite* sprite)
{
	
}


void add_frame(int animation, Sprite* sprite, int n)
{
	
}


int add_animation()
{
	
}


void next_frame()
{
	
}


void set_frame(int n)
{
	
}


void set_animation(int animation)
{
	
}


Sprite* get_current_frame()
{
	
}


Sprite* get_frame(int n)
{
	
}


Sprite* get_frame(int animation, int n)
{
	
}


