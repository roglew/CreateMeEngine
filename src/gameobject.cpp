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
  instance_id = game->objects->add_object(this);
}

GameObject::~GameObject()
{
  // When the object dies, remove it from the list
  this->game->objects->destroy_object(this->instance_id);
}

/////////////////////
// Instance methods
unsigned int get_id()
{
  return instance_id;
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

void GameObject::append_frame(int animation, Sprite* sprite)
{
  animations[animation].push_back(sprite);
}


void GameObject::add_frame(int animation, Sprite* sprite, int n)
{
  
}


int GameObject::add_animation()
{
  //OPTIMIZE
  // create and delete the animation vectors
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
  return (animations[current_animation][current_frame]);
}


Sprite* GameObject::get_frame(int n)
{
  
}


Sprite* GameObject::get_frame(int animation, int n)
{
  
}

void GameObject::update_sprite()
{
  get_current_frame()->setPosition(position.x, position.y);
}

