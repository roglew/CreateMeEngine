#ifndef __RESOURCE_IDS__
enum ResourceImage: unsigned int;
enum ResourceSound: unsigned int;
enum ResourceMusic: unsigned int;
enum ResourceAnimation: unsigned int;
enum ObjectType: unsigned int;
enum CollisionType: int;

// Arrays defined in resourceids.h
extern const unsigned int PREDEFINED_COLLISION_DATA[];
extern const int PREDEFINED_COLLISION_DATA_LOC[][2];
extern const unsigned int PREDEFINED_COLLISION_DATA_FRAME[];
extern const char ANIMATION_HAS_COLLISION[];
#endif
