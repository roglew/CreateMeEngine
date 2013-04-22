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

void GameObject::append_frame(int animation, Sprite* sprite)
{
	animations[animation].push_back(sprite);
}


void GameObject::add_frame(int animation, Sprite* sprite, int n)
{
	
}


int GameObject::add_animation()
{
	// Shitty way to add something to the vector, but it will work for now
	std::vector<Sprite*> temp;
	animations.push_back(temp);

	int size;
	size = animations.size();

	// Set a default frame/animation if this is the first animation
	if (size == 1)
	{
		current_animation = 0;
		current_frame = 0;
	}

	return (size-1);
}


void GameObject::next_frame()
{
	// Go to the next frame
	current_frame++;

	// Loop back to the first frame if we've reached the end of the animation
	if (current_frame >= animations[current_animation].size())
		current_frame = 0;
}


void GameObject::set_frame(int n)
{
	current_frame = n;

	int anim_length;
	anim_length = animations[current_animation].size();

	while (current_frame < 0)
		current_frame += anim_length;
	while (current_frame >= anim_length)
		current_frame -= anim_length;
}


void GameObject::set_animation(int animation)
{
	current_animation = animation;
	while (current_animation < 0)
		current_animation++;
	while (current_animation >= animations.size())
		current_animation--;
}


Sprite* GameObject::get_current_frame()
{
	
}


Sprite* GameObject::get_frame(int n)
{
	
}


Sprite* GameObject::get_frame(int animation, int n)
{
	
}


