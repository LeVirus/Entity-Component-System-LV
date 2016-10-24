#ifndef SEGMENT_H
#define SEGMENT_H

#include "rectbox.hpp"
#include "vector2D.hpp"

/**
 * @brief The Segment class Classe représentative d'un segment dans un espace 2 dimentions.
 */
class Segment
{
private:
    Vector2D mVectPtA, mVectPtB;
    RectBox mRectBox;
public:
    Segment();
    Segment( const Vector2D &vectA, const Vector2D &vectB ):
        mVectPtA( vectA ), mVectPtB( vectB ) {};
    void miseAJourRectBox();
    const Vector2D &mVectGetPtA()const;
    const Vector2D &mVectGetPtB()const;
    const RectBox &mRectGetBox()const;
    bool setPtsSegment( const Vector2D &vectA, const Vector2D &vectB );
    bool moveSegment( const Vector2D &vect );
};

#endif // SEGMENT_H
