#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP

//Enumération des types de composants
enum{ DISPLAY_COMPONENT, POSITION_COMPONENT, PHYSIC_COMPONENT, MOVEABLE_COMPONENT, BEHAVIOR_COMPONENT, INPUT_COMPONENT,
    GROUND_COMPONENT, RING_BEHAVIOR_COMPONENT, ROUND_TRIP_BEHAVIOR_COMPONENT, SINUSOID_BEHAVIOR_COMPONENT, COLL_SEGMENT_COMPONENT };

//Enumération des types de systemes
enum{ IA_SYSTEM, GRAVITY_SYSTEM, INPUT_SYSTEM, DISPLAY_SYSTEM  };

//Enumération des commandes joueurs
enum{ MOVE_UP, MOVE_LEFT, MOVE_DOWN, MOVE_RIGHT, JUMP, ATTACK };

//Enumération des types de comportements
enum{ UNSPECIFIED, SINUSOIDAL, RING, ROUND_TRIP, TOWARD_PLAYER };

const unsigned int COMPONENT_NOT_FOUND = 1000, SYSTEM_NOT_FOUND = 1001, NUMBR_COMPONENT = 10, NUMBR_SYSTEM = 4, NUMBR_INPUT = 6,
GROUND_UNDEFINED = 1002;

const float PI = 3.14159265358979323846;

#endif // CONSTANTES_HPP
