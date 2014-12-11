#ifndef COMPONENT_HPP
#define COMPONENT_HPP

/**
 * @brief La structure Component est la classe mère de tous les composants.
 * Un composant représente un élément d'une entité.
 * Elle est abstraite, et comporte un identifiant de type.
 */
struct Component{
    unsigned int muiTypeComponent, muiIDComponent;
    Component() = delete;   //pour bloquer l'instanciation.
};

#endif // COMPONENT_HPP
