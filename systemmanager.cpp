#include "systemmanager.hpp"
#include "ECSconstantes.hpp"
#include <memory>
#include <cassert>
#include <iostream>

namespace ecs
{

/**
 * @brief SystemManager::SystemManager Constructeur de la classe SystemManager.
 */
SystemManager::SystemManager()
{
}

/**
 * @brief SystemManager::linkEngine fonction envoyant un pointeur d'Engine à SystemManager.
 * @param ptrEngine Un pointeur d'Engine
 */
void SystemManager::linkEngine(Engine* ptrEngine)
{
    mptrEngine = ptrEngine;
}

/**
 * @brief SystemManager::bAddExternSystem Ajout d'un système implémenté en dehors de la bibliothèque.
 * @param newSystem Le pointeur du nouveau système.
 * @return true si le systeme a été créer avec succés, false sinon
 */
bool SystemManager::bAddExternSystem(std::unique_ptr<System> newSystem)
{
    if(newSystem == nullptr || muiNumberSystem >= ecs::NUMBR_SYSTEM_MAX)return false;
    mVectSystem.push_back(std::move(newSystem));
    mVectSystem[mVectSystem.size() - 1]->linkSystemManager(this);
	return true;
}

/**
 * @brief SystemManager::getptrEngine fonction renvoyant un pointeur vers Engine.
 * @return Un pointeur vers Engine.
 */
Engine* SystemManager::getptrEngine()
{
    return mptrEngine;
}

/**
 * @brief SystemManager::bRmAllSystem Fonction supprimant tous les systèmes de SystemManager.
 */
void SystemManager::RmAllSystem()
{
    mVectSystem.clear();
}

/**
 * @brief SystemManager::bExecAllSystem Fonction déclanchant les exécutions de tous les systèmes présents dans SystemManager.
 * @return false si la liste des système est vide, true sinon.
 */
void SystemManager::bExecAllSystem()
{
    for(unsigned int i = 0 ; i < mVectSystem.size() ; ++i)
	{
        if(mVectSystem[i])
		{
            mVectSystem[i]->execSystem();
        }
    }
}

}//fin namespace
