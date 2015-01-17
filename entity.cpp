#include <iostream>
#include "entity.hpp"
#include "constantes.hpp"
#include "displaycomponent.hpp"
#include "positioncomponent.hpp"

/**
 * @brief Entity::Entity Constructeur de la classe Engine.
 */
Entity::Entity(){
    mbActive = false;
    mVectComponent.resize( NUMBR_COMPONENT );
    mbUpToDate = false;
}

/**
 * @brief Entity::Entity
 * @param uiIdEntity L'identifiant à attribuer à la nouvelle entité.
 */
Entity::Entity( unsigned int uiIdEntity ){
    mUiIDEntity = uiIdEntity;
    mVectComponent.resize( NUMBR_COMPONENT );
    mbUpToDate = false;
}

/**
 * @brief Entity::displayEntity Fonction d'affichage d'une entité.
 * Elle affiche l'ID de l'entité ainsi que la liste de ses composants.
 */
void Entity::displayEntity()const{
   std::cout << "Identifiant::" << mUiIDEntity << std::endl;
   for( unsigned int i = 0 ; i < mVectComponent.size() ; ++i ){
       if( NULL != mVectComponent[ i ] )mVectComponent[ i ] -> displayComponent();
   }
}

/**
 * @brief attributeIDEntity
 * @param uiIdEntity L'identifiant à attribuer l'entité.
 */
void Entity::attributeIDEntity( unsigned int uiIdEntity ){
    mUiIDEntity = uiIdEntity;
}

/**
 * @brief Entity::bEntityIsUpToDate Fonction de vérification si
 * l'entité est à mettre à jour dans ComponentManager.
 * @return true si une mise à jour est nécessaire, false sinon.
 */
bool Entity::bEntityIsUpToDate()const{
    return mbUpToDate;
}

/**
 * @brief Entity::ComponentExist
 * Fonction vérifiant si le composant dont le type est envoyé en paramètre est bien présent dans l'entité.
 * @param uiTypeComponent le type de composant à vérifier.
 * @return true si le composant existe, false sinon
 */
bool Entity::ComponentExist( unsigned int uiTypeComponent )const{
    //vérification de la présence du component dans le bitset
    bool bReturn = false;
    if( uiTypeComponent < mBitSetComponent.size() && mBitSetComponent[ uiTypeComponent ] == true ){
        bReturn = true;
    }
    return bReturn;
}

/**
 * @brief Entity::getEntityBitSet Fonction retournant le bitset(représentant les composants de l'entité) associé a l'entité.
 * @return Une référence constante du bitset.
 */
const std::bitset< NUMBR_COMPONENT > & Entity::getEntityBitSet()const{
    return mBitSetComponent;
}

/**
 * @brief Entity::bEntityIsActive Fonction de vérifiant si l'entité est activé
 * (si elle doit être traité par les systèmes)
 * @return true si l'entité est activée, false sinon.
 */
bool Entity::bEntityIsActive()const{
    return mbActive;
}

/**
 * @brief Entity::bAddComponent Fonction d'ajout d'un composant dans l'entité.
 * @param uiTypeComponent le type de composant à créer.
 * @return true si le composant a été créé avec succés, false sinon.
 */
bool Entity::bAddComponent( unsigned int uiTypeComponent ){
    bool breturn = false;
    if( ! ComponentExist( uiTypeComponent ) ){
        breturn = true;
        mBitSetComponent[ uiTypeComponent ] = true;

        switch( uiTypeComponent ){
        case DISPLAY_COMPONENT :{
            mVectComponent[ DISPLAY_COMPONENT ] = std::make_unique< DisplayComponent >();
            break;
        }
        case POSITION_COMPONENT :{
            mVectComponent[ POSITION_COMPONENT ] = std::make_unique< PositionComponent >();
            break;
        }
        default :{
            breturn = false;
            break;
        }
        }
        mbUpToDate = false;
    }
    return breturn;
}

/**
 * @brief Entity::bRmComponent Fonction de suppression d'un composant dans l'entité.
 * @param uiTypeComponent L'identifiant du composant a supprimer.
 * @return true si le composant a été trouvé, false sinon.
 */
bool Entity::bRmComponent( unsigned int uiTypeComponent ){
    bool breturn = false;
    if( ComponentExist( uiTypeComponent ) ){
        mVectComponent[ uiTypeComponent ].reset();
        mBitSetComponent[ uiTypeComponent ] = false;
        breturn = true;
        mbUpToDate = false;
    }
    return breturn;
}

/**
 * @brief Entity::bRmAllComponent Fonction supprimant tous les composants présents dans l"entité.
 * @return true si la suppression a été effectuée avec succés, false sinon.
 */
void Entity::RmAllComponent(){
    for( unsigned int i = 0 ; i < mVectComponent.size() ; ++i ){
        mVectComponent[ i ].reset();
    }
    mBitSetComponent.reset();
    mbUpToDate = false;
}
