#ifndef MOVEABLECOMPONENT_HPP
#define MOVEABLECOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include <vector>

/**
 * @brief La structure MoveableComponent possède les caractéristiques liée aux déplacements d'une entité.
 * muiCustumVar sert à stocker des valeurs qui seront utilisés ou non en fonction du besoin.
 *
 * Si BehaviorComponent -> muiTypeBehavior == SINUSOIDAL
 * Avant l'initialisation dans IASystem::
 * mVectFCustumVar[ 0 ] :: Mémorisation de l'angle (degré) en fonction duquel la position ordonnée sera déterminée(fonction sinus)
 * mVectFCustumVar[ 1 ] :: représente le parcourt vertical maximal que doit parcourir la sinusoide de moitié
 * (à partir de l'origine'entité mVectFCustumVar[ 1 ]).
 * mVectFCustumVar[ 2 ] ::  L'ordonnée d'origine de l'entité.
 * mbCustomVarC Direction true == GAUCHE, false == DROITE
 */
struct MoveableComponent : public Component{
    bool mbMoveUpToDate;
    std::vector< float > mVectFCustumVar;
    float mfVelocite;
    bool mbCustomVarA;

    /**
     * @brief DisplayComponent Constructeur de MoveableComponent.
     * Initialisation des variables à des valeurs par défaut.
     */
    MoveableComponent(){
        muiTypeComponent = MOVEABLE_COMPONENT;
        mbMoveUpToDate = false;
        mfVelocite = 0;
        mVectFCustumVar . resize( 2 );
        mVectFCustumVar[ 0 ] = 0;
        mVectFCustumVar[ 1 ] = 0;
        mbCustomVarA = true;
    }

    /**
     * @brief displayComponent Affichage des valeurs des variables contenues dans MoveableComponent.
     */
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "\n mfVelocite" << mfVelocite << "\n";
    }
};

#endif // MOVEABLECOMPONENT_HPP

