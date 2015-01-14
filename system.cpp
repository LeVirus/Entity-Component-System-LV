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
    ptrSystemManager.swap( mptrSystemManager );
}

/**
 * @brief System::refreshNode Fonction de synchronisation des entités à modifier par le système.
 * La fonction va rechercher les numéros d'entités à modifier, et les stocker dans mVectNumEntity.
 */
void System::refreshEntity(){

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
        mBitSetComponentSystem[ uiTypeComponent ] = true;

    }
    return bReturn;
}

/**
 * @brief System::bAlreadyExist Fonction vérifiant si le numéro de composant(paramètre)
 * est déja présent dans le tableau de stockage des composants(bitset).
 * @param uiTypeComponent Le numéro du composant à vérifier.
 * @return true si le composant est présent, false sinon.
 */
bool System::bComponentAlreadyExist( unsigned int uiTypeComponent ){
    return mBitSetComponentSystem[ uiTypeComponent ];
}
