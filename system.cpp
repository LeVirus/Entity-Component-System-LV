#include "system.hpp"
#include "constantes.hpp"

/**
 * @brief System::System Constructeur de la classe System
 */
System::System(){

}

/**
 * @brief SystemManager::linkEngine fonction envoyant un pointeur d'Engine à SystemManager.
 * @param ptrEngine Un pointeur d'Engine
 */
void System::linkSystemManager( std::unique_ptr< SystemManager > ptrSystemManager ){
    mptrSystemManager = ptrSystemManager;
}

/**
 * @brief System::refreshNode Fonction de synchronisation des entités à modifier par le système.
 * La fonction va rechercher les entités et récupérer les références des composants nécessaires
 * @return false si le tableau des composants( à récupérer ) est vide, true sinon.
 */
bool System::bRefreshNode(){
    bool bReturn = false;
    if( mVectTypeComponent.size() != 0 ){

        bReturn = true;
    }
}

/**
 * @brief System::displaySystem Fonction d'affichage des caractéristiques du système.
 * Affichage des composants nécessaire au système et descriptif de la fonction du système.
 */
void System::displaySystem()const{

}

/**
 * @brief System::addComponentSystem Fonction d'ajout d'un composant au système.
 * @param uiTypeComponent le numéro du composant à intégrer dans le système.
 * @return false si le composant est déja présent ou si uiTypeComponent ne correspond à aucun composants
 * true sinon.
 */
bool System::bAddComponentToSystem( unsigned int uiTypeComponent ){
    bool bReturn = false;
    if( ! bComponentAlreadyExist( uiTypeComponent ) ){//A MODIFIER
        bReturn = true;
        switch( uiTypeComponent ){
        case DISPLAY_COMPONENT:
                break;
        case POSITION_COMPONENT:
                break;
        default:
            bReturn = false;
            break;
        }
    }
    if( bReturn ){
        mVectTypeComponent.push_back( uiTypeComponent );
    }
    return bReturn;
}

/**
 * @brief System::bAlreadyExist Fonction vérifiant si le numéro de composant(paramètre)
 * est déja présent dans le tableau de stockage des composants.
 * @param uiTypeComponent Le numéro du composant à vérifier.
 * @return true si le composant est présent, false sinon.
 */
bool System::bComponentAlreadyExist( unsigned int uiTypeComponent ){
    bool bReturn = false;
    for( unsigned int i = 0 ; i < mVectTypeComponent.size() ; ++i ){
        if( uiTypeComponent == mVectTypeComponent[ i ] ){
            bReturn = true;
            break;
        }
    }
    return bReturn;
}
