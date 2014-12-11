#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <bitset>
#include <memory>

#include "component.hpp"

/**
 * @brief La classe Entity est représentative d'un élément de la scène du jeu.
 * Elle contient un vector de Component.
 *
 * Cette classe permet d'ajouter/supprimer les composents de l'entité.
 */
class Entity
{
private:
    unsigned int mUiIDEntity;
    std::bitset< 16 > mBitSetComponent;
public:
    std::vector< std::unique_ptr< Component > > mVectComponent;
    
    Entity();
    Entity( unsigned int uiIdEntity );
    void displayEntity()const;
    void attributeIDEntity( unsigned int uiIdEntity );
    bool bAddComponent();
    bool bRmComponent( unsigned int uiIdComponent );
    void RmAllComponent();
};

#endif // ENTITY_HPP
