#include "vector2D.hpp"

void Vector2D::displayVector()const
{
    std::cout << "mfX :: " << mfX << "\nmfY" << mfY << "\n";
}

Vector2D & Vector2D::operator =( const Vector2D & vect )
{
    mfX = vect.mfX;
    mfY = vect.mfY;
    return this;
}

Vector2D & Vector2D::operator +( const Vector2D & vect )
{
    return Vector2D( mfX + vect.mfX, mfY + vect.mfY );
}

Vector2D & Vector2D::operator -( const Vector2D & vect )
{
    return Vector2D( mfX - vect.mfX, mfY - vect.mfY );
}

Vector2D & Vector2D::operator -=( const Vector2D & vect )
{
    mfX -= vect.mfX;
    mfY -= vect.mfY;
    return this;
}

Vector2D & Vector2D::operator +=( const Vector2D & vect )
{
    mfX += vect.mfX;
    mfY += vect.mfY;
    return this;
}
