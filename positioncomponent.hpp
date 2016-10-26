#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "component.hpp"
#include "vector2D.hpp"
#include "ECSconstantes.hpp"

class Vector2D;

/**
 * @brief La structure PositionComponent représente la position d'une entité.
 * Elle contient l'abscisse et l'ordonnée de l'entité.
 */
struct PositionComponent : public Component{
    Vector2D vect2DPosComp;

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
        //Component::displayComponent();
        std::cout << "Position Component\n";
        std::cout << "vect2DPosComp . mfX::" << vect2DPosComp . mfX << "\n";
        std::cout << "vect2DPosComp . mfY::" << vect2DPosComp . mfY << "\n";
        std::cout << "Fin Position Component\n";
    }
    //float mfPositionX, mfPositionY;

};

#endif // POSITIONCOMPONENT_HPP
