#ifndef SEGMENT_H
#define SEGMENT_H

#include "rectbox.hpp"
class Vector2D;

/**
 * @brief The Segment class Classe représentative d'un segment dans un espace 2 dimentions.
 */
class Segment
{
private:
    Vector2D mVectPtA, mVectPtB;
    RectBox mRectBox;
public:
	Segment() = default;
    Segment( const Vector2D &vectA, const Vector2D &vectB );
    void miseAJourRectBox();
    const Vector2D &mVectGetPtA()const;
    const Vector2D &mVectGetPtB()const;
    const RectBox &mRectGetBox()const;
    void setPtsSegment( const Vector2D &vectA, const Vector2D &vectB );
    void moveSegment( const Vector2D& vect );
};

#endif // SEGMENT_H
