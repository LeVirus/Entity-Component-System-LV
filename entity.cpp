#include <iostream>
#include "entity.hpp"
#include "ECSconstantes.hpp"

namespace ecs
{

/**
 * @brief Entity::Entity Constructeur de la classe Engine.
 */
Entity::Entity():mBitSetComponent(std::vector< bool >(ComponentManager::getNumberComponent()))
{
    initEntity();
}

/**
 * @brief Entity::Entity
 * @param uiIdEntity L'identifiant à attribuer à la nouvelle entité.
 */
Entity::Entity(unsigned int uiIdEntity):mUiIDEntity(uiIdEntity),
    mBitSetComponent(std::vector< bool >(ComponentManager::getNumberComponent()))
{
    initEntity();
}

/**
 * @brief initEntity Fonction initialisant les variables booléenne de la classe Entity
 */
void Entity::initEntity()
{
    mbActive = true;
    mbUpToDate = false;
    mbEntityInUse = true;
}

/**
 * @brief Entity::bInUse Fonction informant si l'emplacement de l'entité est utilisé.
 * @return Le booléen mbEntityInUse.
 */
bool Entity::bInUse()const
{
    return mbEntityInUse;
}

/**
 * @brief modifyEntityInUse Définie l'emplacement de l'entité comme libre:
 * en cas d'ajout d'une nouvelle entité cette dernière pourra être placé dans cet emplacement.
 * mBitSetComponent est remis à 0.
 * @param bInUse La nouvelle valeur à associé à mbEntityInUse
 */
void Entity::modifyEntityInUse(bool bInUse)
{
    if(! bInUse){
        reinitComponentBitSet();
        mbEntityInUse = bInUse;
        mbActive = false;
    }
    else {
        initEntity();
    }
}

/**
 * @brief Entity::setUpToDate Fonctionn modifiant la valeur de mbUpToDate a true.
 * Cette fonction est appelée aprés la mise à jour de ComponentManager sur toutes les entités.
 */
void Entity::setUpToDate()
{
    mbUpToDate = true;
}

/**
 * @brief attributeIDEntity
 * @param uiIdEntity L'identifiant à attribuer l'entité.
 */
void Entity::attributeIDEntity(unsigned int uiIdEntity)
{
    mUiIDEntity = uiIdEntity;
}

/**
 * @brief Entity::bEntityIsUpToDate Fonction de vérification si
 * l'entité est à mettre à jour dans ComponentManager.
 * @return true si une mise à jour est nécessaire, false sinon.
 */
bool Entity::bEntityIsUpToDate()const
{
    return mbUpToDate;
}

/**
 * @brief Entity::ComponentExist
 * Fonction vérifiant si le composant dont le type est envoyé en paramètre est bien présent dans l'entité.
 * @param uiTypeComponent le type de composant à vérifier.
 * @return true si le composant existe, false sinon
 */
bool Entity::ComponentExist(unsigned int uiTypeComponent)const
{
    //vérification de la présence du component dans le bitset
    if(uiTypeComponent < mBitSetComponent.size())
    {
        return mBitSetComponent[uiTypeComponent];
    }
    return false;
}

/**
 * @brief Entity::getEntityBitSet Fonction retournant le bitset(représentant les composants de l'entité) associé a l'entité.
 * @return Une référence constante du bitset.
 */
void Entity::reinitComponentBitSet()
{
    std::vector<bool>::iterator it = mBitSetComponent.begin();
    for(;it != mBitSetComponent.end();++it)
    {
        *it = false;
    }
}

const std::vector< bool > & Entity::getEntityBitSet()const
{
    return mBitSetComponent;
}

/**
 * @brief Entity::bEntityIsActive Fonction vérifiant si l'entité est activé
 * (si elle doit être traité par les systèmes).
 * @return true si l'entité est activée, false sinon.
 */
bool Entity::bEntityIsActive()const
{
    return mbActive;
}

/**
 * @brief Entity::bAddComponent Fonction d'ajout d'un composant dans l'entité.
 * @param uiTypeComponent le type de composant à créer.
 * @return true si le composant a été créé avec succés, false sinon.
 */
bool Entity::bAddComponent(unsigned int uiTypeComponent)
{
    bool bReturn = true;
     if(! bInUse() || uiTypeComponent >= mBitSetComponent . size())
     {
         bReturn = false;
     }
      if(bReturn && ! ComponentExist(uiTypeComponent)){
        bReturn = true;
        mBitSetComponent[uiTypeComponent] = true;
        mbUpToDate = false;
    }
    return bReturn;
}

/**
 * @brief Entity::bRmComponent Fonction de suppression d'un composant dans l'entité.
 * @param uiTypeComponent L'identifiant du composant a supprimer.
 * @return true si le composant a été trouvé, false sinon.
 */
bool Entity::bRmComponent(unsigned int uiTypeComponent)
{
    bool breturn = false;
    if(bInUse() && ComponentExist(uiTypeComponent))
    {
        mBitSetComponent[uiTypeComponent] = false;
        breturn = true;
        mbUpToDate = false;
    }
    return breturn;
}

/**
 * @brief Entity::bRmAllComponent Fonction supprimant tous les composants présents dans l"entité.
 * @return true si la suppression a été effectuée avec succés, false sinon.
 */
void Entity::RmAllComponent()
{
    reinitComponentBitSet();
    mbUpToDate = false;
}

}//fin namespace
