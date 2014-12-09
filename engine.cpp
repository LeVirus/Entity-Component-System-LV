#include "engine.hpp"
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
 * @brief Engine::bRmAllEntity Fonction supprimant toutes les entitées présentes dans Engine.
 * @return true si la suppression a été effectuée avec succés, false sinon.
 */
void Engine::RmAllEntity(){
    mVectEntity.clear();
}
