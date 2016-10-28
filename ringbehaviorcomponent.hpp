#ifndef RINGBEHAVIORCOMPONENT_HPP
#define RINGBEHAVIORCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "vector2D.hpp"


namespace ecs
{

/**
 * @brief La structure RingBehaviorComponent comporte les variables nécessaires pour le comportement RING.
 * Le composant doit correspondre à son numéro de comportement ( BehaviorComponent . muiTypeComponent ).
 *
 * mfRadiusCircle :: Valeur du rayon du cercle.
 * mfCurrentAngle :: Valeur de l'angle actuel(la valeur de la vélocité y est ajoutée a chaque itération).
 * mvect2DRotationCenter :: Coordonnées du centre de rotation.
 * mbTrigonometric :: true = sens trigonométrique, false = sens antitrigonométrique.
 *
 * Le centre de rotation sera définis par les valeurs présentes dans le composant position(supposé initialisé).
 */
struct RingBehaviorComponent : public Component{
    float mfRadiusCircle, mfCurrentAngle;
    Vector2D mvect2DRotationCenter;
    bool mbTrigonometric;

    RingBehaviorComponent(){
        mbTrigonometric = true;
        mfCurrentAngle = 0;
        mfRadiusCircle = 30;
    }
    void displayComponent()const override{


    }
};

}//fin namespace
#endif // RINGBEHAVIORCOMPONENT_HPP

