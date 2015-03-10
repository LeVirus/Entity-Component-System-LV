#ifndef MOVEABLECOMPONENT_HPP
#define MOVEABLECOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include <vector>

/**
 * @brief La structure MoveableComponent possède les caractéristiques liées aux déplacements d'une entité.
 * muiCustumVar est un tableau servant à stocker des valeurs qui seront utilisées ou non en fonction du besoin.
 *
 * Si BehaviorComponent -> muiTypeBehavior = SINUSOIDAL
 * mVectFCustumVar[ 0 ] :: Mémorisation de l'angle(en degré) en fonction duquel la position ordonnée sera déterminée(fonction sinusoidale)
 * mVectFCustumVar[ 1 ] :: Représente l'amplitude de la sinusoide.
 * mVectFCustumVar[ 2 ] :: L'ordonnée d'origine de l'entité(valeur de l'ordonnée de la sinusoide pour sin(0)).
 * mbCustomVarA Direction true == GAUCHE, false == DROITE
 * //A MODIFIER POUR POUVOIR DIRIGER LA SINUSOIDE DANS TOUTES LES DIRECTIONS
 * ===============================================================
 *
 * Si BehaviorComponent -> muiTypeBehavior = RING
 * mVectFCustumVar[ 0 ] :: Valeur du rayon du cercle.
 * mVectFCustumVar[ 1 ] :: Valeur de l'angle actuel(la valeur de la vélocité y est ajoutée a chaque itération).
 * mVectFCustumVar[ 2 ] :: Abscisse du centre de rotation.
 * mVectFCustumVar[ 3 ] :: Ordonnée du centre de rotation.
 * mbCustomVarA true = sens trigonométrique, false = sens antitrigonométrique.
 * Le centre de rotation sera définis par les valeurs présentes dans le composant position(supposé initialisé).
 * ===============================================================
 *
 * Si BehaviorComponent -> muiTypeBehavior == ROUND_TRIP
 * mVectFCustumVar[ 0 ] :: Angle sur lequel le composant va effectuer ses aller-retours (origine --> destination).
 * mVectFCustumVar[ 1 ] :: Longueur sur laquelle le composant va se déplacer.
 * mVectFCustumVar[ 2 ] :: Abscisse de l'origine du parcour.
 * mVectFCustumVar[ 3 ] :: Ordonnée de l'origine du parcour.
 * mVectFCustumVar[ 4 ] :: Abscisse de la destination du parcour.
 * mVectFCustumVar[ 5 ] :: Ordonnée de la destination du parcour.
 * mbCustomVarA true = sens point origine ==> point destination, false = sens point destination ==> point origine.
 * L'origine du parcour sera définis par les valeurs présentes dans le composant position(supposé initialisé).
 * La destination sera calculé dans initMoveableRoundTrip de la classe IASystem.
 * ===============================================================
 */
struct MoveableComponent : public Component{
    bool mbMoveUpToDate;
    std::vector< float > mVectFCustumVar;
    float mfVelocite;
    bool mbCustomVarA;

    /**
     * @brief DisplayComponent Constructeur de MoveableComponent.
     * Initialisation des variables à des valeurs par défaut.
     */
    MoveableComponent(){
        muiTypeComponent = MOVEABLE_COMPONENT;
        mbMoveUpToDate = false;
        mfVelocite = 0;
        mVectFCustumVar . resize( 2 );
        mVectFCustumVar[ 0 ] = 0;
        mVectFCustumVar[ 1 ] = 0;
        mbCustomVarA = true;
    }

    /**
     * @brief displayComponent Affichage des valeurs des variables contenues dans MoveableComponent.
     */
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "\n mfVelocite" << mfVelocite << "\n";
    }
};

#endif // MOVEABLECOMPONENT_HPP

