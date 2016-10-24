#include "geometriefreefunctions.hpp"
#include "ECSconstantes.hpp"
#include "vector2D.hpp"
#include "segment.hpp"
#include "rectbox.hpp"
#include <cmath>

float distance( const Vector2D & vectA, const Vector2D & vectB )
{
    float memX = vectA.mfX - vectB.mfX;
    float memY = vectA.mfY - vectB.mfY;
    return std::sqrt( memX * memX + memY * memY );
}

void moveVectorAngle( const Vector2D & vectA, float mfVelocite, float fCurrentAngle )
{

}

float addToAngle( float fCurrentAngle, float fValAjout )
{

}

const Vector2D & applyAngle( float fAngle, float fRadiusCircle, const Vector2D & mvect2DRotationCenter )
{

}

const Vector2D & moveVectorAngle( const Vector2D & mvect2DCurrentPositionSinusoidAxis,
                float fMemAbscisseSinus, float mfDirectionAxisSinusoid )
{

}

float radian( float mfCurrentAngleSinusoid )
{
    return mfCurrentAngleSinusoid * PI / 180;
}

bool bIsInCollision( const RectBox &collRectBoxCompA, const RectBox &collRectBoxCompB )
{
    const Vector2D &vectHGA = collRectBoxCompA.mGetOriginsRectBox(),
            &vectBDA( collRectBoxCompA.mGetOriginsRectBox().mfX + collRectBoxCompA.mfGetLenghtRectBox(),
                     collRectBoxCompA.mGetOriginsRectBox().mfY + collRectBoxCompA.mfGetHeightRectBox() ),
            &vectHGB = collRectBoxCompB.mGetOriginsRectBox(),
            &vectBDB( collRectBoxCompB.mGetOriginsRectBox().mfX + collRectBoxCompB.mfGetLenghtRectBox(),
                     collRectBoxCompB.mGetOriginsRectBox().mfY + collRectBoxCompB.mfGetHeightRectBox() );

    if( vectBDA.mfX < vectHGB.mfX || vectBDB.mfX < vectHGA.mfX ||
            vectBDA.mfY < vectHGB.mfY || vectBDB.mfY < vectHGA.mfY )return false;
    return true;
}

bool bIsInCollision( const Segment &collSegmCompA, const Segment &collSegmCompB )
{
    if( ! bIsInCollision( collSegmCompA.mRectGetBox(), collSegmCompB.mRectGetBox() ) )return false;
    //A compléter
}

bool bIsInCollision( const RectBox &collRectBoxCompA, const Segment &collSegmCompB )
{
    return bIsInCollision( collSegmCompB.mRectGetBox(), collRectBoxCompA );
}

bool bIsInCollision( const Segment &collSegmCompA, const RectBox &collRectBoxCompB )
{
    if( ( bIsInCollision( collSegmCompA.mVectGetPtA(), collRectBoxCompB ) ) ||
            ( bIsInCollision( collSegmCompA.mVectGetPtB(), collRectBoxCompB ) ) )
        return true;
    //A compléter
}

bool bIsInCollision( const Vector2D &collVectA, const RectBox &collRectBoxCompB )
{
    const Vector2D &vectHGB = collRectBoxCompB.mGetOriginsRectBox(),
            &vectBDB( collRectBoxCompB.mGetOriginsRectBox().mfX + collRectBoxCompB.mfGetLenghtRectBox(),
                     collRectBoxCompB.mGetOriginsRectBox().mfY + collRectBoxCompB.mfGetHeightRectBox() );
    return ( collVectA.mfX <= vectBDB.mfX && collVectA.mfX >= vectHGB.mfX ) &&
          ( collVectA.mfY <= vectBDB.mfY && collVectA.mfY >= vectHGB.mfY );
}


