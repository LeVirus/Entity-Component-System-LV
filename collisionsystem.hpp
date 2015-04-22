#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "bitset2d.hpp"

/**
 * @brief La classe CollisionSystem détermine les entités qui sont en collisions.
 * Un tableau détermine quelles type d'entité peut entrer en collision avec d'autres.
 */
class CollisionSystem{
private:
    BitSet2d mBitSet2dTagCollision;
    unsigned int muiNumberTag;
public:
    CollisionSystem();
    void bModifyNumberTag( unsigned int uiNumTag );
    void execSystem() override;
    bool attributeVectTabTagCollision(const std::vector< bool > & vectBool, unsigned int uiLenght );
};

#endif // COLLISIONSYSTEM_H
