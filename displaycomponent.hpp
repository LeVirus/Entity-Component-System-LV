#ifndef DISPLAYCOMPONENT_HPP
#define DISPLAYCOMPONENT_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief La structure DisplayComponent représente la position d'une entité.
 * Elle contient l'abscisse et l'ordonnée.
 */
struct DisplayComponent : public Compionent{
    sf::Sprite mSpriteComp;
};

#endif // DISPLAYCOMPONENT_HPP
