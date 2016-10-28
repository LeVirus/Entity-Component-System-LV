#ifndef BEHAVIORCOMPONENT_HPP
#define BEHAVIORCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"


namespace ecs
{


/**
 * @brief La structure BehaviorComponent représente le type de comportement de l'entité.
 * Le comportement est déterminé par un entier.
 */
struct BehaviorComponent : public Component{
	unsigned int muiTypeBehavior;//a modifier remplacer par un bitset

	/**
	 * @brief BehaviorComponent Constructeur de la structure BehaviorComponent.
	 * Initialisation des variables muiTypeComponent(présente dans la classe mère Component) et muiTypeBehavior.
	 */
	BehaviorComponent(){
		muiTypeComponent = BEHAVIOR_COMPONENT;
		muiTypeBehavior = UNSPECIFIED;
	}

	/**
	 * @brief displayComponent Fonction dérivée d'affichage des variables de la structure BehaviorComponent.
	 * La fonction de base d'affichage de la classe mère est appelée en premier lieu.
	 */
	void displayComponent()const override{
		//Component::displayComponent();
		std::cout << "muiTypeComponent" << muiTypeComponent << "\n";
	}
};

}//fin namespace

#endif // BEHAVIORCOMPONENT_HPP
