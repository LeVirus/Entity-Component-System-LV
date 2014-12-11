#ifndef COMPONENT_HPP
#define COMPONENT_HPP

/**
 * @brief La structure Component est la classe mère de tous les composants.
 * Un composant représente un élément d'une entité.
 * Elle est abstraite, et comporte un identifiant de type.
 */
struct Component{
    //static unsigned int muiNumberComponent = 0;
    unsigned int muiTypeComponent, muiIDComponent;
protected:
    inline Component(){}// = delete;   //pour bloquer l'instanciation.
    //inline void initComponent(){ muiIDComponent = muiNumberComponent; muiNumberComponent++; }
};

#endif // COMPONENT_HPP
