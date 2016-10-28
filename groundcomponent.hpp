#ifndef GROUNDCOMPONENT_HPP
#define GROUNDCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "segment.hpp"


namespace ecs
{

/**
 * @brief La structure GroundComponent détermine les caractéristiques d'une entité pouvant se déplacer sur le sol.
 */
struct GroundComponent : public Component{
    bool mbInit, mbOnTheGround;
    Segment mCollSegment;
    /**
     * @brief GroundComponent Constructeur de GroundComponent.
     */
    GroundComponent(){
        muiTypeComponent = GROUND_COMPONENT;
        mbOnTheGround = false;
    }
    void displayComponent()const override{


    }
};

}//fin namespace
#endif // GROUNDCOMPONENT_HPP

