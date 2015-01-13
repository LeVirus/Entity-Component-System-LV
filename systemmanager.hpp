#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

#include <vector>
#include "system.hpp"
#include <bitset>
#include <memory>

/**
 * @brief La classe SystemManager gère les systèmes actifs.
 * Elle contient un vector de System.
 *
 * Cette classe permet d'ajouter/supprimer les systèmes et de les exécuter.
 */
class SystemManager
{
    std::vector< std::unique_ptr< System > > mVectSystem;
    std::bitset< 16 > mBitSetSystem;
public:
    SystemManager();
    unsigned int uiGetNumCaseSystem( unsigned int uiIdSystem );
    bool bAddSystem( unsigned int uiIdSystem );
    bool bRmSystem( unsigned int uiIdSystem );
    void RmAllSystem();
    bool bExexSystem( unsigned int uiIdSystem );
    bool bExecAllSystem();
};

#endif // SYSTEMMANAGER_HPP
