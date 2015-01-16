#include <iostream>
#include "engine.hpp"
#include "constantes.hpp"

int main()
{
    Engine engine;
    engine.AddEntity();
    engine.AddEntity();
    engine.AddEntity();
    engine.bAddComponentToEntity( 1, DISPLAY_COMPONENT );
    engine.bAddComponentToEntity( 1, POSITION_COMPONENT );
    engine.bAddComponentToEntity( 2, DISPLAY_COMPONENT );
    engine.bAddComponentToEntity( 2, POSITION_COMPONENT );
    //engine.displayVectEntity();
    engine.GetSystemManager().bAddSystem( DISPLAY_SYSTEM ); // std::cout << "sdf" << std::endl;
    engine.GetSystemManager() . bExecAllSystem();
    engine.GetSystemManager().bRmSystem( DISPLAY_SYSTEM ); // std::cout << "sdf" << std::endl;
    engine.GetSystemManager() . bExecAllSystem();
    return 0;
}

