#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "engine_classes.h"
#include "game.h"
#include "vector.hpp"
#include "sprite.h"
#include "animation.h"
#include <SFML/Graphics.hpp>
#include <vector>

// Since Game and GameObject depend on each other
class Game;

class GameObject
{
  protected:
    Game *game;
    unsigned int instance_id;

    Animation* animation;
    int current_frame;
    int depth;

    Vector2<int> position;
    Vector2<int> velocity;
    Vector2<int> acceleration;

  public:
    /////////////////////////////////
    // Constructors and destructors
    GameObject(Game* game);
    ~GameObject();

    /////////////////////
    // Instance methods
    unsigned int get_id();
    // EFFECTS: Returns this object's instance id

    /////////////////////
    // Movement methods

    void set_position(const Vector2<int>& set_to);
    void set_position(int x, int y);
    // MODIFIES: Position
    // EFFECTS:  Sets the position of the object

    void move(const Vector2<int>& move_vector);
    void move(int x, int y);
    // MODIFIES: Position
    // EFFECTS:  Moves the object by the given vector

    void set_velocity(const Vector2<int>& velocity_vector);
    void set_velocity(int x, int y);
    // MODIFIES: Velocity
    // EFFECTS:  Sets the velocity of the object

    void add_velocity(const Vector2<int>& velocity_vector);
    void add_velocity(int x, int y);
    // MODIFIES: Velocity
    // EFFECTS:  Adds to the velocity of the object

    void set_acceleration(const Vector2<int>& acceleration_vector);
    void set_acceleration(int x, int y);
    // MODIFIES: Acceleration
    // EFFECTS:  Sets the acceleration of the object

    void add_acceleration(const Vector2<int>& acceleration_vector);
    void add_acceleration(int x, int y);
    // MODIFIES: Acceleration
    // EFFECTS:  Adds to the acceleration of the object

    Vector2<int> get_position();

    //////////////////
    // Event Methods

    virtual void process_events();
    // EFFECTS: Processes the events of the object

    void remove_event(bool*);
    // EFFECTS: Removes any registered events that point to the given pointer

    /////////////////////////////
    // Sprite/Animation Methods

    void next_frame();
    // MODIFIES: This
    // EFFECTS:  Changes sprite to the next frame in the current animation.
    //           If the end of the animation is reached, sprite changes
    //           to the first frame of the animation

    void set_frame(int n);
    // MODIFIES: This
    // EFFECTS:  Sets the sprite to the nth frame of the current animation

    void set_animation(Animation* animation);
    // MODIFIES: This
    // EFFECTS:  Sets the current animation and changes to the first frame

    Sprite* get_current_frame();
    // EFFECTS: Returns a pointer to a Sprite that represents the current
    //          frame of the current animation

    Animation* get_animation();
    // EFFECTS: Returns a pointer to the current animation
    
    Sprite* get_frame(int n);
    // EFFECTS: Returns a pointer to the Sprite that represents the
    //          nth frame of the current animation

    void update_sprite();
    // MODIFIES: Sprite pointed to by sprite
    // EFFECTS:  Adjusts the sprite to match the object

};

#endif

