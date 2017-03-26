#include "vector2D.hpp"
#include <memory>

namespace ecs
{

void Vector2D::displayVector()const
{
    std::cout << "mfX :: " << mfX << "\nmfY" << mfY << "\n";
}

Vector2D & Vector2D::operator =( const Vector2D & vect )
{
    mfX = vect.mfX;
	mfY = vect.mfY;
	return *this;
}

Vector2D Vector2D::operator +( const Vector2D & vect )const
{
	return {mfX + vect.mfX, mfY + vect.mfY};
}

Vector2D Vector2D::operator -( const Vector2D & vect )const
{
	return {mfX - vect.mfX, mfY - vect.mfY};
}

Vector2D & Vector2D::operator -=( const Vector2D & vect )
{
    mfX -= vect.mfX;
    mfY -= vect.mfY;
    return *this;
}

Vector2D & Vector2D::operator +=( const Vector2D & vect )
{
    mfX += vect.mfX;
    mfY += vect.mfY;
    return *this;
}

bool Vector2D::operator ==( const Vector2D & vect )const
{
    return ( mfX == vect.mfX && mfY == vect.mfY );

}

}//fin namespace
