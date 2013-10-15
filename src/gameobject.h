#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "vector.hpp"
#include "sprite.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <vector>

class GameObject
{
  protected:
    //GameObjectId id;
    unsigned int instance_id;

    std::vector< std::vector<Sprite*> > animations;
    int current_animation, current_frame;
    int depth;

    Vector2<int> position;
    Vector2<int> velocity;
    Vector2<int> acceleration;

  public:
    /////////////////////////////////
    // Constructors and destructors
    GameObject(id);
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

    virtual void process_events(Game *game);
    // EFFECTS: Processes the events of the object

    void remove_event(bool*);
    // EFFECTS: Removes any registered events that point to the given pointer

    /////////////////////////////
    // Sprite/Animation Methods

    void append_frame(int animation, Sprite* sprite);
    // REQUIRES: That the animation exists
    // MODIFIES: This
    // EFFECTS:  Adds a frame to the end of the given animation

    void add_frame(int animation, Sprite* sprite, int n);
    // REQUIRES: That the animation exists
    // MODIFIES: This
    // EFFECTS:  Inserts a frame into the given animation at the given
    //           position
    
    int add_animation();
    // MODIFIES: This
    // EFFECTS:  Creates an animation and returns the number that is used
    //           to reference. It starts at 0 and increments by 1 for every
    //           additional animation. If you add animations in order,
    //           you can use enums to reference animations

    void next_frame();
    // MODIFIES: This
    // EFFECTS:  Changes sprite to the next frame in the current animation.
    //           If the end of the animation is reached, sprite changes
    //           to the first frame of the animation

    void set_frame(int n);
    // MODIFIES: This
    // EFFECTS:  Sets the sprite to the nth frame of the current animation

    void set_animation(int animation);
    // MODIFIES: This
    // EFFECTS:  Sets the current animation and changes to the first frame

    Sprite* get_current_frame();
    // EFFECTS: Returns a pointer to a Sprite that represents the current
    //          frame of the current animation

    Sprite* get_frame(int n);
    // EFFECTS: Returns a pointer to the Sprite that represents the
    //          nth frame of the current animation

    Sprite* get_frame(int animation, int n);
    // EFFECTS: Returns the nth frame of the given animation

    void update_sprite();
    // MODIFIES: Sprite pointed to by sprite
    // EFFECTS:  Adjusts the sprite to match the object

};

#endif

