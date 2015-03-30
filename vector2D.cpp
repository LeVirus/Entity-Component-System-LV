#include "vector2D.hpp"
#include "ECSconstantes.hpp"
#include <iostream>
#include <cmath>

/**
 * @brief Vector2D::Vector2D Constructeur de Vector2D .
 */
Vector2D::Vector2D(){
    mfX = 0;
    mfY = 0;
}

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
 * @brief Vector2D::rotate Fonction de positionnement du vector par rapport a un centre et un angle.
 * @param fAngle L'angle où positionner le vector par rapport au centre.
 * @param vect2dCenter Les coordonnées du centre de rotation.
 */
void Vector2D::rotate( float fAngle, const Vector2D & vect2dCenter ){
    float fRadius = distance( *this, vect2dCenter );

    //calcul de la nouvelle position en fonction de l'angle du cercle
    mfX = vect2dCenter . mfX + ( cos( radian( fAngle ) ) * fRadius );
    mfY = vect2dCenter . mfY + ( sin( radian( fAngle ) ) * fRadius );
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
 * @brief radian Conversion d'un angle en radian.
 * @param fDegreeAngle La valeur de l'angle en degré.
 * @return La valeur de l'angle en degré.
 */
float radian( float fDegreeAngle ){
    return fDegreeAngle * PI / 180;
}

/**
 * @brief addToAngle Ajout D'une valeur à un angle.
 * Si la valeur dépasse 360 celle ci est corrigée.
 * @param fCurrentAngle L'angle courrant.
 * @param fDegree La valeur à ajouter à m'angle.
 * @return La nouvelle valeur de l'angle.
 */
float addToAngle( float fCurrentAngle, float fDegree ){
    fCurrentAngle += fDegree;
    if( fCurrentAngle >= 360 )fCurrentAngle = fmod( fCurrentAngle, 360 );
    return fCurrentAngle;
}

/**
 * @brief moveVectorAngle Fonction de déplacement d'une entité à partir d'une longueur et d'un angle.
 * Application des formules (cosinus sinus).
 * @param vect2dA le vector à modifier.
 * @param fNbrPixels Le nombre de pixels.
 * @param fAngle l'angle dans lequel se fait le déplacement.
 * @return La référence du vector à renvoyer en paramètre.
 */
Vector2D & moveVectorAngle( Vector2D & vect2dA, float fNbrPixels, float fAngle ){
    float fAngleRadian;

    fAngleRadian = radian( fAngle );
    vect2dA . mfX += cos( fAngleRadian ) * fNbrPixels;
    vect2dA . mfY += sin( fAngleRadian ) * fNbrPixels;
    return vect2dA;
}

/**
 * @brief moveTowardVector Fonction de déplacement d'un vector en direction d'un autre avec une distance donnée.
 * @param vect2dA Le vector à déplacer.
 * @param vect2dDestination Le vector vers lequel se diriger.
 * @param fNbrPixels La distance à parcourir.
 * @return La référence du vector modifié.
 */
Vector2D & moveTowardVector( Vector2D & vect2dA, const Vector2D & vect2dDestination, float fNbrPixels ){

}

/**
 * @brief Vector2D::~Vector2D Destructeur de Vector2D.
 */
Vector2D::~Vector2D(){

}

