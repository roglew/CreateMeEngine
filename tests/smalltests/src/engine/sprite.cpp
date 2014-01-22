#include "sprite.h"
#include "collision.h"
#include "square.h"
#include <SFML/Graphics.hpp>
#include <vector>

Sprite::Sprite(ResourceManager *resource_manager)
{
  this->resource_manager = resource_manager;
  this->loaded = false;
  this->image_defined = false;
}

Sprite::~Sprite()
{
  // do nothing
}

bool Sprite::collides(Sprite& other_sprite)
{
  return ::collides(this->collision, other_sprite.collision);
}

void Sprite::set_image(ResourceImage image)
{
  this->image         = image;
  this->image_defined = true;
  this->is_part       = false;
}

void Sprite::set_image(ResourceImage image, Square &position)
{
  this->set_image(image, position.x, position.y, position.w, position.h);
}

void Sprite::set_image(ResourceImage image, int x, int y, int w, int h)
{
  this->image         = image;
  this->image_pos.x   = x;
  this->image_pos.y   = y;
  this->image_pos.w   = w;
  this->image_pos.h   = h;
  this->is_part       = true;
  this->image_defined = true;
}

void Sprite::set_position(int x, int y)
{
    this->setPosition(x, y);
    this->collision.x = x;
    this->collision.y = y;
}

int Sprite::get_sprite_width()
{
  return this->image_pos.w;
}

int Sprite::get_sprite_height()
{
  return this->image_pos.h;
}

void Sprite::update_texture()
{
  // Load the texture if we have to
  this->resource_manager->load_texture(this->image);
  sf::Texture *tex = this->resource_manager->get_texture(this->image);
  this->setTexture(*tex);

  // Crop it to a rectangle if we have to
  if (is_part)
  {
    this->setTextureRect(sf::IntRect(image_pos.x, image_pos.y, image_pos.w, image_pos.h));
  }
}

