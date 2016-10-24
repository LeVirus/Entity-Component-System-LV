#ifndef COLLSEGMENTCOMPONENT_HPP
#define COLLSEGMENTCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "segment.hpp"
#include "vector2D.hpp"

/**
 * @brief La structure CollSegmentComponent stocke un masque de collision de type segment.
 */
struct CollSegmentComponent : public Component{
    Segment mCollSegment;
    //Le vecteur séparent la position de l'origine de la figure (ici le point A du segment)
    Vector2D mVect2dVectOrigins;
    /**
     * @brief CollSegmentComponent Constructeur de la structure CollSegmentComponent.
     * Initialisation des variables muiTypeComponent(présente dans la classe mère Component).
     */
    CollSegmentComponent(){
        muiTypeComponent = COLL_SEGMENT_COMPONENT;
    }

    /**
     * @brief displayComponent Fonction dérivée d'affichage des variables de la structure BehaviorComponent.
     * La fonction de base d'affichage de la classe mère est appelée en premier lieu.
     */
    void displayComponent()const override{
        std::cout << "Segment Component\n";
        Component::displayComponent();
        std::cout << "Point A\n";
        mCollSegment . getVect2dPointA() . displayVector();
        std::cout << "Point B\n";
        mCollSegment . getVect2dPointB() . displayVector();
        std::cout << "Fin Segment Component\n";
    }
};

#endif // COLLSEGMENTCOMPONENT_HPP

