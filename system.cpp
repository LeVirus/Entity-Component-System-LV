#include "system.hpp"
#include "ECSconstantes.hpp"
#include "entity.hpp"
#include "engine.hpp"
#include <bitset>
#include <cassert>

namespace ecs
{

/**
 * @brief System::System Constructeur de la classe System
 */
System::System():mBitSetComponentSystem(std::vector<bool>(ComponentManager::getNumberComponent())),
    mptrSystemManager(nullptr)
{

}

const std::vector< unsigned int > &System::getVectNumEntity() const
{
	return mVectNumEntity;
}

/**
 * @brief SystemManager::linkEngine fonction envoyant un pointeur d'Engine à SystemManager.
 * @param ptrEngine Un pointeur d'Engine
 */
void System::linkSystemManager(SystemManager* ptrSystemManager)
{
    mptrSystemManager = ptrSystemManager;
}

/**
 * @brief System::refreshNode Fonction de synchronisation des entités à modifier par le système.
 * La fonction va rechercher les numéros d'entités à modifier, et les stocker dans mVectNumEntity.
 */
void System::refreshEntity()
{
    bool granted;
    const std::vector< Entity > & vectEntity = mptrSystemManager -> getptrEngine() -> getVectEntity();
    mVectNumEntity.clear();
    for(unsigned int i = 0 ; i < vectEntity . size() ; ++i)
    {
        granted = true;

        if(! vectEntity[i].bEntityIsActive())continue;
        //récupération du bitset de l'entité
        const std::vector< bool > & bitSetEntity = vectEntity[i] . getEntityBitSet();
        for(unsigned int j = 0 ; j < bitSetEntity.size() ; ++j)
        {
            //si le composant nécessaire au système n'est pas présent dans l'entité
            if(mBitSetComponentSystem[j] && !bitSetEntity[j])
            {
                granted = false;
                break;
            }
            if(mBitSetExcludeComponentSystem[j] && bitSetEntity[j])
            {
                granted = false;
                break;
            }
        }
        if(granted)
		{
            mVectNumEntity.emplace_back(i);
        }
    }
}

/**
 * @brief System::addComponentSystem Fonction d'ajout d'un composant au système.
 * @param uiTypeComponent le numéro du composant à intégrer dans le système.
 * @return false si le composant est déja présent ou si uiTypeComponent ne correspond à aucun composants
 * true sinon.
 */
void System::bAddComponentToSystem(unsigned int uiTypeComponent)
{
    assert(uiTypeComponent < mBitSetComponentSystem.size() && "Bad component number.");
    mBitSetComponentSystem[uiTypeComponent] = true;
}

void System::bAddExcludeComponentToSystem(unsigned int uiTypeComponent)
{
    assert(uiTypeComponent < mBitSetExcludeComponentSystem.size() && "Bad component number.");
    mBitSetExcludeComponentSystem[uiTypeComponent] = true;
}

/**
 * @brief System::execSystem Fonction de base d'execution d'un systeme. Cette fonction appelle System::refreshEntity.
 */
void System::execSystem()
{
    refreshEntity();
}

/**
 * @brief System::bAlreadyExist Fonction vérifiant si le numéro de composant(paramètre)
 * est déja présent dans le tableau de stockage des composants(bitset).
 * @param uiTypeComponent Le numéro du composant à vérifier.
 * @return true si le composant est présent, false sinon.
 */
bool System::bComponentAlreadyExist(unsigned int uiTypeComponent)
{
    return mBitSetComponentSystem[uiTypeComponent];
}

/**
 * @brief System::stairwayToComponentManager Fonction d'envoie d'une référence vers le gestionnaire de composant.
 * (Cette fonction a été faite pour une question de lisibilité du code).
 * @return Une référence vers le gestionnaire de composant(mComponentManager).
 */
ComponentManager & System::stairwayToComponentManager()
{
    assert(mptrSystemManager && "mptrSystemManager non instancié\n");
    return mptrSystemManager -> getptrEngine() -> getComponentManager();
}

}//fin namespace
