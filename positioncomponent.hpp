#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La structure PositionComponent représente la position d'une entité.
 * Elle contient l'abscisse et l'ordonnée de l'entité.
 */
struct PositionComponent : public Component{

    /**
     * @brief PositionComponent Constructeur de PositionComponent.
     * Initialisation de la variable muiTypeBehavior.
     */
    PositionComponent(){
        muiTypeComponent = POSITION_COMPONENT;
    }

    /**
     * @brief displayComponent Fonction dérivée d'affichage des variables de la structure PositionComponent.
     * La fonction de base d'affichage de la classe mère est appelée en premier lieu.
     */
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "mfPositionX" << mfPositionX << "\n";
        std::cout << "mfPositionY" << mfPositionY << "\n";
    }
    float mfPositionX, mfPositionY;

};

#endif // POSITIONCOMPONENT_HPP
