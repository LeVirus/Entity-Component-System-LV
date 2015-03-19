#ifndef GRAVITYSYSTEM_H
#define GRAVITYSYSTEM_H

#include <tuple>
#include "system.hpp"

struct PositionComponent;
struct MoveableComponent;
struct GroundComponent;

/**
 * @brief La classe GravitySystem gère la gravité sur les entités possédant les composants nécessaires.
 */
class GravitySystem : public System{
private:
    unsigned int muiValueGravity;
    std::vector< std::tuple< MoveableComponent *, PositionComponent *, GroundComponent * > > mVectTupleComponentGravitySystem;

public:
    GravitySystem();
    bool bSetGravityValue( unsigned int uiValueGravity );
    void recupComponentToEntity();
    void execSystem() override;
    std::vector< std::tuple< MoveableComponent *, PositionComponent *, GroundComponent * > > * getVectTupleComponentGravitySystem();
    ~GravitySystem();
};

#endif // GRAVITYSYSTEM_H
