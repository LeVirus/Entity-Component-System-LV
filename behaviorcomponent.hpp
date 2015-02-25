#ifndef BEHAVIORCOMPONENT_HPP
#define BEHAVIORCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La structure BehaviorComponent représente le type de comportement de l'entité.
 */
struct BehaviorComponent : public Component{
    unsigned int muiTypeBehavior;//a modifier remplacer par un bitset

    BehaviorComponent(){
        muiTypeComponent = BEHAVIOR_COMPONENT;
        muiTypeBehavior = UNSPECIFIED;
    }
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "muiTypeComponent" << muiTypeComponent << "\n";
    }
    unsigned int muiNumSprite;
};

#endif // BEHAVIORCOMPONENT_HPP
