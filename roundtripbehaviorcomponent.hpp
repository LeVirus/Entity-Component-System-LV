#ifndef ROUNDTRIPBEHAVIORCOMPONENT_HPP
#define ROUNDTRIPBEHAVIORCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "vector2D.hpp"


namespace ecs
{

/**
 * @brief La structure RoundTripBehaviorComponent comporte les variables nécessaires pour le comportement ROUND_TRIP.
 * Le composant doit correspondre à son numéro de comportement ( BehaviorComponent . muiTypeComponent ).
 *
 * mfDestinationDirection :: Angle sur lequel le composant va effectuer ses aller-retours (origine --> destination).
 * mfTravelsLenght :: Longueur sur laquelle le composant va se déplacer.
 * mvect2DPositionOriginTravels :: Coordonnées de l'origine du parcour.
 * mvect2DPositionDestinationTravels :: Coordonnées de la destination du parcour.
 * mbCustomVarA true = sens point origine ==> point destination, false = sens point destination ==> point origine.
 *
 * L'origine du parcour sera définis par les valeurs présentes dans le composant position(supposé initialisé).
 * La destination sera calculé dans initMoveableRoundTrip de la classe IASystem.
 */
struct RoundTripBehaviorComponent : public Component{
    float mfDestinationDirection, mfTravelsLenght;
    Vector2D mvect2DPositionOriginTravels, mvect2DPositionDestinationTravels;
    bool mbTowardDirection;

    RoundTripBehaviorComponent(){
        mbTowardDirection = true;
        mfDestinationDirection = 0;
        mfTravelsLenght = 30;
    }
    void displayComponent()const override{


    }
};

}//fin namespace
#endif // ROUNDTRIPBEHAVIORCOMPONENT_HPP

