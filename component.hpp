#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>

/**
 * @brief La structure Component est la classe mère de tous les composants.
 * Un composant représente un élément d'une entité.
 * Elle est abstraite, et comporte un identifiant de type.
 */
struct Component{
    virtual void displayComponent()const{
        std::cout << "muiTypeComponent" << muiTypeComponent
                  << "muiIDComponent" << muiIDComponent << std::endl;
    }

    inline unsigned int muiGetTypeComponent()const{ return muiTypeComponent; }
    inline unsigned int muiGetIdComponent()const{ return muiIDComponent; }
    protected:
        unsigned int muiTypeComponent, muiIDComponent;
        inline Component(){}// = delete;
};

#endif // COMPONENT_HPP
