#include "componentmanager.hpp"
#include "engine.hpp"
#include "entity.hpp"
#include <iostream>
#include <cassert>

namespace ecs
{

unsigned int ComponentManager::muiNumberComponent = 0;


ComponentManager::ComponentManager()
{
   muiNumberComponent = 0;
}

/**
 * @brief ComponentManager::bUpdateComponentFromEntity Fonction de mise à jour des composants
 * a partir des caractéristiques des entités. La fonction va vérifier sur chaque entité si elle est à jour,
 * si ce n'est pas le cas la fonction enchaine sur l'itération suivante.
 */
void ComponentManager::updateComponentFromEntity()
{
    const std::vector< Entity > & vectEntitycst = mptrEngine -> getVectEntity();
    //en cas de besoin resize du tableau de composants
    if(mVectComponent.size() < vectEntitycst.size() * muiNumberComponent){
        mVectComponent.resize(vectEntitycst.size() * muiNumberComponent);
    }
    for(unsigned int i = 0 ; i < vectEntitycst . size() ; ++i){
        //si l'entité est à jour
        if(vectEntitycst[i] . bEntityIsUpToDate())continue;
        const std::vector< bool > & bitsetComponent = vectEntitycst[i].getEntityBitSet();
        for(unsigned int j = 0 ; j < bitsetComponent.size() ; ++j)
        {
            //si la case du bitset est à false et que la case correspondante dans le vector de component est instanciée
            if(! bitsetComponent[j] && mVectComponent[i * muiNumberComponent + j])
            {
                mVectComponent[i * muiNumberComponent + j].reset();
            }
        }
    }
}

/**
 * @brief ComponentManager::bVerifComponentInstanciate La fonction vérifie si la case demandée est bien dans le tableau
 * dans un premier temps, et si le pointeur en question n'est pas NULL.
 * @param uiNumEntity le numéro de l'entité à qui appartient le composant.
 * @param uiTypeComponent Le type de composant demandé.
 * @return false si le pointeur est NULL, true sinon.
 */
bool ComponentManager::bVerifComponentInstanciate(unsigned int uiNumEntity,
                                                   unsigned int uiTypeComponent)
{
    if(uiNumEntity * muiNumberComponent + uiTypeComponent >= mVectComponent.size())
    {
        return false;
    }
    if(mVectComponent[uiNumEntity * muiNumberComponent + uiTypeComponent])
    {
        return true;
    }
    return false;
}

/**
 * @brief ComponentManager::addExternComponent
 * !!! L'appel de la fonction réinitialise le tableau de composants et la liste des systèmes!!!
 * A utiliser avant d'instancier les systèmes et les composants.
 * @param numberNewComponent
 */
void ComponentManager::addEmplacementsForExternComponent(unsigned int uiNumberExternalComponent)
{
    if(uiNumberExternalComponent == 0)return;
	muiNumberComponent += uiNumberExternalComponent;
	mVectComponent.clear();
	mptrEngine->getSystemManager().RmAllSystem();
}

void ComponentManager::instanciateExternComponent(unsigned int uiNumEntity,
                                                   std::unique_ptr<Component> ptrComp)
{
    if(ptrComp == nullptr)return;
	unsigned int typeComp = ptrComp.get()->muiGetTypeComponent(),
			uiEmplacementNewComp = uiNumEntity * muiNumberComponent + typeComp;
    assert(!(mVectComponent.size() <= uiEmplacementNewComp)
			&& "Instanciate extern component out of range\n");
    mVectComponent[uiEmplacementNewComp] = std::move(ptrComp);
}

unsigned int ComponentManager::getNumberComponent()
{
	return ComponentManager::muiNumberComponent;
}

/**
 * @brief ComponentManager::linkEngineToComponentManager Fonction liant Engine à ComponentManager par un pointeur.
 * @param ptrEngine Un pointeur vers Engine
 */
void ComponentManager::linkEngineToComponentManager(Engine *ptrEngine)
{
    mptrEngine = ptrEngine;
}


}//fin namespace
