#include "gameobject.h"
#include "sprite.h"
#include "vector.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

/////////////////////////////
// Constructors/destructors
GameObject::GameObject(Game* game)
{
  this->game          = game;
  instance_id         = game->get_object_manager()->add_object(this);
  this->depth         = 0;
  this->current_frame = 0;
  this->animation     = NULL;
}

GameObject::~GameObject()
{
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
  this->position = set_to;
}

void GameObject::set_position(int x, int y)
{
  this->position.x = x;
  this->position.y = y;
}


void GameObject::move(const Vector2<int>& move_vector)
{
  this->position += move_vector;
}

void GameObject::move(int x, int y)
{
  this->position.x += x;
  this->position.y += y;
}


void GameObject::set_velocity(const Vector2<int>& velocity_vector)
{
  this->velocity = velocity_vector;
}

void GameObject::set_velocity(int x, int y)
{
  this->velocity.x = x;
  this->velocity.y = y;
}


void GameObject::add_velocity(const Vector2<int>& velocity_vector)
{
  this->velocity += velocity_vector;
}

void GameObject::add_velocity(int x, int y)
{
  this->velocity.x += x;
  this->velocity.y += y;
}


void GameObject::set_acceleration(const Vector2<int>& acceleration_vector)
{
  this->acceleration = acceleration_vector;
}

void GameObject::set_acceleration(int x, int y)
{
  this->acceleration.x = x;
  this->acceleration.y = y;
}


void GameObject::add_acceleration(const Vector2<int>& acceleration_vector)
{
  this->acceleration += acceleration_vector;
}

void GameObject::add_acceleration(int x, int y)
{
  this->acceleration.x += x;
  this->acceleration.y += y;
}


Vector2<int> GameObject::get_position()
{
  return this->position;
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

Animation* GameObject::get_animation()
{
  return this->animation;
}

Sprite* GameObject::get_frame(int n)
{
  return this->animation->get_frame(n);
}

int GameObject::get_depth()
{
  return this->depth;
}

void GameObject::set_depth(int dep)
{
  this->depth = dep;
}

void GameObject::update_sprite()
{
  this->get_current_frame()->set_position(position.x, position.y);
}

