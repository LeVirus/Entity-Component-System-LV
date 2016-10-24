#ifndef RECTBOX_H
#define RECTBOX_H

#include "vector2D.hpp"

/**
 * @brief The RectBox class Classe représentant un rectangle dont les cotés sont // aux au repères
 * de la référence orthonormée.
 */
class RectBox
{
private:
    Vector2D mVect2dOrigins;
    float mfLenght = 0, mfHeight = 0;
public:
    RectBox();
    RectBox( const Vector2D & vectOrigins, float lenght, float height )
        :mVect2dOrigins = vectOrigins, mfLenght = lenght, mfHeight = height;

    const Vector2D & mGetOriginsRectBox()const;
    float mfGetLenghtRectBox()const;
    float mfGetHeightRectBox()const;
    bool mSetOriginsRectBox( const Vector2D & vect );
    void mSetLenghtRectBox( float lenght );
    void mSetHeightRectBox( float height );
};

#endif // RECTBOX_H
