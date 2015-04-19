#ifndef COLLSEGMENTCOMPONENT_HPP
#define COLLSEGMENTCOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include "segment.hpp"

/**
 * @brief La structure CollSegmentComponent stocke un masque de collision de type segment.
 */
struct CollSegmentComponent : public Component{
    Segment mCollSegment;

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
        Component::displayComponent();
    }
};

#endif // COLLSEGMENTCOMPONENT_HPP

