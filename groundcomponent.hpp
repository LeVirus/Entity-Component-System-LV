#ifndef GROUNDCOMPONENT_HPP
#define GROUNDCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "vector2D.hpp"

/**
 * @brief La structure GroundComponent détermine les caractéristiques d'une entité concernant le sol.
 */
struct GroundComponent : public Component{
    unsigned int muiGroundAssociate;
    Vector2D mvect2dCurrentPointColGround, mvect2dPreviousPointColGround;
    bool mbInit, mbOnTheGround;

    /**
     * @brief PhysicComponent Constructeur de PhysicComponent.
     * Initialisation de la variable muiTypeBehavior.
     */
    GroundComponent(){
        muiTypeComponent = PHYSIC_COMPONENT;
        mbInit = false;
        mbOnTheGround = false;
        mvect2dCurrentPointColGround . mfX = 0;
        mvect2dCurrentPointColGround . mfY = 0;
        mvect2dPreviousPointColGround . mfX = 0;
        mvect2dPreviousPointColGround . mfY = 0;
    }

};

#endif // GROUNDCOMPONENT_HPP

