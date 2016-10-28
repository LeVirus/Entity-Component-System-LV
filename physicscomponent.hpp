#ifndef PHYSICSCOMPONENT_HPP
#define PHYSICSCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"


namespace ecs
{

/**
 * @brief La structure PhysicComponent détermine les caractéristiques physiques d'une entité.
 * mbGhost détermine si l'entité peut traverser les objets physiques.
 * mbTerrestrial détermine si l'entité est de type terrestre ou volante.
 */
struct PhysicComponent : public Component{
    unsigned int muiTag;

    /**
     * @brief PhysicComponent Constructeur de PhysicComponent.
     * Initialisation de la variable muiTypeBehavior.
     */
    PhysicComponent() : muiTag{ 0 } {
        muiTypeComponent = PHYSIC_COMPONENT;
    }

    /**
     * @brief displayComponent Fonction dérivée d'affichage des variables de la structure PhysicComponent.
     * La fonction de base d'affichage de la classe mère est appelée en premier lieu.
     */
    void displayComponent()const override{
        //Component::displayComponent();
    }
};

}//fin namespace
#endif // PHYSICSCOMPONENT_HPP

