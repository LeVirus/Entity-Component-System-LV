#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "node.hpp"
//#include "systemmanager.hpp"
#include <vector>
#include <bitset>
#include <memory>

class SystemManager;

/**
 * @brief La classe System est la classe mère(abstraite) de tous système.
 * Cette classe permet de récupération des composants nécessaires de chaque entités.
 */
class System{
protected:
    unsigned int muiPriority, muiIdSystem, muiTypeSystem;
    //std::vector< Node > mVectNode;
    std::vector< unsigned int > mVectTypeComponent;
    std::bitset< 16 > mBitSetComponentSystem;
    std::unique_ptr< SystemManager > mptrSystemManager;
    bool bAddComponentToSystem( unsigned int uiTypeComponent );
public:
    System();
    void linkSystemManager( std::unique_ptr< SystemManager > ptrSystemManager );
    bool bRefreshNode();
    virtual void execSystem() = 0;
    void displaySystem()const;
    bool bComponentAlreadyExist( unsigned int uiTypeComponent );

    inline unsigned int uiGetPriority()const{ return muiPriority; }
    inline unsigned int uiGetIdSystem()const{ return muiIdSystem; }
    inline unsigned int uiGetTypeSystem()const{ return muiTypeSystem; }

    inline void modValuePriority( unsigned int uiPriority ){ muiPriority = uiPriority; }
    inline void modValueIdSystem( unsigned int uiIdSystem ){ muiIdSystem = uiIdSystem; }
    inline void modValueTypeSystem( unsigned int uiTypeSystem ){ muiTypeSystem = uiTypeSystem; }
};

#endif // SYSTEM_HPP
