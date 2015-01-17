#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include "constantes.hpp"
#include <vector>

class ComponentManager{
private:
    std::vector< std::unique_ptr< Component > > mVectComponent;
public:
    ComponentManager();
    bool bsetNumEntity();
    bool bAddComponent( unsigned int uiNumEntity, unsigned int uiNumTypeComponent );
    bool bRmComponent( unsigned int uiNumEntity, unsigned int uiNumTypeComponent );
    //void rmAllComponent();

    /**
     * @brief ComponentManager::searchComponentByType
     * Fonction renvoyant la référence du contenant recherché.
     * Une vérification est effectué avant l'envoie:
     * -Les paramètres renvoie bien a une case du tableau(pas de dépassement de mémoire).
     * -La case est bien un composant instancié.
     * La fonction renvoie le composant avec un static_cast.
     * @param uiTypeComponent le type de composant a rechercher.
     * @return la référence du composant recherché.
     */
    template < typename componentTemplate >

    componentTemplate &searchComponentByType( unsigned int uiNumEntity, unsigned int uiTypeComponent ){

        if( ( uiNumEntity * NUMBR_COMPONENT + uiTypeComponent ) <  mVectComponent.size() &&
                mVectComponent[ uiNumEntity * NUMBR_COMPONENT + uiTypeComponent ] )return;
        static_assert( std::is_base_of< Component, componentTemplate >(), "componentTemplate n'est pas un composant" );

        return static_cast< componentTemplate& >( *mVectComponent[ uiNumEntity * NUMBR_COMPONENT + uiTypeComponent ] );
    }
};

#endif // COMPONENTMANAGER_H
