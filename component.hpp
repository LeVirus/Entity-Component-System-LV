#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>

/**
 * @brief La structure Component est la classe mère de tous les composants.
 * Un composant représente un élément d'une entité.
 * Elle est abstraite, et comporte un identifiant de type.
 */
struct Component{
    //static unsigned int muiNumberComponent = 0;

    virtual void displayComponent()const{
        std::cout << "muiTypeComponent" << muiTypeComponent
                  << "muiIDComponent" << muiIDComponent << std::endl;
    }

    inline unsigned int muiGetTypeComponent()const{ return muiTypeComponent; }
protected:
    unsigned int muiTypeComponent, muiIDComponent;
    inline Component(){}// = delete;
    //inline void initComponent(){ muiIDComponent = muiNumberComponent; muiNumberComponent++; }
};

#endif // COMPONENT_HPP
