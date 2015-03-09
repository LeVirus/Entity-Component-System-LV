#include <iostream>
#include "engine.hpp"
#include "ECSconstantes.hpp"
#include "componentmanager.hpp"
#include "positioncomponent.hpp"
#include "displaycomponent.hpp"
#include "behaviorcomponent.hpp"
#include "moveablecomponent.hpp"
#include "displaysystem.hpp"
#include "iasystem.hpp"

int main(){

    Engine engine;
    ComponentManager & compMan = engine.getComponentManager();
    engine.AddEntity();
    engine.AddEntity();
    engine.AddEntity();
    engine.bAddComponentToEntity( 0, DISPLAY_COMPONENT );
    engine.bAddComponentToEntity( 0, POSITION_COMPONENT );
    engine.bAddComponentToEntity( 0, BEHAVIOR_COMPONENT );
    engine.bAddComponentToEntity( 0, MOVEABLE_COMPONENT );
    //engine.bAddComponentToEntity( 2, DISPLAY_COMPONENT );
    //engine.bAddComponentToEntity( 2, POSITION_COMPONENT );
    //engine.displayVectEntity();
    //engine.bRmComponentToEntity( 2, POSITION_COMPONENT );
    //engine.bRmComponentToEntity( 1, POSITION_COMPONENT );
    //engine.bRmEntity( 0 );
    //engine.displayVectEntity();
    engine.getSystemManager().bAddSystem( DISPLAY_SYSTEM ); // std::cout << "sdf\n";
    engine.getSystemManager().bAddSystem( IA_SYSTEM ); // std::cout << "sdf\n";
    compMan . updateComponentFromEntity();
    //engine.execIteration();
    PositionComponent * posComp = compMan . searchComponentByType< PositionComponent >( 0, POSITION_COMPONENT );
    if( posComp ){
        posComp -> mfPositionX = 100;
        posComp -> mfPositionY = 158;
    }
    DisplayComponent * dispComp = compMan . searchComponentByType< DisplayComponent >( 0, DISPLAY_COMPONENT );
    if( dispComp ){
        dispComp -> muiNumSprite = 1;
    }
    BehaviorComponent * behavComp = compMan . searchComponentByType< BehaviorComponent >( 0, BEHAVIOR_COMPONENT );
    if( behavComp ){
        behavComp -> muiTypeBehavior = RING;
        //behavComp -> muiTypeBehavior = SINUSOIDAL;
        //behavComp -> muiTypeBehavior = ROUND_TRIP;
    }

    MoveableComponent * moveComp = compMan . searchComponentByType< MoveableComponent >( 0, MOVEABLE_COMPONENT );
    /*if( moveComp ){
        moveComp -> muiTypeBehavior = RING;
    }*/

    engine.getSystemManager().searchSystemByType< IASystem >( IA_SYSTEM ) ->  initMoveable( behavComp, posComp, moveComp );
    /*PositionComponent * posComp2 = compMan . searchComponentByType< PositionComponent >( 2, POSITION_COMPONENT );
    if( posComp2 ){
        posComp2 -> mfPositionX = 10;
        posComp2 -> mfPositionY = 298;
    }*/

    /*DisplayComponent * dispComp2 = compMan . searchComponentByType< DisplayComponent >( 2, DISPLAY_COMPONENT );
    if( dispComp2 ){
        dispComp2 -> muiNumSprite = 1;
    }*/
    compMan . displayComponent();

    //engine.bRmComponentToEntity( 2, POSITION_COMPONENT );
    engine.execIteration();
    engine.getSystemManager().searchSystemByType< IASystem >( IA_SYSTEM ) ->displaySystem();
    /*const std::multimap< DisplayComponent *, PositionComponent * > & multiMapDisplay = engine .getSystemManager().
            searchSystemByType < DisplaySystem > ( DISPLAY_SYSTEM ) -> getMapComponentDisplaySystem();
    for( std::multimap< DisplayComponent *, PositionComponent * >::const_iterator it = multiMapDisplay.begin() ;
         it != multiMapDisplay.end() ; ++it ){
       //std::cout << ( *it ) . first ->  << "  numSprite\n";
        ( *it ) . first -> displayComponent();
        ( *it ) . second -> displayComponent();
    }*/
    return 0;
}


 /* ComponentManager & compMan = mECSEngine.getComponentManager();
    mECSEngine.AddEntity();
    //mECSEngine.AddEntity();
    mECSEngine.bAddComponentToEntity( 0, DISPLAY_COMPONENT );
    mECSEngine.bAddComponentToEntity( 0, POSITION_COMPONENT );
    mECSEngine.bAddComponentToEntity( 0, BEHAVIOR_COMPONENT );
    mECSEngine.bAddComponentToEntity( 0, MOVEABLE_COMPONENT );
    //mECSEngine.bAddComponentToEntity( 1, DISPLAY_COMPONENT );
    //mECSEngine.bAddComponentToEntity( 1, POSITION_COMPONENT );
    if( ! mECSEngine.getSystemManager().bAddSystem( DISPLAY_SYSTEM ) ) std::cout << "Echec DisplaySystem non ajouté\n" ;
    if( ! mECSEngine.getSystemManager().bAddSystem( IA_SYSTEM ) ) std::cout << "Echec BehaviorSystem non ajouté\n" ;

    //mECSEngine.displayVectEntity();
    compMan . updateComponentFromEntity();


    //mECSEngine . getSystemManager() . searchSystemByType < DisplaySystem > ( DISPLAY_SYSTEM ) -> refreshEntity();
    //mECSEngine . getSystemManager() . searchSystemByType < IASystem > ( IA_SYSTEM ) -> refreshEntity();

    PositionComponent * posComp = compMan . searchComponentByType< PositionComponent >( 0, POSITION_COMPONENT );
    if( posComp ){
        posComp -> mfPositionX = 100;
        posComp -> mfPositionY = 158;
    }
    DisplayComponent * dispComp = compMan . searchComponentByType< DisplayComponent >( 0, DISPLAY_COMPONENT );
    if( dispComp ){
        dispComp -> muiNumSprite = 0;
    }
    BehaviorComponent * behavComp = compMan . searchComponentByType< BehaviorComponent >( 0, BEHAVIOR_COMPONENT );
    if( behavComp ){
        behavComp -> muiTypeBehavior = RING;
        //behavComp -> muiTypeBehavior = SINUSOIDAL;
        //behavComp -> muiTypeBehavior = ROUND_TRIP;
    }

    MoveableComponent * moveComp = compMan . searchComponentByType< MoveableComponent >( 0, MOVEABLE_COMPONENT );
    /*if( moveComp ){
        moveComp -> muiTypeBehavior = RING;
    }*/

    //mECSEngine.getSystemManager().searchSystemByType< IASystem >( IA_SYSTEM ) ->  initMoveable( behavComp, posComp, moveComp );

    /*PositionComponent * posComp2 = compMan . searchComponentByType< PositionComponent >( 2, POSITION_COMPONENT );
    if( posComp2 ){
        posComp2 -> mfPositionX = 10;
        posComp2 -> mfPositionY = 298;
    }*/

    /*DisplayComponent * dispComp2 = compMan . searchComponentByType< DisplayComponent >( 2, DISPLAY_COMPONENT );
    if( dispComp2 ){
        dispComp2 -> muiNumSprite = 1;
    }*/

    //mECSEngine.execIteration();
