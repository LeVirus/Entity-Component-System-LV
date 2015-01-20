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
    //engine.displayVectEntity();
    //engine.bRmComponentToEntity( 2, POSITION_COMPONENT );
    engine.bRmComponentToEntity( 1, POSITION_COMPONENT );
    engine.bRmEntity( 0 );
    engine.displayVectEntity();
    engine.getSystemManager().bAddSystem( DISPLAY_SYSTEM ); // std::cout << "sdf" << std::endl;
    engine.execIteration();
    engine.bRmComponentToEntity( 2, POSITION_COMPONENT );
    engine.execIteration();
    return 0;
}

