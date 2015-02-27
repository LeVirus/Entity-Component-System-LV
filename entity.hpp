#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <bitset>
#include <memory>
#include "component.hpp"
#include "ECSconstantes.hpp"

/**
 * @brief La classe Entity est représentative d'un élément de la scène du jeu.
 * Elle contient un vector de Component.
 * Le bitset indique quels sont les composants que contient l'entité, ils sont désigné par leurs type( muiTypeComponent ).
 *
 * Cette classe permet d'ajouter/supprimer les composents de l'entité.
 */
class Entity
{
private:
    unsigned int mUiIDEntity;
    std::bitset< NUMBR_COMPONENT > mBitSetComponent;
    //mbMoveableInitialized ne sert qu'aux entité possédant le composant MoveableComponent
    bool mbActive, mbUpToDate, mbEntityInUse;
public:
    const std::bitset< NUMBR_COMPONENT > & getEntityBitSet()const;

    Entity();
    Entity( unsigned int uiIdEntity );
    void displayEntity()const;
    bool ComponentExist( unsigned int uiTypeComponent )const;
    bool bEntityIsUpToDate()const;
    bool bInUse()const;
    void initEntity();

    void modifyEntityInUse( bool bInUse );
    void setUpToDate();
    void attributeIDEntity( unsigned int uiIdEntity );
    bool bAddComponent( unsigned int uiTypeComponent );
    bool bRmComponent( unsigned int uiTypeComponent );
    void RmAllComponent();
    bool bEntityIsActive()const;

    inline unsigned int muiGetIDEntity()const{ return mUiIDEntity; }
};

#endif // ENTITY_HPP
