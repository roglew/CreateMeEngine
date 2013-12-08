#include "gameobject.h"
#include "sprite.h"
#include "vector.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

/////////////////////////////
// Constructors/destructors
GameObject::GameObject(Game* game)
{
  this->game  = game;
  instance_id = game->get_object_manager()->add_object(this);
}

GameObject::~GameObject()
{
  // When the object dies, remove it from the list
  this->game->get_object_manager()->destroy_object(this->instance_id);
}

/////////////////////
// Instance methods
unsigned int GameObject::get_id()
{
  return this->instance_id;
}


/////////////////////
// Movement methods

void GameObject::set_position(const Vector2<int>& set_to)
{
  position = set_to;
}

void GameObject::set_position(int x, int y)
{
  position.x = x;
  position.y = y;
}


void GameObject::move(const Vector2<int>& move_vector)
{
  position += move_vector;
}

void GameObject::move(int x, int y)
{
  position.x += x;
  position.y += y;
}


void GameObject::set_velocity(const Vector2<int>& velocity_vector)
{
  velocity = velocity_vector;
}

void GameObject::set_velocity(int x, int y)
{
  velocity.x = x;
  velocity.y = y;
}


void GameObject::add_velocity(const Vector2<int>& velocity_vector)
{
  velocity += velocity_vector;
}

void GameObject::add_velocity(int x, int y)
{
  velocity.x += x;
  velocity.y += y;
}


void GameObject::set_acceleration(const Vector2<int>& acceleration_vector)
{
  acceleration = acceleration_vector;
}

void GameObject::set_acceleration(int x, int y)
{
  acceleration.x = x;
  acceleration.y = y;
}


void GameObject::add_acceleration(const Vector2<int>& acceleration_vector)
{
  acceleration += acceleration_vector;
}

void GameObject::add_acceleration(int x, int y)
{
  acceleration.x += x;
  acceleration.y += y;
}


Vector2<int> GameObject::get_position()
{
  return position;
}


//////////////////
// Event Methods

void GameObject::process_events()
{
  // so it doesn't shit itself if we don't define events
}

/////////////////////////////
// Sprite/Animation Methods

void GameObject::next_frame()
{
  // Go to the next frame
  this->current_frame++;

  // Loop back to the first frame if we've reached the end of the animation
  if (this->current_frame >= this->animation->size())
    this->current_frame = 0;
}


void GameObject::set_frame(int n)
{
  this->current_frame = n;
}


void GameObject::set_animation(Animation* animation)
{
  this->animation = animation;
}


Sprite* GameObject::get_current_frame()
{
  return this->animation->get_frame(this->current_frame);
}


Sprite* GameObject::get_frame(int n)
{
  return this->animation->get_frame(n);
}

void GameObject::update_sprite()
{
  get_current_frame()->setPosition(position.x, position.y);
}

