#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

#include <vector>
#include "system.hpp"

/**
 * @brief La classe SystemManager gère les systèmes actifs.
 * Elle contient un vector de System.
 *
 * Cette classe permet d'ajouter/supprimer les systèmes et de les exécuter.
 */
class SystemManager
{
    std::vector< System > mVectSystem;
public:
    SystemManager();
    bool bSystemExist( unsigned int uiIdSystem );
    bool bAddSystem();
    bool bRmSystem( unsigned int uiIdSystem );
    void RmAllSystem();
    bool bExexSystem( unsigned int uiIdSystem );
    bool bExecAllSystem();
};

#endif // SYSTEMMANAGER_HPP
