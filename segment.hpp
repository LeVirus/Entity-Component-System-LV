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
    RectBox RectBox;
public:
    Segment();
    Segment( const Vector2D &vectA, const Vector2D &vectB );
    void miseAJourSegment();
};

#endif // SEGMENT_H
