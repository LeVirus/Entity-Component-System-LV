#ifndef MOVEABLECOMPONENT_HPP
#define MOVEABLECOMPONENT_HPP

#include "component.hpp"
#include "ECSconstantes.hpp"
#include <vector>

/**
 * @brief La structure MoveableComponent possède les caractéristiques liées aux déplacements d'une entité.
 * muiCustumVar est un tableau servant à stocker des valeurs qui seront utilisées en fonction du besoin.
 *
 * Si BehaviorComponent -> muiTypeBehavior = SINUSOIDAL
 * mVectFCustumVar[ 0 ] :: Direction de la sinusoide(en degré).
 * mVectFCustumVar[ 1 ] :: Représente l'amplitude de la sinusoide.
 * mVectFCustumVar[ 2 ] :: L'abscisse de la droite d'origine de la sinusoide(valeur de l'abscisse de la sinusoide pour sin(0)).
 * mVectFCustumVar[ 3 ] :: L'ordonnée de la droite d'origine de la sinusoide(valeur de l'ordonnée de la sinusoide pour sin(0)).
 * mVectFCustumVar[ 4 ] :: Mémorisation de l'angle(en degré) en fonction duquel l'abscisse et l'ordonnée seront
 * déterminées(fonction sinusoidale).
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
    bool mbMoveUpToDate, mbTerrestrial, mbOnTheGround ,mbCustumVarA;
    std::vector< float > mVectFCustumVar;
    float mfVelocite;

    /**
     * @brief DisplayComponent Constructeur de MoveableComponent.
     * Initialisation de la variable muiTypeBehavior.
     * Les conteneurs de variables ;dont l'utilité sera déterminée en fonction du type des classes filles; sont initialisés
     * à des valeurs par défaut.
     */
    MoveableComponent(){
        muiTypeComponent = MOVEABLE_COMPONENT;
        mbTerrestrial = true;
        mbMoveUpToDate = false;
        mbOnTheGround = false;
        mfVelocite = 0;
        mVectFCustumVar . resize( 2 );
        mVectFCustumVar[ 0 ] = 0;
        mVectFCustumVar[ 1 ] = 0;
        mbCustumVarA = true;
    }

    /**
     * @brief displayComponent Fonction dérivée d'affichage des variables de la structure MoveableComponent.
     * La fonction de base d'affichage de la classe mère est appelée en premier lieu.
     */
    void displayComponent()const override{
        Component::displayComponent();
        std::cout << "\n mfVelocite" << mfVelocite << "\n";
    }
};

#endif // MOVEABLECOMPONENT_HPP

