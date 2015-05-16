#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "bitset2d.hpp"
#include "system.hpp"

/**
 * @brief La classe CollisionSystem détermine les entités qui sont en collisions.
 * Un tableau détermine quelles type d'entité peut entrer en collision avec d'autres.
 */
class CollisionSystem : System{
private:
    BitSet2d mBitSet2dTagCollision, mBitSet2dInCollision;
    unsigned int muiNumberTag;
    ComponentManager * mCompManager;
public:
    CollisionSystem();
    void bModifyNumberTag( unsigned int uiNumTag );
    void execSystem() override;
    bool bEntityIsInCollision( unsigned int uiEntityA, unsigned int uiEntityB );
    bool bEntityTagMatches( unsigned int uiEntityA, unsigned int uiEntityB );
    bool attributeVectTabTagCollision( const std::vector< bool > & vectBool, unsigned int uiLenght );
};

#endif // COLLISIONSYSTEM_H
