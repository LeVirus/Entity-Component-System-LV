#ifndef DISPLAYCOMPONENT_HPP
#define DISPLAYCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La structure DisplayComponent comporte les données concernant l'apparence graphique qu'a une entité.
 * Elle contient un entier qui correspond à un sprite.
 */
struct DisplayComponent : public Component{
    DisplayComponent(){
        muiTypeComponent = DISPLAY_COMPONENT;
    }
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "muiNumSprite" << muiNumSprite << "\n";
    }
    unsigned int muiNumSprite;
};

#endif // DISPLAYCOMPONENT_HPP
