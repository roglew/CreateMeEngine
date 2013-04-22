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
void GameObject::set_position(const& Vector2<T> set_to)
{
	position = set_to;
}

void GameObject::set_position(double x, double y)
{
	position.x = x;
	position.y = y;
}


template <class T>
void GameObject::move(const& Vector2<T> move_vector)
{
	position += move_vector;
}

void GameObject::move(double x, double y)
{
	position.x += x;
	position.y += y;
}


template <class T>
void GameObject::set_velocity(Vector2<T> velocity_vector)
{
	velocity = velocity_vector;
}

void GameObject::set_velocity(double x, double y)
{
	velocity.x = x;
	velocity.y = y;
}


template <class T>
void GameObject::add_velocity(Vector2<T> velocity_vector)
{
	velocity += velocity_vector;
}

void GameObject::add_velocity(float x, float y)
{
	velocity.x += x;
	velocity.y += y;
}


template <class T>
void GameObject::set_acceleration(Vector2<T> acceleration_vector)
{
	acceleration = acceleration_vector;
}

void GameObject::set_acceleration(float x, float y)
{
	acceleration.x = x;
	acceleration.y = y;
}


template <class T>
void GameObject::add_acceleration(Vector2<T> acceleration_vector)
{
	acceleration += acceleration_vector;
}

void GameObject::add_acceleration(float x, float y)
{
	acceleration.x += x;
	acceleration.y += y;
}


//////////////////
// Event Methods

template <class T>
void register_event(bool*, void (*response(T)))
{
	
}

void register_event(bool*, void (*response()))
{
	
}


template <class T>
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


