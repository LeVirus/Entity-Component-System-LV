#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "component.hpp"
#include "constantes.hpp"

/**
 * @brief La structure PositionComponent représente la position d'une entité.
 * Elle contient l'abscisse et l'ordonnée de l'entité.
 */
struct PositionComponent : public Component{

    PositionComponent(){
        muiTypeComponent = POSITION_COMPONENT;
    }
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "mfPositionX" << mfPositionX << std::endl;
        std::cout << "mfPositionY" << mfPositionY << std::endl;
    }
    float mfPositionX, mfPositionY;

};

#endif // POSITIONCOMPONENT_HPP
