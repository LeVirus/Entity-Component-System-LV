#ifndef PHYSICSCOMPONENT_HPP
#define PHYSICSCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La structure PhysicComponent détermine les caractéristiques physiques d'une entité.
 * mbGhost détermine si l'entité peut traverser les objets physiques.
 * mbTerrestrial détermine si l'entité est de type terrestre ou volante.
 */
struct PhysicComponent : public Component{
    bool mbTerrestrial, mbGhost;

    PhysicComponent(){
        muiTypeComponent = PHYSIC_COMPONENT;
    }
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "terrestrial::" << mbTerrestrial << "\n ghost" << mbGhost << "\n";
    }
};

#endif // PHYSICSCOMPONENT_HPP

