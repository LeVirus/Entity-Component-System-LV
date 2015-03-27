#ifndef ROUNDTRIPBEHAVIORCOMPONENT_HPP
#define ROUNDTRIPBEHAVIORCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "vector2D.hpp"

/**
 * @brief La structure RingBehaviorComponent comporte les variables nécessaires pour le comportement RING.
 * Le composant doit être instancié ET correspondre à son numéro de comportement ( BehaviorComponent . muiTypeComponent ).
 *
 * mVectFCustumVar[ 0 ] :: Angle sur lequel le composant va effectuer ses aller-retours (origine --> destination).
 * mVectFCustumVar[ 1 ] :: Longueur sur laquelle le composant va se déplacer.
 * mVectFCustumVar[ 2 ] :: Abscisse de l'origine du parcour.
 * mVectFCustumVar[ 3 ] :: Ordonnée de l'origine du parcour.
 * mVectFCustumVar[ 4 ] :: Abscisse de la destination du parcour.
 * mVectFCustumVar[ 5 ] :: Ordonnée de la destination du parcour.
 * mbCustomVarA true = sens point origine ==> point destination, false = sens point destination ==> point origine.
 * L'origine du parcour sera définis par les valeurs présentes dans le composant position(supposé initialisé).
 * La destination sera calculé dans initMoveableRoundTrip de la classe IASystem.
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

#endif // ROUNDTRIPBEHAVIORCOMPONENT_HPP

