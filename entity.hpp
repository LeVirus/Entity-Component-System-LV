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
    unsigned int searchCaseComponent( unsigned int uiTypeComponent )const;


    void attributeIDEntity( unsigned int uiIdEntity );
    bool bAddComponent( unsigned int uiTypeComponent );
    bool bRmComponent( unsigned int uiTypeComponent );
    void RmAllComponent();

    /**
     * @brief Entity::searchComponentByType
     * Fonction renvoyant la référence du contenant recherché, la fonction
     * searchCaseComponent retourne le numéro de case, et la fonction courante
     * renvoie le composant avec un dynamic_cast.
     * @param uiTypeComponent le type de composant a rechercher.
     * @return la référence du composant recherché.
     */
    template < typename componentTemplate >
    componentTemplate &searchComponentByType(unsigned int uiTypeComponent){
        unsigned int uiCaseComponent = searchCaseComponent( uiTypeComponent );
            //return *mVectComponent[ uiCaseComponent ];
            return static_cast< componentTemplate& >( *mVectComponent[ uiCaseComponent ] );
    }

};

#endif // ENTITY_HPP
