#include <iostream>
#include "engine.hpp"
#include "ECSconstantes.hpp"
#include "componentmanager.hpp"
#include "positioncomponent.hpp"
#include "displaycomponent.hpp"
#include "displaysystem.hpp"

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
    engine.getSystemManager().bAddSystem( DISPLAY_SYSTEM ); // std::cout << "sdf\n";
    compMan . updateComponentFromEntity();
    //engine.execIteration();
    PositionComponent * posComp = compMan . searchComponentByType< PositionComponent >( 1, POSITION_COMPONENT );
    if( posComp ){
        posComp -> mfPositionX = 100;
        posComp -> mfPositionY = 158;
    }
    PositionComponent * posComp2 = compMan . searchComponentByType< PositionComponent >( 2, POSITION_COMPONENT );
    if( posComp2 ){
        posComp2 -> mfPositionX = 10;
        posComp2 -> mfPositionY = 298;
    }
    DisplayComponent * dispComp = compMan . searchComponentByType< DisplayComponent >( 1, DISPLAY_COMPONENT );
    if( dispComp ){
        dispComp -> muiNumSprite = 1;
    }
    DisplayComponent * dispComp2 = compMan . searchComponentByType< DisplayComponent >( 2, DISPLAY_COMPONENT );
    if( dispComp2 ){
        dispComp2 -> muiNumSprite = 1;
    }
    compMan . displayComponent();

    //engine.bRmComponentToEntity( 2, POSITION_COMPONENT );
    engine.execIteration();
    const std::multimap< unsigned int, PositionComponent * > & multiMapDisplay = engine .getSystemManager().
            searchSystemByType < DisplaySystem > ( DISPLAY_SYSTEM ) -> getMapComponentDisplaySystem();
    for( std::multimap< unsigned int, PositionComponent * >::const_iterator it = multiMapDisplay.begin() ;
         it != multiMapDisplay.end() ; ++it ){
        std::cout << ( *it ) . first << "  numSprite\n";
        //( *it ) . first -> displayComponent();
        ( *it ) . second -> displayComponent();
    }
    return 0;
}
