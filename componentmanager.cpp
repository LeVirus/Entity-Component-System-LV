#include "componentmanager.hpp"
#include "engine.hpp"

ComponentManager::ComponentManager(){

}

/**
 * @brief ComponentManager::bUpdateComponentFromEntity Fonction de mise à jour des composants
 * a partir des caractéristiques des entités. La fonction va vérifier si le booléen (statique) est a true,
 * si ce n'est pas le cas la mise a jour ne sera pas effectué.
 * @return true si la mise à jour est effectuée, false sinon.
 */
bool ComponentManager::bUpdateComponentFromEntity(){
    const std::vector< Entity > & vectEntitycst = mptrEngine -> getVectEntity();
    for( unsigned int i = 0 ; i < vectEntitycst.size() ; ++i ){
        const std::bitset< NUMBR_COMPONENT > & bitsetComponent = vectEntitycst[ i ].getEntityBitSet();
        if(  )
    }
}

/**
 * @brief ComponentManager::linkEngineToComponentManager Fonction liant Engine à ComponentManager par un pointeur.
 * @param ptrEngine Un pointeur vers Engine
 */
void ComponentManager::linkEngineToComponentManager( Engine *ptrEngine ){
    mptrEngine = ptrEngine;
}


