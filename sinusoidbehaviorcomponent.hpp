#ifndef SINUSOIDBEHAVIORCOMPONENT_HPP
#define SINUSOIDBEHAVIORCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "vector2D.hpp"

/**
 * @brief La structure SinusoidBehaviorComponent comporte les variables nécessaires pour le comportement SINUSOIDAL.
 * Le composant doit correspondre à son numéro de comportement ( BehaviorComponent . muiTypeComponent ).
 *
 * mfDirectionAxisSinusoid :: Direction de l'axe de la sinusoide(en degré).
 * mfAmplitudeSinusoid :: Représente l'amplitude de la sinusoide.
 * mvect2DCurrentPositionSinusoidAxis :: Coordonnées du point actuel de la droite d'origine de la sinusoide
 * (valeur de l'abscisse de la sinusoide pour sin(0)).
 * mfCurrentAngleSinusoid :: Mémorisation de l'angle(en degré) en fonction duquel l'abscisse et l'ordonnée seront
 * déterminées(fonction sinusoidale).
 */
struct SinusoidBehaviorComponent : public Component{
    float mfDirectionAxisSinusoid, mfAmplitudeSinusoid, mfCurrentAngleSinusoid;
    Vector2D mvect2DCurrentPositionSinusoidAxis;

    SinusoidBehaviorComponent(){
        mfDirectionAxisSinusoid = 180;
        mfAmplitudeSinusoid = 20;
        mfCurrentAngleSinusoid = 0;
    }
};

#endif // SINUSOIDBEHAVIORCOMPONENT_HPP

