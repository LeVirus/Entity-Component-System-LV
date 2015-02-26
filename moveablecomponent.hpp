#ifndef MOVEABLECOMPONENT_HPP
#define MOVEABLECOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La structure MoveableComponent possède les caractéristiques liée aux déplacements d'une entité.
 * muiCustumVar sert à stocker des valeurs qui seront utilisés ou non en fonction du besoin.
 */
struct MoveableComponent : public Component{
    bool mbMoveUpToDate;
    unsigned int muiTypeComportement;
    float mfVelocite, mfCustomVarA, mfCustomVarB;

    /**
     * @brief DisplayComponent Constructeur de MoveableComponent.
     * Initialisation des variables à des valeurs par défaut.
     */
    MoveableComponent(){
        muiTypeComponent = MOVEABLE_COMPONENT;
        mbMoveUpToDate = false;
        mfVelocite = 0;
        mfCustomVarA = 0;
        mfCustomVarB = 0;
    }

    /**
     * @brief displayComponent Affichage des valeurs des variables contenues dans MoveableComponent.
     */
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "muiTypeComportement::" << muiTypeComportement << "\n mfVelocite" << mfVelocite << "\n"
                  << "mfCustomVarA::" << mfCustomVarA << "\n mfCustomVarB" << mfCustomVarB << "\n";
    }
};

#endif // MOVEABLECOMPONENT_HPP

