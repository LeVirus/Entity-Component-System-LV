#include "systemmanager.hpp"
#include "ECSconstantes.hpp"
#include "displaysystem.hpp"
#include "gravitysystem.hpp"
#include "collisionsystem.hpp"
#include "inputsystem.hpp"
#include "groundcomponent.hpp"
#include "iasystem.hpp"
#include <memory>
#include <cassert>
#include <iostream>

namespace ecs
{

/**
 * @brief SystemManager::SystemManager Constructeur de la classe SystemManager.
 */
SystemManager::SystemManager()
{
	//init pour les 5 systèmes déja existant au sein de l'ECS
	mVectSystem.resize( 5 );
}

/**
 * @brief SystemManager::linkEngine fonction envoyant un pointeur d'Engine à SystemManager.
 * @param ptrEngine Un pointeur d'Engine
 */
void SystemManager::linkEngine( Engine* ptrEngine )
{
    mptrEngine = ptrEngine;
}

/**
 * @brief SystemManager::bAddSystem Fonction d'ajout d'un système dans SystemManager.
 * La fonction vérifie si le numéro envoyé en paramètre correspond bien à un système existant,
 * et si le système n'est pas déja présent dans le tableau.
 * @param uiIdSystem Le numéro du système à ajouter.
 * @return true si le système a été ajouté, false sinon.
 */
bool SystemManager::bAddSystem( unsigned int uiIdSystem )
{//FONCTION A MODIFIER

    bool bReturn = false;
    if( uiIdSystem < mBitSetSystem.size() && mBitSetSystem[ uiIdSystem ] == false ){
        bReturn = true;
        switch( uiIdSystem ){
        case DISPLAY_SYSTEM:

            mVectSystem[ DISPLAY_SYSTEM ] = std::make_unique< DisplaySystem >();
            mBitSetSystem[ DISPLAY_SYSTEM ] = true;
            break;
        case IA_SYSTEM:

            mVectSystem[ IA_SYSTEM ] = std::make_unique< IASystem >();
            mBitSetSystem[ IA_SYSTEM ] = true;
            break;
        case GRAVITY_SYSTEM:

            mVectSystem[ GRAVITY_SYSTEM ] = std::make_unique< GravitySystem >();
            mBitSetSystem[ GRAVITY_SYSTEM ] = true;
            break;
        case INPUT_SYSTEM:

            mVectSystem[ INPUT_SYSTEM ] = std::make_unique< InputSystem >();
            mBitSetSystem[ INPUT_SYSTEM ] = true;
            break;
        case COLLISION_SYSTEM:

            mVectSystem[ COLLISION_SYSTEM ] = std::make_unique< CollisionSystem >();
            mBitSetSystem[ COLLISION_SYSTEM ] = true;
            break;
        default:
            assert( false && " Num système incorrect\n" );
            bReturn = false;
            break;
        }
        //envoie du pointeur de systemManager vers tous les systèmes créé
        mVectSystem[ uiIdSystem ] -> linkSystemManager( this );
    }
	return bReturn;
}

/**
 * @brief SystemManager::bAddExternSystem Ajout d'un système implémenté en dehors de la bibliothèque.
 * @param newSystem Le pointeur du nouveau système.
 * @return true si le systeme a été créer avec succés, false sinon
 */
bool SystemManager::bAddExternSystem( std::unique_ptr<System> &newSystem )
{
	if( newSystem == nullptr || muiNumberSystem >= ecs::NUMBR_SYSTEM_MAX )return false;
	mVectSystem.push_back( std::move( newSystem ) );
	mBitSetSystem[ muiNumberSystem++ ] = true;
	mVectSystem[ mVectSystem.size() - 1 ] -> linkSystemManager( this );
	return true;
}

/**
 * @brief SystemManager::getptrEngine fonction renvoyant un pointeur vers Engine.
 * @return Un pointeur vers Engine.
 */
Engine* SystemManager::getptrEngine()
{
    return mptrEngine;
}


/**
 * @brief SystemManager::bRmSystem Fonction de suppression d'un système de SystemManager.
 * La fonction vérifie si la valeur envoyée en paramètre correspond à un système présent dans le tableau.
 * @param uiIdSystem Le numéro du système à supprimer.
 * @return true si le système est trouvé et supprimé, false sinon.
 */
bool SystemManager::bRmSystem( unsigned int uiIdSystem )
{
    bool bReturn = false;
    if( uiIdSystem < mBitSetSystem.size() && mBitSetSystem[ uiIdSystem ] == true ){
        mBitSetSystem[ uiIdSystem ] = false;
        mVectSystem[ uiIdSystem ].reset();
        bReturn = true;
    }

    return bReturn;
}

/**
 * @brief SystemManager::bRmAllSystem Fonction supprimant tous les systèmes de SystemManager, mBitSetSystem est réinitialisé.
 */
void SystemManager::RmAllSystem()
{
	for( unsigned int i = 0 ; i < mVectSystem.size() ; ++i )
	{
        if( mVectSystem[ i ] )
            mVectSystem[ i ].reset();
    }
    mBitSetSystem.reset();
}

/**
 * @brief SystemManager::bExexSystem Fonction déclanchant l'exécutions du système dont l'identifiant est envoyé en paramètre.
 * La fonction vérifie si le paramètre correspond bien à un système présent dans SystemManager.
 * @param uiIdSystem Le numéro du système à exécuter.
 * @return true si la suppression a été effectuée avec succés, false sinon.
 */
bool SystemManager::bExexSystem( unsigned int uiIdSystem )
{
    bool bReturn = false;
	if( uiIdSystem < mVectSystem.size() && mVectSystem[ uiIdSystem ] )
	{
        mVectSystem[ uiIdSystem ] -> execSystem();
        bReturn = true;
    }
    return bReturn;
}

/**
 * @brief SystemManager::bExecAllSystem Fonction déclanchant les exécutions de tous les systèmes présents dans SystemManager.
 * @return false si la liste des système est vide, true sinon.
 */
void SystemManager::bExecAllSystem()
{
	for( unsigned int i = 0 ; i < mVectSystem.size() ; ++i )
	{
		if( mVectSystem[ i ] )
		{
            mVectSystem[ i ] ->  execSystem();
        }
    }
}

}//fin namespace
