#include <iostream>
#include "entity.hpp"
#include "constantes.hpp"
#include "displaycomponent.hpp"
#include "positioncomponent.hpp"

/**
 * @brief Entity::Entity Constructeur de la classe Engine.
 */
Entity::Entity(){

}

/**
 * @brief Entity::Entity
 * @param uiIdEntity L'identifiant à attribuer à la nouvelle entité.
 */
Entity::Entity( unsigned int uiIdEntity ){
    mUiIDEntity = uiIdEntity;
}

/**
 * @brief Entity::displayEntity Fonction d'affichage d'une entité.
 * Elle affiche l'ID de l'entité ainsi que la liste de ses composants.
 */
void Entity::displayEntity()const{
   std::cout << "Identifiant::" << mUiIDEntity << std::endl;
   //A compléter pour afficher les composants
   for( unsigned int i = 0 ; i < mVectComponent.size() ; ++i ){
       mVectComponent[ i ] -> displayComponent();
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
 * @brief Entity::searchCaseComponent
 * Fonction recherchant l'emplacement du composant dont le type est envoyé en paramètre.
 * @param uiTypeComponent le type de composant a rechercher.
 * @return Le numéro de la case ou est présent le composants,
 * 1000( COMPONENT_NOT_FOUND ) si le composant n'a pas été trouvée.
 */
unsigned int Entity::searchCaseComponent( unsigned int uiTypeComponent )const{
    for( unsigned int i = 0 ; i < mVectComponent.size() ; ++i ){
        if ( mVectComponent[ i ] -> muiGetTypeComponent() == uiTypeComponent ){
            return i;
        }
    }
    return COMPONENT_NOT_FOUND;
}

/**
 * @brief Entity::bAddComponent Fonction d'ajout d'un composant dans l'entité.
 * @param uiTypeComponent le type de composant à créer.
 * @return true si le composant a été créé avec succés, false sinon.
 */
bool Entity::bAddComponent( unsigned int uiTypeComponent ){
    bool breturn = true;
    if( searchCaseComponent( uiTypeComponent ) != COMPONENT_NOT_FOUND ){
        return false;
    }

    switch( uiTypeComponent ){
    case DISPLAY_COMPONENT :{
        //std::unique_ptr< DisplayComponent > ptrDC( new DisplayComponent );
        mVectComponent.push_back( std::make_unique< DisplayComponent >() );
        break;
    }
    case POSITION_COMPONENT :{
        // mVectComponent.push_back( PositionComponent() );
        mVectComponent.push_back( std::make_unique< PositionComponent >() );
        break;
    }
    default :{
        breturn = false;
        break;
    }
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
    unsigned int uiCaseComponent = searchCaseComponent( uiTypeComponent );
    if( uiCaseComponent != COMPONENT_NOT_FOUND ){
        mVectComponent.erase( mVectComponent.begin() + uiCaseComponent );
        breturn = true;
    }
    return breturn;
}

/**
 * @brief Entity::bRmAllComponent Fonction supprimant tous les composants présents dans l"entité.
 * @return true si la suppression a été effectuée avec succés, false sinon.
 */
void Entity::RmAllComponent(){
    mVectComponent.clear();
}
