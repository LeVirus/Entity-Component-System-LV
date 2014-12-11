#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "component.hpp"

/**
 * @brief La structure PositionComponent représente la position d'une entité.
 * Elle contient l'abscisse et l'ordonnée de l'entité.
 */
struct PositionComponent : public Component{
    float mfPositionX, mfPositionY;
};

#endif // POSITIONCOMPONENT_HPP
