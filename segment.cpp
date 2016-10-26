#include "vector2D.hpp"
#include "segment.hpp"
#include <cmath>


/**
 * @brief Segment Constructeur avec 2 arguments représentant les 2 points du segment.
 * Quand les 2 point sont modifiés le RectBox(boite englobante) s'adapte aux 2 points.
 * @param vectA Le point A.
 * @param vectB Le point B.
 */
Segment::Segment( const Vector2D &vectA, const Vector2D &vectB )
{
    mVectPtA = vectA;
    mVectPtB = vectB;
    miseAJourRectBox();
}

/**
 * @brief Segment::miseAJourRectBox Adaptation de la boite englobante aux 2 points.
 * La fonction détermine quel point se trouve le plus au dessus et/ou à gauche de l'autre.
 * La largeur et la longueur de la boite sont calculées en fonction de la distance entre les points A et B.
 */
void Segment::miseAJourRectBox()
{
    float memX, memY;
    if( mVectPtA.mfX <= mVectPtB.mfX )
    {
        memX = mVectPtA.mfX;
    }
    else
    {
        memX = mVectPtB.mfX;
    }

    if( mVectPtA.mfY <= mVectPtB.mfY )
    {
        memY = mVectPtA.mfY;
    }
    else
    {
        memY = mVectPtB.mfY;
    }
	mRectBox.mSetOriginsRectBox( Vector2D( memX, memY ) );
	mRectBox.mSetLenghtRectBox( std::abs( mVectPtA.mfX - mVectPtB.mfX ) );
	mRectBox.mSetHeightRectBox( std::abs( mVectPtA.mfY - mVectPtB.mfY ) );
}

/**
 * @brief Segment::mVectGetPtA Renvoi le point A du segment.
 * @return une référence constante du point A.
 */
const Vector2D &Segment::mVectGetPtA()const
{
    return mVectPtA;
}

/**
 * @brief Segment::mVectGetPtB Renvoi le point B du segment.
 * @return une référence constante du point B.
 */
const Vector2D &Segment::mVectGetPtB()const
{
    return mVectPtB;
}

/**
 * @brief Segment::mRectGetBox Renvoi la boite englobante du segment.
 * @return une référence constante de la boite englobante.
 */
const RectBox &Segment::mRectGetBox()const
{
    return mRectBox;
}

/**
 * @brief Segment::setPtsSegment Modifie les ppoints A et B du segment, avant de mettre à jour la nouvelle boite englobante.
 * @param vectA Le nouveau point A.
 * @param vectB Le nouveau point B.
 * @return false si au moins un des 2 Vector2D est à null, true sinon.
 */
void Segment::setPtsSegment( const Vector2D &vectA, const Vector2D &vectB )
{
    mVectPtA = vectA;
    mVectPtB = vectB;
    miseAJourRectBox();
}

/**
 * @brief moveSegment Positionne le segment au point envoyé en paramètre(angle haut gauche).
 * Les 2 points sont déplacés en fonction d'un vecteur
 * @param vect Le point où positionner le segment.
 * @return false si le paramètre est à null, true sinon.
 */
void Segment::moveSegment( const Vector2D &vect )
{
	Vector2D vectMove = mRectBox.mGetOriginsRectBox() - vect;
	mRectBox.mSetOriginsRectBox( vect );
	mVectPtA += vectMove;
	mVectPtB += vectMove;
}

