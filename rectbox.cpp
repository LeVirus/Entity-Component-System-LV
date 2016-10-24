#include "rectbox.hpp"

/**
 * @brief RectBox::mGetOriginsRectBox Fonction retournant l'origine du rectangle.
 * @return Une référence condtante du vector2d de l'origine du rectangle(coin haut gauche).
 */
const Vector2D & RectBox::mGetOriginsRectBox()const
{
    return mVect2dOrigins;
}

/**
 * @brief RectBox::mfGetLenghtRectBox Retourne la longueur du rectangle.
 * @return Longueur du rectangle.
 */
float RectBox::mfGetLenghtRectBox()const
{
    return mfLenght;
}

/**
 * @brief RectBox::mfGetHeightRectBox Retourne la largeur du rectangle.
 * @return Largeur du rectangle.
 */
float RectBox::mfGetHeightRectBox()const
{
    return mfHeight;
}

/**
 * @brief RectBox::mSetOriginsRectBox Modification de l'origine du rectangle
 * @param vect La référence contenant les données de l'origine à entrer dans le rectangle.
 * @return false si la référence est à nullptr, true sinon.
 */
bool RectBox::mSetOriginsRectBox( const Vector2D & vect )
{
    if( vect == nullptr )return false;
    mVect2dOrigins = vect;
    return true;
}

/**
 * @brief RectBox::mSetLenghtRectBox Modifie la longueur du rectangle.
 * @param lenght la nouvelle longueur du rectangle.
 */
void RectBox::mSetLenghtRectBox( float lenght )
{
    mfLenght = lenght;
}

/**
 * @brief RectBox::mSetHeightRectBox Modifie la largeur du rectangle.
 * @param height la nouvelle largeur du rectangle.
 */
void RectBox::mSetHeightRectBox( float height )
{
    mfHeight = height;
}
