#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

/**
 * @brief The Vector2D struct Structure représentant un point dans un espace 2 dimentions.
 */
struct Vector2D
{    

    float mfX = 0, mfY = 0;
	Vector2D() = default;
    Vector2D( float x, float y ):
        mfX( x ), mfY( y ){};
    void displayVector()const;
    Vector2D & operator =( const Vector2D & vect );
	Vector2D & operator +( const Vector2D & vect )const;
	Vector2D & operator -( const Vector2D &vect ) const;
    Vector2D & operator +=( const Vector2D & vect );
    Vector2D & operator -=( const Vector2D & vect );
    bool operator ==( const Vector2D & vect )const;

};

#endif // VECTOR2D_H
