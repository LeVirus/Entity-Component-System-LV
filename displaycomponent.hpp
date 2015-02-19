#ifndef DISPLAYCOMPONENT_HPP
#define DISPLAYCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La structure DisplayComponent représente la position d'une entité.
 * Elle contient l'abscisse et l'ordonnée.
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
