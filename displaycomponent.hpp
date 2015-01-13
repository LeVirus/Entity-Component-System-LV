#ifndef DISPLAYCOMPONENT_HPP
#define DISPLAYCOMPONENT_HPP

//#include <SFML/Graphics.hpp>
#include "component.hpp"
#include "constantes.hpp"

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
        std::cout << "muiNumSprite" << muiNumSprite << std::endl;
    }
    unsigned int muiNumSprite;

    //sf::Sprite mSpriteComp;
};

#endif // DISPLAYCOMPONENT_HPP
