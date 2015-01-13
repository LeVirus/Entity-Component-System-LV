#include <iostream>
#include "engine.hpp"
#include "constantes.hpp"

int main()
{
    Engine engine;
    engine.AddEntity();
    engine.AddEntity();
    engine.AddEntity();
    engine.displayVectEntity();
    engine.bAddComponentToEntity( 0, DISPLAY_COMPONENT );
    engine.bAddComponentToEntity( 0, POSITION_COMPONENT );
    engine.bAddComponentToEntity( 0, DISPLAY_COMPONENT );
    engine.bAddComponentToEntity( 0, DISPLAY_COMPONENT );
    engine.displayVectEntity();
    engine.RmAllEntity();
    return 0;
}

