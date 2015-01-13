#include "engine.hpp"
#include "constantes.hpp"
#include <iostream>

/**
 * @brief Engine::Engine Constructeur de la classe Engine.
 */
Engine::Engine(){

}

/**
 * @brief Engine::bAddEntity Fonction d'ajout d'une entité dans le conteneur.
 * @return true si l'entité a été créée avec succés, false sinon.
 */
void Engine::AddEntity(){
    mVectEntity.push_back( Entity( mVectEntity.size() ) );
}

/**
 * @brief Engine::bRmEntity Fonction de suppression d'une entité dans le conteneur.
 * La fonction synchronizeVectorEntity est appelée.
 * @param uiIdEntity Le numéro d'identifiant unique qui sera attribué à l'entité.
 * @return true si l'entité a été supprimé avec succés, false sinon.
 */
bool Engine::bRmEntity( unsigned int uiIdEntity ){
    bool bReturn = false;
    if( uiIdEntity < mVectEntity.size() ){
        mVectEntity.erase( mVectEntity.begin() + uiIdEntity );
        synchronizeVectorEntity();
        bReturn = true;
    }
    return bReturn;
}

/**
 * @brief Engine::displayVectEntity fonction d'affichage des entités présente dans le vector.
 */
void Engine::displayVectEntity()const{
    for( unsigned int i = 0 ; i < mVectEntity.size() ; ++i ){
        mVectEntity[ i ].displayEntity();
    }
    std::cout << "FIN AFFICHAGE" << std::endl;
}

/**
 * @brief Engine::synchronizeVectorEntity Fonction de synchronisation entre les identifiants unique
 * des entités et les numéro de case du vector.
 */
void Engine::synchronizeVectorEntity(){
    for( unsigned int i = 0 ; i < mVectEntity.size() ; ++i ){
        mVectEntity[ i ].attributeIDEntity( i );
    }
}

/**
 * @brief Engine::bAddComponentToEntity Fonction d'ajout d'un composant a une entité présente dans Engine.
 * La fonction vérifie si l'entité est bien présente dans le vector, et si le composant n'est pas déja dans l'entité.
 * @param uiIdEntity Le numéro de l'entité à modifier.
 * @return true si le composant a été ajouté avec succés, false sinon.
 */
bool Engine::bAddComponentToEntity( unsigned int uiIdEntity, unsigned int uiTypeComponent ){
    bool bReturn = true;
    //vérification si l'entité demandé est bien dans le vector
    if( uiIdEntity >= mVectEntity.size() ){
        bReturn = false;
    }
    //vérification si le composant a ajouter n'est pas déja dans l'entité
    if( bReturn && ! mVectEntity[ uiIdEntity ].bAddComponent( uiTypeComponent ) ){
        bReturn = false;
    }
    return bReturn;
}


/**
 * @brief Engine::bRmAllEntity Fonction supprimant toutes les entitées présentes dans Engine.
 * @return true si la suppression a été effectuée avec succés, false sinon.
 */
void Engine::RmAllEntity(){
    mVectEntity.clear();
}
