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
    engine.getSystemManager().bAddSystem( DISPLAY_SYSTEM );
    engine.getSystemManager().bAddSystem( IA_SYSTEM );
    compMan . updateComponentFromEntity();
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
    }

    MoveableComponent * moveComp = compMan . searchComponentByType< MoveableComponent >( 0, MOVEABLE_COMPONENT );

    engine.getSystemManager().searchSystemByType< IASystem >( IA_SYSTEM ) ->  initMoveable( behavComp, posComp, moveComp );
    compMan . displayComponent();
    return 0;
}
