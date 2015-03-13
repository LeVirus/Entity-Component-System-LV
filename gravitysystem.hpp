#ifndef GRAVITYSYSTEM_H
#define GRAVITYSYSTEM_H

#include <map>
#include "system.hpp"

struct PositionComponent;
struct MoveableComponent;

/**
 * @brief La classe GravitySystem gère la gravité sur les entités possédant les composants nécessaires.
 */
class GravitySystem : public System{
private:
    unsigned int muiValueGravity;
    std::multimap< const MoveableComponent *, PositionComponent * > mMultiMapComponentGravitySystem;

public:
    GravitySystem();
    bool bSetGravityValue( unsigned int uiValueGravity );
    void execSystem() override;
    std::multimap<MoveableComponent *, PositionComponent *> &getMapComponentGravitySystem();
    ~GravitySystem();
};

#endif // GRAVITYSYSTEM_H
