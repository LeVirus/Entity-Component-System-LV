#ifndef IASYSTEM_H
#define IASYSTEM_H

#include "system.hpp"

struct PositionComponent;
struct MoveableComponent;
struct BehaviorComponent;

/**
 * @brief La classe IASystem éxecute le comportement que doivent avoir les entités,
 * en fonction de leurs caractéristiques présentes dans les différents composants.
 */
class IASystem : public System{
private:

    void initMoveableSinusoid( PositionComponent * posComp, MoveableComponent * moveComp );
    void initMoveableRing( PositionComponent * posComp, MoveableComponent * moveComp );
    void initMoveableRoundTrip( PositionComponent * posComp, MoveableComponent * moveComp );

    void actionSinusoid( PositionComponent * posComp, MoveableComponent * moveComp );
    void actionRing( PositionComponent * posComp, MoveableComponent * moveComp );
    void actionRoundTrip( PositionComponent * posComp, MoveableComponent * moveComp );

    bool bVerifExceedingMovement( float fOriginX, float fOriginY, float fDestinationX, float fDestinationY, float fAngle );
public:
    IASystem();
    void execSystem() override;
    bool initMoveable( BehaviorComponent *behavComp, PositionComponent * posComp, MoveableComponent * moveComp );
    void moveEntityAngle( PositionComponent * posComp, float fNbrPixels, float fAngle );
    void moveEntity( PositionComponent * posComp, float fNbrPixelsX, float fNbrPixelsY );
    void positionEntity( PositionComponent * posComp, float fPosX, float fPosY );
    ~IASystem();
};

#endif // IASYSTEM_H
