#include "systemmanager.hpp"
#include "constantes.hpp"
#include "displaysystem.hpp"
#include <memory>

/**
 * @brief SystemManager::SystemManager Constructeur de la classe SystemManager.
 */
SystemManager::SystemManager(){

}

/**
 * @brief SystemManager::linkEngine fonction envoyant un pointeur d'Engine à SystemManager.
 * @param ptrEngine Un pointeur d'Engine
 */
void SystemManager::linkEngine( Engine* ptrEngine ){
    mptrEngine = ptrEngine;
}

/**
 * @brief SystemManager::bAddSystem Fonction d'ajout d'un système dans SystemManager.
 * La fonction vérifie si le numéro envoyé en paramètre correspond bien à un système existant,
 * et si le système n'est pas déja présent dans le tableau.
 * @param uiIdSystem Le numéro du système à ajouter.
 * @return true si le système a été ajouté, false sinon.
 */
bool SystemManager::bAddSystem( unsigned int uiIdSystem ){//FONCTION A MODIFIER

    bool bReturn = false;
    unsigned int uiNumCaseSystem = uiGetNumCaseSystem( uiIdSystem );
    if( uiNumCaseSystem == SYSTEM_NOT_FOUND ){//A MODIFIER trouver un moyen de savoir le nombre de type de composant

        bReturn = true;
        switch( uiIdSystem ){
        case DISPLAY_SYSTEM:

            mVectSystem.push_back( std::make_unique< DisplaySystem >() );
            mBitSetSystem[ DISPLAY_SYSTEM ] = true;
                break;
        default:

            bReturn = false;
            break;
        }
    }
    //envoie du pointeur de systemManager vers tous les systèmes créé
    if( bReturn ){
        mVectSystem[ mVectSystem.size() - 1 ] -> linkSystemManager( this );
    }

    return bReturn;
}

/**
 * @brief SystemManager::getptrEngine fonction renvoyant un pointeur vers Engine.
 * @return Un pointeur vers Engine.
 */
Engine* SystemManager::getptrEngine(){
    return mptrEngine;
}


/**
 * @brief SystemManager::bRmSystem Fonction de suppression d'un système de SystemManager.
 * La fonction vérifie si la valeur envoyée en paramètre correspond à un système présent dans le tableau.
 * @param uiIdSystem Le numéro du système à supprimer.
 * @return true si le système est trouvé et supprimé, false sinon.
 */
bool SystemManager::bRmSystem( unsigned int uiIdSystem ){
    bool bReturn = false;

    if( uiIdSystem < mBitSetSystem.size() && mBitSetSystem[ uiIdSystem ] == true ){
        unsigned int uiNumCaseSystem = uiGetNumCaseSystem( uiIdSystem );
        if( uiNumCaseSystem != SYSTEM_NOT_FOUND ){
            mVectSystem.erase( mVectSystem.begin() + uiNumCaseSystem );
            mBitSetSystem[ uiIdSystem ] = false;
            bReturn = true;
        }
    }

    return bReturn;
}

/**
 * @brief SystemManager::bRmAllSystem Fonction supprimant tous les systèmes de SystemManager.
 */
void SystemManager::RmAllSystem(){
    mVectSystem.clear();
    mBitSetSystem.reset();
}

/**
 * @brief SystemManager::bExexSystem Fonction déclanchant l'exécutions du système dont l'identifiant est envoyé en paramètre.
 * La fonction vérifie si le paramètre correspond bien à un système présent dans SystemManager.
 * @param uiIdSystem Le numéro du système à exécuter.
 * @return true si la suppression a été effectuée avec succés, false sinon.
 */
bool SystemManager::bExexSystem( unsigned int uiIdSystem ){
    bool bReturn = false;
    unsigned int uiNumCaseSystem = uiGetNumCaseSystem( uiIdSystem );
    if( uiNumCaseSystem != SYSTEM_NOT_FOUND ){
        mVectSystem[ uiNumCaseSystem ] -> execSystem();
        bReturn = true;
    }
    return bReturn;
}

/**
 * @brief SystemManager::bSystemExist Fonction de vérification de l'existance du système dont l'identifiant est envoyé en paramètre.
 * @param uiIdSystem Le numéro du système.
 * @return Le numéro de la case ou le système a été trouvé, 1000 si le systèmme n'existe pas.
 */
unsigned int SystemManager::uiGetNumCaseSystem( unsigned int uiIdSystem ){
    unsigned int uiNumCaseSystem = SYSTEM_NOT_FOUND;

    if( uiIdSystem < mBitSetSystem.size() && mBitSetSystem[ uiIdSystem ] == true ){

        for( unsigned int i = 0 ; i < mVectSystem.size() ; ++i ){
            if( mVectSystem[ i ] -> uiGetIdSystem() == uiIdSystem ){
                uiNumCaseSystem = i;
                break;
            }
        }
    }
    return uiNumCaseSystem;
}

/**
 * @brief SystemManager::bExecAllSystem Fonction déclanchant les exécutions de tous les systèmes présents dans SystemManager.
 * @return false si la liste des système est vide, true sinon.
 */
bool SystemManager::bExecAllSystem(){
    bool bReturn = false;
    if( ! mVectSystem.empty() ){
        for( unsigned int i = 0 ; i < mVectSystem.size() ; ++i ){
            mVectSystem[ i ] ->  refreshEntity();
            mVectSystem[ i ] ->  execSystem();
            mVectSystem[ i ] ->  displaySystem();
        }
        bReturn = true;
    }
    return bReturn;
}
