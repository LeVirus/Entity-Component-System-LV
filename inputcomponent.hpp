#ifndef INPUTCOMPONENT_HPP
#define INPUTCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include <bitset>


namespace ecs
{

/**
 * @brief La structure InputComponent comporte les associations de numéros avec les
 * intéractivités que peut effectuer le joueur avec l'entité associée.
 */
struct InputComponent : public Component{
    std::bitset< NUMBR_INPUT > mBitsetInput;
    /**
     * @brief InputComponent Constructeur de la structure InputComponent.
     * Initialisation de la variable muiTypeBehavior.
     */
    InputComponent(){
        muiTypeComponent = INPUT_COMPONENT;
    }
    void displayComponent()const override{


    }
};

}//fin namespace
#endif // INPUTCOMPONENT_HPP

