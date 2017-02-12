#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

#include <vector>
#include "system.hpp"
#include "ECSconstantes.hpp"
//#include "engine.hpp"
#include <bitset>
#include <iostream>
#include <memory>



namespace ecs
{

class Engine;
class System;

/**
 * @brief La classe SystemManager gère les systèmes actifs.
 * Elle contient un tableau de système dont le nombre de case est égal au nombre de type de système.
 * Chaque système à un emplacement prédéfinis dans le tableau, le type de système détermine l'emplacement de ce dernier.
 * Tous les types de système étant présents dans une énumération.
 * Cette classe permet d'ajouter/supprimer les systèmes et de les exécuter.
 */
class SystemManager{
    std::vector< std::unique_ptr< System > > mVectSystem;
	std::bitset< NUMBR_SYSTEM_MAX > mBitSetSystem;
    Engine* mptrEngine;
	unsigned int muiNumberSystem = 5;
public:
    SystemManager();
    Engine* getptrEngine();
    void linkEngine( Engine* ptrEngine );
    bool bAddSystem( unsigned int uiIdSystem );
	bool bAddExternSystem( std::unique_ptr<System> &newSystem );
	bool bRmSystem( unsigned int uiIdSystem );
    void RmAllSystem();
    bool bExexSystem( unsigned int uiIdSystem );
    void bExecAllSystem();


    /**
     * @brief SystemManager::searchSystemByType
     * Fonction renvoyant la référence du système recherché.
     * Une vérification est effectué avant l'envoie:
     * -Le paramètre renvoie bien à une case du tableau(pas de dépassement de mémoire).
     * -Le paramètre renvoie bien à une case contenant un système instancié.
     * La fonction renvoie le Système avec un static_cast.
     * @param uiTypeSystem le type de système a rechercher.
     * @return Un pointeur vers le système demandé, NULL en cas de paramètre invalide.
     */
    template < typename systemTemplate >
     systemTemplate * searchSystemByType( unsigned int uiTypeSystem ){

        if( uiTypeSystem >= mVectSystem.size() || ! mVectSystem[ uiTypeSystem ] )return NULL;
        static_assert( std::is_base_of< System, systemTemplate >(), "systemTemplate n'est pas un système" );
        //récupérer un pointeur vers l'objet contenu dans le unique_ptr
        return static_cast< systemTemplate* >( mVectSystem[ uiTypeSystem ].get() );
    }
};

}//fin namespace
#endif // SYSTEMMANAGER_HPP
