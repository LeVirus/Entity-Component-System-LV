#include "engine.hpp"
#include "ECSconstantes.hpp"
#include <iostream>

namespace ecs
{

/**
 * @brief Engine::Engine Constructeur de la classe Engine.
 */
Engine::Engine(){
    mSystemManager.linkEngine( this );
    mComponentManager.linkEngineToComponentManager( this );
}

/**
 * @brief Engine::bAddEntity Fonction d'ajout d'une entité dans le conteneur.
 * @return true Le numéro de case ou a été créé ou placer la nouvelle entité.
 */
unsigned int Engine::AddEntity(){
    for( unsigned int i = 0 ; i < mVectEntity.size() ; ++i ){
       if( ! mVectEntity[ i ] . bInUse() ){
           mVectEntity[ i ] . modifyEntityInUse( true );
           return i;
       }
    }
    mVectEntity.push_back( Entity( mVectEntity.size() ) );
    return mVectEntity.size() - 1;
}

/**
 * @brief Engine::getVectEntity Fonction retournant le vector d'entité en référence constante.
 * @return Une référence constante du vector d'entité.
 */
const std::vector<Entity> & Engine::getVectEntity()const{
   return mVectEntity;
}

/**
 * @brief Engine::bRmEntity Fonction de suppression d'une entité dans le conteneur.
 * L'entité n'est pas supprimée de la mémoire, le booléen bEntityInUse est mis à true.
 * @param uiIdEntity Le numéro d'identifiant unique qui sera attribué à l'entité.
 * @return true si l'entité a été supprimé avec succés, false sinon.
 */
bool Engine::bRmEntity( unsigned int uiIdEntity ){
    bool bReturn = false;
    if( uiIdEntity < mVectEntity.size() ){
        mVectEntity[ uiIdEntity ] . modifyEntityInUse( false );
    //bRmAllComponentToEntity(uiIdEntity);
        bReturn = true;
    }
    return bReturn;
}

/**
 * @brief Engine::displayVectEntity fonction d'affichage des entités présente dans le vector.
 */
void Engine::displayVectEntity()const{
    std::cout << "DEBUT AFFICHAGE\n" ;
    std::cout << "Taille vector::  " << mVectEntity.size() << "\n" ;
    for( unsigned int i = 0 ; i < mVectEntity.size() ; ++i ){
        if( ! mVectEntity[ i ] . bInUse() )std::cout << i << "  Entité libre\n" ;
        else mVectEntity[ i ].displayEntity();
    }
    std::cout << "FIN AFFICHAGE\n" ;
}

/**
 * @brief Engine::setEntityUpToDate Appel de la fonction setUpToDate sur toutes les entités.
 */
void Engine::setEntityUpToDate(){
    for( unsigned int i = 0 ; i < mVectEntity.size() ; ++i ){
        //informer l'entité que celle ci est à jour dans ComponentManager
        mVectEntity[ i ] . setUpToDate();
    }
}

/**
 * @brief Engine::execIteration Exécution d'une itération. Appel des fonctions de mise a jours des composants,
 * d'exécution des systèmes(en passant par une mise à jour des entités à traiter), et modification
 * de l'état(booléen) des entités en "UpToDate".
 */
void Engine::execIteration(){
    mComponentManager . updateComponentFromEntity();
    mSystemManager . bExecAllSystem();
    setEntityUpToDate();
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
 * @brief Engine::bAddComponentToEntity Fonction d'ajout d'un composant à une entité présente dans Engine.
 * La fonction vérifie si l'entité est bien présente dans le vector.
 * @param uiIdEntity Le numéro de l'entité à modifier.
 * @param uiTypeComponent Le numéro du type de composant à ajouter à l'entité.
 * @return true si le composant a été ajouté avec succés, false sinon.
 */
bool Engine::bAddComponentToEntity( unsigned int uiIdEntity, unsigned int uiTypeComponent ){
    bool bReturn = true;
    //vérification si l'entité demandé est bien dans le vector
    if( uiIdEntity >= mVectEntity.size() ){
        bReturn = false;
        std::cout << "false" << std::endl;
    }
    //vérification si le composant a ajouter n'est pas déja dans l'entité
    if( ! bReturn || ! mVectEntity[ uiIdEntity ].bAddComponent( uiTypeComponent ) ){
        std::cout << "false2" << std::endl;
        bReturn = false;
    }
    return bReturn;
}

/**
 * @brief Engine::bRmComponentToEntity Fonction de suppression d'un component à une entité.
 * La fonction vérifie si l'entité est bien présente dans le vector.
 * @param uiIdEntity Le numéro de l'entité à modifier.
 * @param uiTypeComponent Le numéro du type de composant à ajouter à l'entité.
 * @return true si le composant a bien été supprimé, false sinon.
 */
bool Engine::bRmComponentToEntity( unsigned int uiIdEntity, unsigned int uiTypeComponent ){
    bool bReturn = true;
    //vérification si l'entité demandé est bien dans le vector
    if( uiIdEntity >= mVectEntity.size() ){
        bReturn = false;
        std::cout << "false" << std::endl;
    }
    //vérification si le composant a supprimer existe bien dans l'entité
    if( ! bReturn || ! mVectEntity[ uiIdEntity ].bRmComponent( uiTypeComponent ) ){
        std::cout << "false2" << std::endl;
        bReturn = false;
    }
    return bReturn;
}

/**
 * @brief Engine::bRmAllEntity Fonction supprimant toutes les entitées présentes dans Engine.
 */
void Engine::RmAllEntity(){
	std::vector<Entity>::const_iterator it = mVectEntity.begin();
	for(;it != mVectEntity.end();++it)
	{
		bRmEntity((*it).muiGetIDEntity());
	}
	mVectEntity.clear();
}

/**
 * @brief Engine::GetSystemManager Fonction renvoyant une référence de mSystemManager.
 * @return Une référence du SystemManager.
 */
SystemManager &Engine::getSystemManager(){
    return mSystemManager;
}

/**
 * @brief Engine::getComponentManager Fonction renvoyant une référence de mComponentManager.
 * @return Une référence du ComponentManager.
 */
ComponentManager &Engine::getComponentManager(){
    return mComponentManager;
}

}//fin namespace
