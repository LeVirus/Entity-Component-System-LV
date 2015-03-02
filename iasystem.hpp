#ifndef IASYSTEM_H
#define IASYSTEM_H

#include "system.hpp"

struct PositionComponent;
struct MoveableComponent;

/**
 * @brief La classe IASystem éxecute le comportement que doivent avoir les entités,
 * en fonction de leurs caractéristiques présentes dans les différents composants.
 */
class IASystem : public System{
private:
    void moveEntityAngle( PositionComponent * posComp, float fNbrPixels, float fAngle );
    void moveEntity( PositionComponent * posComp, float fNbrPixelsX, float fNbrPixelsY );
public:
    IASystem();
    void execSystem() override;
    void actionSinusoid( PositionComponent * posComp, MoveableComponent * moveComp );
    void actionRing( PositionComponent * posComp, MoveableComponent * moveComp );
    void initMoveable( unsigned int uiNumBehavior, PositionComponent * posComp, MoveableComponent * moveComp );
    void initMoveableSinusoid( PositionComponent * posComp, MoveableComponent * moveComp );
    void initMoveableRing( PositionComponent * posComp, MoveableComponent * moveComp );
    ~IASystem();
};

#endif // IASYSTEM_H
