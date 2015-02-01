#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

#include <vector>
#include "system.hpp"
//#include "engine.hpp"
#include <bitset>
#include <iostream>
#include <memory>

class Engine;
class System;

/**
 * @brief La classe SystemManager gère les systèmes actifs.
 * Elle contient un vector de System.
 *
 * Cette classe permet d'ajouter/supprimer les systèmes et de les exécuter.
 */
class SystemManager{
    std::vector< std::unique_ptr< System > > mVectSystem;
    std::bitset< 16 > mBitSetSystem;
    Engine* mptrEngine;
public:
    SystemManager();
    Engine* getptrEngine();
    void linkEngine( Engine* ptrEngine );
    bool bAddSystem( unsigned int uiIdSystem );
    bool bRmSystem( unsigned int uiIdSystem );
    void RmAllSystem();
    bool bExexSystem( unsigned int uiIdSystem );
    void bExecAllSystem();


    /**
     * @brief SystemManager::searchSystemByType
     * Fonction renvoyant la référence du système recherché.
     * Une vérification est effectué avant l'envoie:
     * -Le paramètre renvoie bien a une case du tableau(pas de dépassement de mémoire).
     * La fonction renvoie le Système avec un static_cast.
     * @param uiTypeSystem le type de système a rechercher.
     * @return Un pointeur vers le système demandé, NULL en cas de paramètre invalide.
     */
    template < typename systemTemplate >

     systemTemplate * searchSystemByType( unsigned int uiTypeSystem ){

        if( uiTypeSystem >= mVectSystem.size() )return NULL;
        static_assert( std::is_base_of< System, systemTemplate >(), "systemTemplate n'est pas un système" );
        //récupérer un pointeur vers l'objet contenu dans le unique_ptr
        return static_cast< systemTemplate* >( mVectSystem[ uiTypeSystem ].get() );
    }
};

#endif // SYSTEMMANAGER_HPP
