#ifndef GROUNDCOMPONENT_HPP
#define GROUNDCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La structure GroundComponent détermine les caractéristiques d'une entité concernant le sol.
 */
struct GroundComponent : public Component{
    unsigned int muiGroundAssociate;
    float mfGroundCollisionPositionX, mfGroundCollisionPositionY;
    bool mbInit, mbOnTheGround;

    /**
     * @brief PhysicComponent Constructeur de PhysicComponent.
     * Initialisation de la variable muiTypeBehavior.
     */
    GroundComponent(){
        muiTypeComponent = PHYSIC_COMPONENT;
        mbInit = false;
        mfGroundCollisionPositionX = 0;
        mfGroundCollisionPositionY = 0;
    }

};

#endif // GROUNDCOMPONENT_HPP

