#ifndef MOVEABLECOMPONENT_HPP
#define MOVEABLECOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La structure MoveableComponent possède les caractéristiques liée aux déplacements d'une entité.
 * muiCustumVar sert à stocker des valeurs qui seront utilisés ou non en fonction du besoin.
 */
struct MoveableComponent : public Component{
    unsigned int muiTypeComportement, muiVelocite, muiCustomVarA, muiCustomVarB;

    /**
     * @brief DisplayComponent Constructeur de MoveableComponent.
     * Initialisation des variables à des valeurs par défaut.
     */
    DisplayComponent(){
        muiTypeComponent = MOVEABLE_COMPONENT;
        muiTypeComportement = 0;
        muiVelocite = 0;
        muiCustomVarA = 0;
        muiCustomVarB = 0;
    }

    /**
     * @brief displayComponent Affichage des valeurs des variables contenues dans MoveableComponent.
     */
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "muiTypeComportement::" << muiTypeComportement << "\n muiVelocite" << muiVelocite << "\n"
                  << "muiCustomVarA::" << muiCustomVarA << "\n muiCustomVarB" << muiCustomVarB << "\n";
    }
};

#endif // MOVEABLECOMPONENT_HPP

