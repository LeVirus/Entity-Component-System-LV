#ifndef RINGBEHAVIORCOMPONENT_HPP
#define RINGBEHAVIORCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "vector2D.hpp"

/**
 * @brief La structure RingBehaviorComponent comporte les variables nécessaires pour le comportement RING.
 *
 * mVectFCustumVar[ 0 ] :: Valeur du rayon du cercle.
 * mVectFCustumVar[ 1 ] :: Valeur de l'angle actuel(la valeur de la vélocité y est ajoutée a chaque itération).
 * mVectFCustumVar[ 2 ] :: Abscisse du centre de rotation.
 * mVectFCustumVar[ 3 ] :: Ordonnée du centre de rotation.
 * mbCustomVarA true = sens trigonométrique, false = sens antitrigonométrique.
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
};

#endif // RINGBEHAVIORCOMPONENT_HPP

