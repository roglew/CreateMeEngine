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
  /*
  // Just bounding boxes for now
  const std::vector< sf::Rect<int> > *bboxes = &collision.bounding_box;

  // Store iterator data
  std::vector< sf::Rect<int> >::iterator it1;
  std::vector< sf::Rect<int> >::iterator itbegin;
  std::vector< sf::Rect<int> >::iterator itend;
  itbegin = collision.bounding_box.begin();
  itend = collision.bounding_box.end();

  // Loop through our bounding boxes
  for (it1 = itbegin; it1 != itend; it1++)
  {
    // Other sprite's bounding box data
    std::vector< sf::Rect<int> >::iterator it2;
    std::vector< sf::Rect<int> >::iterator itbegin2;
    std::vector< sf::Rect<int> >::iterator itend2;
    itbegin2 = other_sprite.collision.bounding_box.begin();
    itend2 = other_sprite.collision.bounding_box.end();

    // Iterate through the other sprite's bounding boxes
    for (it2 = itbegin2; it2 != itend2; it2++)
    {

    }
  }
  */
  return false;
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

