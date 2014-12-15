#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "node.hpp"
#include <vector>

class System{
protected:
    unsigned int muiPriority, muiIdSystem, muiTypeSystem;
    //std::vector< Node > mVectNode;
    std::vector< unsigned int > mVectNode;
public:
    inline System(){}
    virtual void refreshNode() = 0;
    virtual void execSystem() = 0;
    virtual void displaySystem()const = 0;

    inline unsigned int uiGetPriority()const{ return muiPriority; }
    inline unsigned int uiGetIdSystem()const{ return muiIdSystem; }
    inline unsigned int uiGetTypeSystem()const{ return muiTypeSystem; }

    inline void modValuePriority( unsigned int uiPriority ){ muiPriority = uiPriority; }
    inline void modValueIdSystem( unsigned int uiIdSystem ){ muiIdSystem = uiIdSystem; }
    inline void modValueTypeSystem( unsigned int uiTypeSystem ){ muiTypeSystem = uiTypeSystem; }
};

#endif // SYSTEM_HPP
