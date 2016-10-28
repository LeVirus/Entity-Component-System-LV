#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "bitset2d.hpp"
#include "system.hpp"


namespace ecs
{

/**
 * @brief La classe CollisionSystem détermine les entités qui sont en collisions.
 * Un tableau détermine quelles type d'entité peut entrer en collision avec d'autres.
 */
class CollisionSystem : public System{
private:
    BitSet2d mBitSet2dTagCollision, mBitSet2dInCollision;
    unsigned int muiNumberTag;
    //ComponentManager * mCompManager;
public:
    CollisionSystem();
    void bModifyNumberTag( unsigned int uiNumTag );
    void execSystem() override;
    void updateCollPosition( unsigned int uiEntity );
    bool bEntityIsInCollision( unsigned int uiEntityA, unsigned int uiEntityB );
    bool bEntityTagMatches( unsigned int uiEntityA, unsigned int uiEntityB );
    bool attributeVectTabTagCollision( const std::vector< bool > & vectBool, unsigned int uiLenght );
    void displaySystem()const override;

};

}//fin namespace
#endif // COLLISIONSYSTEM_H
