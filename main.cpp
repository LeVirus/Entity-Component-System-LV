#include <iostream>
#include "engine.hpp"
#include "constantes.hpp"
#include "componentmanager.hpp"
#include "positioncomponent.hpp"
#include "displaycomponent.hpp"

int main(){

    Engine engine;
    ComponentManager & compMan = engine.getComponentManager();
    engine.AddEntity();
    engine.AddEntity();
    engine.AddEntity();
    engine.bAddComponentToEntity( 1, DISPLAY_COMPONENT );
    engine.bAddComponentToEntity( 1, POSITION_COMPONENT );
    engine.bAddComponentToEntity( 2, DISPLAY_COMPONENT );
    engine.bAddComponentToEntity( 2, POSITION_COMPONENT );
    //engine.displayVectEntity();
    //engine.bRmComponentToEntity( 2, POSITION_COMPONENT );
    //engine.bRmComponentToEntity( 1, POSITION_COMPONENT );
    engine.bRmEntity( 0 );
    //engine.displayVectEntity();
    engine.getSystemManager().bAddSystem( DISPLAY_SYSTEM ); // std::cout << "sdf" << std::endl;
    PositionComponent * posComp = compMan . searchComponentByType< PositionComponent >( 1, POSITION_COMPONENT );
    posComp -> mfPositionX = 100;
    posComp -> mfPositionY = 158;
    PositionComponent * posComp2 = compMan . searchComponentByType< PositionComponent >( 2, POSITION_COMPONENT );
    posComp2 -> mfPositionX = 10;
    posComp2 -> mfPositionY = 298;
    DisplayComponent * dispComp = compMan . searchComponentByType< DisplayComponent >( 1, DISPLAY_COMPONENT );
    dispComp -> muiNumSprite = 3;
    DisplayComponent * dispComp2 = compMan . searchComponentByType< DisplayComponent >( 2, DISPLAY_COMPONENT );
    dispComp2 -> muiNumSprite = 8;
    compMan . displayComponent();

    //engine.bRmComponentToEntity( 2, POSITION_COMPONENT );
    engine.execIteration();
    return 0;
}

