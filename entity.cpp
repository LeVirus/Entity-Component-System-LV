#include <iostream>
#include "entity.hpp"

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
}

/**
 * @brief attributeIDEntity
 * @param uiIdEntity L'identifiant à attribuer l'entité.
 */
void Entity::attributeIDEntity( unsigned int uiIdEntity ){
    mUiIDEntity = uiIdEntity;
}

/**
 * @brief Entity::bAddComponent Fonction d'ajout d'un composant dans l'entité.
 * @return true si le composant a été créé avec succés, false sinon.
 */
bool Entity::bAddComponent(){

}

/**
 * @brief Entity::bRmComponent Fonction de suppression d'un composant dans l'entité.
 * @param uiIdComponent L'identifiant du composant a supprimer.
 * @return true si le composant a été trouvé, false sinon.
 */
bool Entity::bRmComponent( unsigned int uiIdComponent ){

}

/**
 * @brief Entity::bRmAllComponent Fonction supprimant tous les composants présents dans l"entité.
 * @return true si la suppression a été effectuée avec succés, false sinon.
 */
void Entity::RmAllComponent(){
    mVectComponent.clear();
}
