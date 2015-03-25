#ifndef GRAVITYSYSTEM_H
#define GRAVITYSYSTEM_H

#include <tuple>
#include "system.hpp"

struct PositionComponent;
struct MoveableComponent;
struct GroundComponent;
struct DisplayComponent;

/**
 * @brief La classe GravitySystem gère la gravité sur les entités possédant les composants nécessaires.
 */
class GravitySystem : public System{
private:
    unsigned int muiValueGravity;
    std::vector< std::tuple< MoveableComponent *, PositionComponent *,
                             GroundComponent *, DisplayComponent *, unsigned int > > mVectTupleComponentGravitySystem;

public:
    GravitySystem();
    bool bSetGravityValue( unsigned int uiValueGravity );
    void recupComponentToEntity();
    void execSystem() override;
    //DisplayComponent est temporaire en attendant l'implémentation des masques de collision
    std::vector<std::tuple< MoveableComponent *, PositionComponent *, GroundComponent *, DisplayComponent *, unsigned int > > *getVectTupleComponentGravitySystem();
    ~GravitySystem();
};

#endif // GRAVITYSYSTEM_H
