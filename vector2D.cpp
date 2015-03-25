#include "vector2D.hpp"
#include <iostream>
#include <cmath>

/**
 * @brief Vector2D::Vector2D Constructeur de Vector2D avec 2 arguments.
 * @param fX Valeur à attribuer a mfX.
 * @param fY Valeur à attribuer a mfY.
 */
Vector2D::Vector2D( float fX, float fY ){
    mfX = fX;
    mfY = fY;
}

/**
 * @brief Vector2D::displayVector Fonction d'affichage des variables contenues dans la classe Vector2D.
 */
void Vector2D::displayVector()const{
    std::cout << "mfX::" << mfX << "\nmfY::" << mfY << "\n";
}

/**
 * @brief Vector2D::magnitude Calcul de la longueur du vecteur.
 * @return La valeur de la longueur du vecteur.
 */
float Vector2D::fMagnitude()const{
    return sqrt( fSqrMagnitude() );
}

/**
 * @brief Vector2D::fSqrMagnitude Calcul de la longueur du vecteur au carré.
 * @return La valeur de la longueur du vecteur au carré.
 */
float Vector2D::fSqrMagnitude()const{
    return mfX * mfX + mfY * mfY;
}


Vector2D & Vector2D::operator -= ( const Vector2D & vect2dA ){
    mfX -= vect2dA . mfX;
    mfY -= vect2dA . mfY;
    return *this;
}

Vector2D & Vector2D::operator += ( const Vector2D & vect2dA ){
    mfX += vect2dA . mfX;
    mfY += vect2dA . mfY;
    return *this;
}

Vector2D & Vector2D::operator *= ( const Vector2D & vect2dA ){
    mfX *= vect2dA . mfX;
    mfY *= vect2dA . mfY;
    return *this;
}

Vector2D & Vector2D::operator /= ( const Vector2D & vect2dA ){
    mfX /= vect2dA . mfX;
    mfY /= vect2dA . mfY;
    return *this;
}


Vector2D operator - ( Vector2D vect2dA, const Vector2D &vect2dB ){
    return vect2dA -= vect2dB;
}

Vector2D operator + ( Vector2D vect2dA, const Vector2D &vect2dB ){
    return vect2dA += vect2dB;
}

Vector2D operator * ( Vector2D vect2dA, const Vector2D &vect2dB ){
    return vect2dA *= vect2dB;
}

Vector2D operator / ( Vector2D vect2dA, const Vector2D &vect2dB ){
    return vect2dA /= vect2dB;
}

bool operator == ( const Vector2D & vect2dA, const Vector2D &vect2dB ){
    return vect2dA . mfX == vect2dB . mfX && vect2dA . mfY == vect2dB . mfY;
}

bool operator != ( const Vector2D & vect2dA, const Vector2D &vect2dB ){
    return vect2dA . mfX != vect2dB . mfX || vect2dA . mfY != vect2dB . mfY;
}

/**
 * @brief distance Fonction de calcul de la distance qui sépare les 2 vecteurs.
 * @param vect2dA Le premier vecteur.
 * @param vect2dB Le deuxième vecteur.
 * @return La valeur de la distance entre les 2 vecteurs.
 */
float distance( const Vector2D & vect2dA, const Vector2D & vect2dB ){

    return ( vect2dA - vect2dB ) . fMagnitude() ;
}

/**
 * @brief Vector2D::~Vector2D Destructeur de Vector2D.
 */
Vector2D::~Vector2D(){

}

