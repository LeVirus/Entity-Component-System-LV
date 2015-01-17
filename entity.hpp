#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <bitset>
#include <memory>
#include "component.hpp"

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
    bool mbActive;
    static bool upToDate;
public:
    //std::vector< std::unique_ptr< Component > > mVectComponent;
    const std::bitset< NUMBR_COMPONENT > & getEntityBitSet()const;

    Entity();
    Entity( unsigned int uiIdEntity );
    void displayEntity()const;
    bool ComponentExist( unsigned int uiTypeComponent )const;


    void attributeIDEntity( unsigned int uiIdEntity );
    bool bAddComponent( unsigned int uiTypeComponent );
    bool bRmComponent( unsigned int uiTypeComponent );
    void RmAllComponent();
    bool bEntityIsActive()const;

    /**
     * @brief Entity::searchComponentByType
     * Fonction renvoyant la référence du contenant recherché, la fonction
     * ComponentExist vérifie si le composant existe dans l'entité, et la fonction courante
     * renvoie le composant avec un static_cast.
     * @param uiTypeComponent le type de composant a rechercher.
     * @return la référence du composant recherché.
     */
    template < typename componentTemplate >

    componentTemplate &searchComponentByType( unsigned int uiTypeComponent ){

        if( ! ComponentExist( uiTypeComponent ) )return;
        static_assert( std::is_base_of< Component, componentTemplate >(), "componentTemplate n'est pas un composant" );

        return static_cast< componentTemplate& >( *mVectComponent[ uiTypeComponent ] );
    }

};

#endif // ENTITY_HPP
