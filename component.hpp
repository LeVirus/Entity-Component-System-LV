#ifndef COMPONENT_HPP
#define COMPONENT_HPP

/**
 * @brief La classe Component est la classe mère de tous les composants. 
 * Un composant représente un élément d'une entité.
 * Elle est abstraite, et comporte un identifiant de type.
 * Tous les éléments de la classe sont public
 */
abstract struct Component{
    unsigned int muiTypeComponent;
};

#endif // COMPONENT_HPP
