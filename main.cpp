#include <iostream>
#include "engine.hpp"
#include "constantes.hpp"

int main()
{
    Engine engine;
    engine.AddEntity();
    engine.AddEntity();
    engine.AddEntity();
    if( ! engine.bAddComponentToEntity( 0, DISPLAY_COMPONENT ))std::cout<<"aa"<<std::endl;
    if( ! engine.bAddComponentToEntity( 0, POSITION_COMPONENT ))std::cout<<"bb"<<std::endl;
    engine.displayVectEntity();
    engine.RmAllEntity();
    return 0;
}

