#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include "ECSconstantes.hpp"
#include "component.hpp"
#include <vector>
#include <memory>


namespace ecs
{

class Engine;

/**
 * @brief La classe ComponentManager gère tous les composants.
 * Les composants de toutes les entités sont stockés dans un tableau.
 * Leurs emplacements sont déterminés par le numéro de leur entité associée ainsi que par leurs type(associé à une énumération).
 * numéro emplacement = numéro entité * nombre total de type de composant + numéro type de composant.
 */
class ComponentManager{
private:
    Engine * mptrEngine;
    std::vector< std::unique_ptr< Component > > mVectComponent;
	static unsigned int muiNumberComponent;//a la base dans l'ECS
public:

    ComponentManager();
    void updateComponentFromEntity();
    void linkEngineToComponentManager( Engine *ptrEngine );
    void instanciateComponent( unsigned int uiNumCase );
    void displayComponent()const;
    bool bVerifComponentInstanciate( unsigned int uiNumEntity, unsigned int uiTypeComponent );
	void addExternComponent( unsigned int numberNewComponent );
	void instanciateExternComponent( unsigned int uiNumEntity, std::unique_ptr< Component > &ptrComp );

	static unsigned int getNumberComponent();

    /**
     * @brief ComponentManager::searchComponentByType
     * Fonction renvoyant la référence du contenant recherché.
     * Une vérification est effectué avant l'envoie:
     * -Les paramètres renvoie bien a une case du tableau(pas de dépassement de mémoire).
     * -Le paramètre renvoie bien à une case contenant un composant instancié.
     * La fonction renvoie le composant avec un static_cast.
     * @param uiNumEntity le numéro de l'entité à qui appartient le composant recherché.
     * @param uiTypeComponent le type de composant a rechercher.
     * @return Un pointeur vers le composant demandé, NULL en cas de paramètre invalide ou
     * si le composant demandé n'est pas instancié.
     */
    template < typename componentTemplate >

     componentTemplate * searchComponentByType( unsigned int uiNumEntity, unsigned int uiTypeComponent ){

		if( ( uiNumEntity * muiNumberComponent + uiTypeComponent ) >=  mVectComponent.size() ||
			  !  mVectComponent[ uiNumEntity * muiNumberComponent + uiTypeComponent ] )return nullptr;
        static_assert( std::is_base_of< Component, componentTemplate >(), "componentTemplate n'est pas un composant" );
        //récupérer un pointeur vers l'objet contenu dans le unique_ptr
		return static_cast< componentTemplate* >( mVectComponent[ uiNumEntity * muiNumberComponent + uiTypeComponent ].get() );
    }
};

}//fin namespace
#endif // COMPONENTMANAGER_H
