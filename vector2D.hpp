#ifndef VECTOR_H
#define VECTOR_H

/**
 * @brief La classe Vector2D représente un vecteur mathématiques à 2 dimentions.
 * Elle permet la manipulation des vecteurs 2 dimentions et différents calculs entre plusieurs vecteurs.
 */
class Vector2D{
public:
    float mfX, mfY;
    Vector2D();
    Vector2D( float fX, float fY );
    void displayVector()const;
    float fMagnitude()const;
    float fSqrMagnitude()const;

    void rotate( float fAngle, const Vector2D & vect2dCenter );
    Vector2D & operator -= ( const Vector2D & vect2dA );
    Vector2D & operator += ( const Vector2D & vect2dA );
    Vector2D & operator *= ( const Vector2D & vect2dA );
    Vector2D & operator /= ( const Vector2D & vect2dA );
    ~Vector2D();
};

Vector2D operator - ( Vector2D vect2dA, const Vector2D & vect2dB );
Vector2D operator + ( Vector2D vect2dA, const Vector2D & vect2dB );
Vector2D operator * ( Vector2D vect2dA, const Vector2D & vect2dB );
Vector2D operator / ( Vector2D vect2dA, const Vector2D & vect2dB );
bool operator == ( const Vector2D & vect2dA, const Vector2D & vect2dB );
bool operator != ( const Vector2D & vect2dA, const Vector2D & vect2dB );

float distance( const Vector2D & vect2dA, const Vector2D & vect2dB );
float radian( float fDegreeAngle );
float addToAngle(float fCurrentAngle , float fDegree);

#endif // VECTOR_H
