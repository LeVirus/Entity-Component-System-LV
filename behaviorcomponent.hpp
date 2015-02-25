#ifndef BEHAVIORCOMPONENT_HPP
#define BEHAVIORCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La structure BehaviorComponent représente le type de comportement de l'entité.
 */
struct BehaviorComponent : public Component{
    unsigned int uiTypeBehavior;

    BehaviorComponent(){
        muiTypeComponent = BEHAVIOR_COMPONENT;
        uiTypeBehavior = 0;
    }
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "muiTypeComponent" << muiTypeComponent << "\n";
    }
    unsigned int muiNumSprite;
};

#endif // BEHAVIORCOMPONENT_HPP

