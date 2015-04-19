#ifndef GROUNDCOMPONENT_HPP
#define GROUNDCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "vector2D.hpp"

/**
 * @brief La structure GroundComponent détermine les caractéristiques d'une entité pouvant se déplacer sur le sol.
 */
struct GroundComponent : public Component{
    bool mbInit, mbOnTheGround;
    /**
     * @brief GroundComponent Constructeur de GroundComponent.
     */
    GroundComponent(){
        muiTypeComponent = GROUND_COMPONENT;
        mbOnTheGround = false;
    }

};

#endif // GROUNDCOMPONENT_HPP

