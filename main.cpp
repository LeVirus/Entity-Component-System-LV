#include <iostream>
#include "engine.hpp"
#include "constantes.hpp"

int main(){

    Engine engine;
    engine.AddEntity();
    engine.AddEntity();
    engine.AddEntity();
    engine.bAddComponentToEntity( 1, DISPLAY_COMPONENT );
    engine.bAddComponentToEntity( 1, POSITION_COMPONENT );
    engine.bAddComponentToEntity( 2, DISPLAY_COMPONENT );
    engine.bAddComponentToEntity( 2, POSITION_COMPONENT );

    //engine.getSystemManager().bAddSystem( DISPLAY_SYSTEM ); // std::cout << "sdf" << std::endl;
    //engine.getSystemManager() . bExecAllSystem();
    //engine.getSystemManager().bRmSystem( DISPLAY_SYSTEM ); // std::cout << "sdf" << std::endl;
    //engine.getSystemManager() . bExecAllSystem();
     std::cout << "sdf" << std::endl;
    engine.getComponentManager().updateComponentFromEntity(); std::cout << "sdfdgf" << std::endl;
    engine.getComponentManager().displayComponent();
    return 0;
}

