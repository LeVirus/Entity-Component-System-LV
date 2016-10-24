#ifndef GEOMETRIEFREEFUNCTIONS_HPP
#define GEOMETRIEFREEFUNCTIONS_HPP

//#include "vector2D.hpp"
//#include "segment.hpp"
//#include "rectbox.hpp"
class Vector2D;
class RectBox;
class Segment;

float distance( const Vector2D & vectA, const Vector2D & vectB );
float addToAngle( float fCurrentAngle, float fValAjout );
const Vector2D & applyAngle( float fAngle, float fRadiusCircle, const Vector2D & mvect2DRotationCenter );
const Vector2D & moveVectorAngle( const Vector2D & mvect2DCurrentPositionSinusoidAxis,
                float fMemAbscisseSinus, float mfDirectionAxisSinusoid );
float radian( float mfCurrentAngleSinusoid );

bool bIsInCollision( const Segment &collSegmCompA, const Segment &collSegmCompB );
bool bIsInCollision( const RectBox &collRectBoxCompA, const Segment &collSegmCompB );
bool bIsInCollision( const Segment &collSegmCompA, const RectBox &collRectBoxCompB );
bool bIsInCollision( const RectBox &collRectBoxCompA, const RectBox &collRectBoxCompB );
bool bIsInCollision( const Vector2D &collVectA, const RectBox &collRectBoxCompB );

#endif // GEOMETRIEFREEFUNCTIONS_HPP
