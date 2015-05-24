#include <iostream>
#include "engine.hpp"
#include "ECSconstantes.hpp"
#include "componentmanager.hpp"
#include "positioncomponent.hpp"
#include "displaycomponent.hpp"
#include "behaviorcomponent.hpp"
#include "moveablecomponent.hpp"
#include "displaysystem.hpp"
#include "collrectboxcomponent.hpp"
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
    engine.bAddComponentToEntity( 0, SINUSOID_BEHAVIOR_COMPONENT );
    engine.bAddComponentToEntity( 1, POSITION_COMPONENT );
    engine.bAddComponentToEntity( 1, COLL_RECTBOX_COMPONENT );
    engine.bAddComponentToEntity( 2, POSITION_COMPONENT );
    engine.bAddComponentToEntity( 2, COLL_RECTBOX_COMPONENT );

    /*engine.getSystemManager().bAddSystem( DISPLAY_SYSTEM );
    engine.getSystemManager().bAddSystem( IA_SYSTEM );
    engine.getSystemManager().bAddSystem( GRAVITY_SYSTEM );*/
    engine.getSystemManager().bAddSystem( COLLISION_SYSTEM );
    compMan . updateComponentFromEntity();
    PositionComponent * posComp = compMan . searchComponentByType< PositionComponent >( 1, POSITION_COMPONENT );
    if( posComp ){
        posComp -> vect2DPosComp . mfX = 100;
        posComp -> vect2DPosComp . mfY = 158;
    }

    PositionComponent * posCompB = compMan . searchComponentByType< PositionComponent >( 2, POSITION_COMPONENT );
    if( posCompB ){
        posCompB -> vect2DPosComp . mfX = 100;
        posCompB -> vect2DPosComp . mfY = 158;
    }

    CollRectBoxComponent * collRect = compMan . searchComponentByType< CollRectBoxComponent >( 1, COLL_RECTBOX_COMPONENT );
    if( collRect ){
        collRect -> mRectBox . modifyOriginsRectBox( Vector2D( 10, 10 ) );
        collRect -> mRectBox . modifyHeightRectBox( 10 );
        collRect -> mRectBox . modifyLenghtRectBox( 10 );
    }
    CollRectBoxComponent * collRectB = compMan . searchComponentByType< CollRectBoxComponent >( 2, COLL_RECTBOX_COMPONENT );
    if( collRectB ){
        collRectB -> mRectBox . modifyOriginsRectBox( Vector2D( 10, 10 ) );
        collRectB -> mRectBox . modifyHeightRectBox( 10 );
        collRectB -> mRectBox . modifyLenghtRectBox( 10 );
    }


    //MoveableComponent * moveComp = compMan . searchComponentByType< MoveableComponent >( 0, MOVEABLE_COMPONENT );

    //engine.getSystemManager().searchSystemByType< IASystem >( IA_SYSTEM ) ->  initMoveable( 0 );
    engine.execIteration();
    compMan . displayComponent();
    return 0;
}
