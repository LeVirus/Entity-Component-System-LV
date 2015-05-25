#ifndef MOVEABLECOMPONENT_HPP
#define MOVEABLECOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "vector2D.hpp"

/**
 * @brief La structure MoveableComponent possède les caractéristiques liées aux déplacements d'une entité. 
 */
struct MoveableComponent : public Component{
    bool mbMoveUpToDate, mbReactGround, mbReactPhysics;
    float mfVelocite;

    /**
     * @brief DisplayComponent Constructeur de MoveableComponent.
     * Initialisation de la variable muiTypeBehavior.
     * Les conteneurs de variables ;dont l'utilité sera déterminée en fonction du type des classes filles; sont initialisés
     * à des valeurs par défaut.
     */
    MoveableComponent(){
        muiTypeComponent = MOVEABLE_COMPONENT;
        mbMoveUpToDate = false;
        mfVelocite = 10;
    }

    /**
     * @brief displayComponent Fonction dérivée d'affichage des variables de la structure MoveableComponent.
     * La fonction de base d'affichage de la classe mère est appelée en premier lieu.
     */
    void displayComponent()const override{
        //Component::displayComponent();
        std::cout << "\n mfVelocite" << mfVelocite << "\n";
    }
};

#endif // MOVEABLECOMPONENT_HPP

