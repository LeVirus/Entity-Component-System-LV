#ifndef COLLRECTBOXCOMPONENT_HPP
#define COLLRECTBOXCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "rectbox.hpp"

/**
 * @brief La structure CollRectBoxComponent stocke un masque de collision de type Boite englobante.
 */
struct CollRectBoxComponent : public Component{
    RectBox mRectBox;
    Vector2D mVect2dVectOrigins;
    /**
     * @brief CollRectBoxComponent Constructeur de la structure CollRectBoxComponent.
     * Initialisation des variables muiTypeComponent( présente dans la classe mère Component ).
     */
    CollRectBoxComponent(){
        muiTypeComponent = COLL_RECTBOX_COMPONENT;
    }

    /**
     * @brief displayComponent Fonction dérivée d'affichage des variables de la structure CollRectBoxComponent.
     * La fonction de base d'affichage de la classe mère est appelée en premier lieu.
     */
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "RectBox Component\n";
        std::cout << "Position et caracteristique BoxRect\n";
        mRectBox . mGetOriginsRectBox() . displayVector();
        std::cout << "\n" << mRectBox . mfGetLenghtRectBox() <<
                     "\n" << mRectBox . mfGetHeightRectBox() << "\n";
        std::cout << "Origine\n";
        mVect2dVectOrigins . displayVector();
        std::cout << "Fin RectBox Component\n";

    }
};

#endif // COLLRECTBOXCOMPONENT_HPP

