#ifndef DISPLAYCOMPONENT_HPP
#define DISPLAYCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La structure DisplayComponent comporte les données concernant l'apparence graphique qu'a une entité.
 * Elle contient un entier qui correspond à un sprite.
 */
struct DisplayComponent : public Component{

    /**
     * @brief DisplayComponent Constructeur de la structure BehaviorComponent.
     * Initialisation de la variable muiTypeBehavior.
     */
    DisplayComponent(){
        muiTypeComponent = DISPLAY_COMPONENT;
    }

    /**
     * @brief displayComponent Fonction dérivée d'affichage des variables de la structure DisplayComponent.
     * La fonction de base d'affichage de la classe mère est appelée en premier lieu.
     */
    void displayComponent()const override{
        //Component::displayComponent();
        std::cout << "muiNumSprite" << muiNumSprite << "\n";
    }
    unsigned int muiNumSprite;
};

#endif // DISPLAYCOMPONENT_HPP
