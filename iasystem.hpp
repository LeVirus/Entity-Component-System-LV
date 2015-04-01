#ifndef IASYSTEM_H
#define IASYSTEM_H

#include "system.hpp"

struct PositionComponent;
struct MoveableComponent;
struct BehaviorComponent;

/**
 * @brief La classe IASystem initialise et éxecute le comportement que doivent avoir les entités
 * en fonction de leurs caractéristiques présentes dans les différents composants.
 */
class IASystem : public System{
private:

    void initMoveableSinusoid( unsigned int uiNumEntity );
    void initMoveableRing( unsigned int uiNumEntity );
    void initMoveableRoundTrip( unsigned int uiNumEntity );

    void actionSinusoid( unsigned int uiNumEntity );
    void actionRing( unsigned int uiNumEntity );
    void actionRoundTrip( unsigned int uiNumEntity );

public:
    IASystem();
    void execSystem() override;
    bool initMoveable( unsigned int uiNumEntity );
    ~IASystem();
};

#endif // IASYSTEM_H
