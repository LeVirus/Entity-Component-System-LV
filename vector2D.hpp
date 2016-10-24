#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

/**
 * @brief The Vector2D struct Structure représentant un point dans un espace 2 dimentions.
 */
struct Vector2D
{    

    float mfX = 0, mfY = 0;
    Vector2D();
    Vector2D(float x, float y): nombre1_(nombre1), nombre2_(nombre2);
    void displayVector()const;
    bool operator =( const Vector2D & vect );
};

#endif // VECTOR2D_H
