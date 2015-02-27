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
 * mfCustomVarA //
 * mfCustomVarB représente le parcourt vertical que doit parcourir la sinusoide à partir de l'origine.
 * mbCustomVarC true == HAUT, false == BAS
 * mbCustomVarD true == GAUCHE, false == DROITE
 */
struct MoveableComponent : public Component{
    bool mbMoveUpToDate;
    std::vector< float > mVectFCustumVar;
    float mfVelocite;
    bool mbCustomVarC, mbCustomVarD;

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
        mbCustomVarC = true;
        mbCustomVarD = true;
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

