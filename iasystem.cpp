#include "iasystem.hpp"
#include "entity.hpp"
#include "engine.hpp"
#include "moveablecomponent.hpp"
#include "behaviorcomponent.hpp"
#include "physicscomponent.hpp"
#include "positioncomponent.hpp"
#include <cmath>
//#include <limits>

/**
 * @brief IASystem::IASystem Constructeur de la classe IASystem.
 */
IASystem::IASystem(){
    if( ! bAddComponentToSystem( PHYSIC_COMPONENT ) ){
        std::cout << "Erreur displaySystem ajout PHYSIC_COMPONENT." << "\n";
    }
    if( ! bAddComponentToSystem( BEHAVIOR_COMPONENT ) ){
        std::cout << "Erreur displaySystem ajout BEHAVIOR_COMPONENT." << "\n";
    }
    if( ! bAddComponentToSystem( POSITION_COMPONENT ) ){
        std::cout << "Erreur displaySystem ajout POSITION_COMPONENT." << "\n";
    }
}

/**
 * @brief IASystem::initMoveable Initialisation des variables présentes dans le composant MoveableComponent.
 * La fonction va appliquer un traitement sur chaque entité possèdant les composants MoveableComponent, PositionComponent,
 * PhysicComponent et BehaviorComponent.
 * En fonction de BehaviorComponent et PositionComponent les variables présentes dans MoveableComponent vont être initialisées
 * La fonction va appeler la fonctions spécialisée en fonction de uiNumBehavior.
 * !!!Le composant PositionComponent est supposé initialisé!!!
 * @param uiNumBehavior le numéro définissant le comportement de l'entité.
 * @param posComp Le composant position .
 * @param moveComp Le composant mouvement.
 */
void IASystem::initMoveable( unsigned int uiNumBehavior, PositionComponent *posComp, MoveableComponent *moveComp ){
    switch( uiNumBehavior ){
    case UNSPECIFIED:
        break;
    case SINUSOIDAL:
        initMoveableSinusoid( posComp, moveComp );
        break;
    case RING:
        initMoveableRing( posComp, moveComp );
        break;
    case ROUND_TRIP:
        break;
    case TOWARD_PLAYER:
        break;
    }
}

/**
 * @brief IASystem::initMoveableSinusoid La fonction calcule la nouvelle position de l'entité selon une sinusoide.
 *
 * @param posComp Le composant position.
 * @param moveComp Le composant mouvement.
 */
void IASystem::initMoveableSinusoid( PositionComponent * posComp, MoveableComponent * moveComp ){
    if( ! posComp || ! moveComp )return;

    moveComp -> mVectFCustumVar . resize( 4 );
    //fabs(a.x - x) < std::numeric_limits<float>::epsilon()
    if( moveComp -> mfVelocite == 0 || moveComp -> mfVelocite > 50 )
        moveComp -> mfVelocite = 10;//si velocité non initialisée::valeur par défault

    //initialisation de l'angle
    moveComp -> mVectFCustumVar[ 0 ] = 0;

    //vérification de la valeur de l'intensité de la sinusoide(possibilité de l'initialiser antérieurement).
    //si valeur hors limite valeur par défaut
    if( moveComp -> mVectFCustumVar[ 1 ] == 0 || moveComp -> mVectFCustumVar[ 1 ] > 500 )
        moveComp -> mVectFCustumVar[ 1 ] = 100;

    //définition de l'origine Y a partir de la position actuelle de l'entité
    moveComp -> mVectFCustumVar[ 2 ] = posComp -> mfPositionY;

    moveComp -> mVectFCustumVar[ 3 ] = moveComp -> mVectFCustumVar[ 1 ];
}

/**
 * @brief IASystem::initMoveableRing Calcul de la position de l'entité suivant un cercle
 * @param posComp Le composant position.
 * @param moveComp Le composant mouvement.
 */
void IASystem::initMoveableRing( PositionComponent * posComp, MoveableComponent * moveComp ){
    if( ! posComp || ! moveComp )return;

    //si vélocité non initialisée ou hors limite
    if( moveComp -> mfVelocite == 0 || moveComp -> mfVelocite > 100 )
        moveComp -> mfVelocite = 10;

    moveComp -> mVectFCustumVar . resize( 4 );
    //si valeur rayon cercle non initialisée
    if( moveComp -> mVectFCustumVar[ 0 ] == 0 )moveComp -> mVectFCustumVar[ 0 ] = 50;

    //initialisation du centre du cercle avec les valeurs contenues dans posComp
    moveComp -> mVectFCustumVar[ 2 ] = posComp -> mfPositionX;
    moveComp -> mVectFCustumVar[ 3 ] = posComp -> mfPositionY;
}

/**
 * @brief IASystem::execSystem Fonction(surchargée) d'exécution du système sur les entités concernées
 * par le système.
 * La fonction va modifier les données contenus dans les composants(associés aux entités).
 * La fonction de la classe mère System::execSystem est appelé en début de fonction.
 * La fonction va analyser les caractéristiques physiques et comportementales de l'entité,
 * pour ensuite définir quels va(vont) être la(les) prochaine(s) action(s).
 * Ces actions vont être déterminé par le composant MoveableComponent(si non NULL) et/ou (un autre à définir).
 */
void IASystem::execSystem(){
    //récupération du vector d'entités
    //const std::vector< Entity > & vectEntity = mptrSystemManager -> getptrEngine() -> getVectEntity();

    System::execSystem();
    //parcours des entités à traiter
    for( unsigned int i = 0 ; i < mVectNumEntity.size() ; ++i ){
        std::cout << mVectNumEntity[ i ] << "\n";

        PhysicComponent * physicComp = stairwayToComponentManager() .
                searchComponentByType < PhysicComponent > ( mVectNumEntity[ i ], PHYSIC_COMPONENT );
        if( ! physicComp ){
            std::cout << " Erreur IASystem pointeur NULL physicComp " << "\n";
            continue;
        }

        PositionComponent * positionComp = stairwayToComponentManager() .
                searchComponentByType < PositionComponent > ( mVectNumEntity[ i ], POSITION_COMPONENT );
        if( ! positionComp ){
            std::cout << " Erreur IASystem pointeur NULL positionComp " << "\n";
            continue;
        }

        BehaviorComponent * behaviorComponent = stairwayToComponentManager() .
                searchComponentByType < BehaviorComponent > ( mVectNumEntity[ i ], BEHAVIOR_COMPONENT );
        if( ! behaviorComponent ){
            std::cout << " Erreur IASystem pointeur NULL behaviorComponent " << "\n";
            continue;
        }
        MoveableComponent * moveableComponent = stairwayToComponentManager() .
                searchComponentByType < MoveableComponent > ( mVectNumEntity[ i ], MOVEABLE_COMPONENT );
        if( ! moveableComponent ){
            std::cout << " IASystem pointeur NULL moveableComponent " << "\n";
        }

        //vérifier si moveableComponent est instancié
        if( ! moveableComponent )continue;
        //si l'entité "moveable" n'est pas initialisé(le composant MoveableComponent n'est pas initialisé)
        if( ! moveableComponent -> mbMoveUpToDate ){
            //appel de la fonction adéquate
            initMoveable( behaviorComponent -> muiTypeBehavior, positionComp, moveableComponent );
        }

        switch( behaviorComponent -> muiTypeBehavior ){
        case UNSPECIFIED:
            break;
        case SINUSOIDAL:
            actionSinusoid( positionComp, moveableComponent );
            break;
        case RING:
            actionRing( positionComp, moveableComponent );
            break;
        case ROUND_TRIP:
            break;
        case TOWARD_PLAYER:
            break;
        }

    }
}

/**
 * @brief IASystem::actionSinusoid Fonction définissant le parcour d'une entité dont le comportement est sinusoidal.
 * Dans un premier temps une vérification de l'appartenance des 2 composants à la même entité est effectuée.
 * //un calcul a partir de la fonction sinus sera fait.
 * Le déplacement horizontal et vertical sera effectué selon la sinusoide, son sens sera définis par mbCustomVarD.
 * @param posComp Le composant position de l'entité en cour de traitement
 * @param moveComp Le composant mouvement de l'entité en cour de traitement
 * //SEULEMENT HORIZONTAL
 */
void IASystem::actionSinusoid( PositionComponent * posComp, MoveableComponent * moveComp ){

    float fMemAbscisseSinus, fMemResult;

    /*vérification de l'instanciation des 2 composants et si l'entité(par le numéro d'identifiant) associée aux 2
    composants est bien la même*/
    if( ! posComp || ! moveComp || posComp -> muiGetIdEntityAssociated() != moveComp -> muiGetIdEntityAssociated() )return;

    //récupération abscisse sinusoide position précédente
    fMemAbscisseSinus = cos( moveComp ->mVectFCustumVar[ 0 ] ) * moveComp -> mVectFCustumVar[ 1 ];

    //modification valeur angle en fonction de vélocité
    moveComp -> mVectFCustumVar[ 0 ] += moveComp -> mfVelocite;
    if( moveComp -> mVectFCustumVar[ 0 ] >= 360 )
        moveComp -> mVectFCustumVar[ 0 ] = 0 + fabs( static_cast< int >( moveComp -> mVectFCustumVar[ 0 ] ) % 360 );

    /*traitement mouvement vertical en fonction du sens
      Calcul du déplacement a effectuée sur les abscisses*/

    //cas du passage d'un angle supérieur à 180°
    if( ( moveComp -> mVectFCustumVar[ 0 ] - moveComp -> mfVelocite ) < 180 && moveComp -> mVectFCustumVar[ 0 ] > 180 ){
        fMemResult = fabs( fMemAbscisseSinus - cos( moveComp ->mVectFCustumVar[ 0 ] ) * moveComp -> mVectFCustumVar[ 1 ] );
    }
    //cas du passage d'un angle 360 >> 0
    else if( ( moveComp -> mVectFCustumVar[ 0 ] - moveComp -> mfVelocite ) > 180 && moveComp -> mVectFCustumVar[ 0 ] < 180  ){

    }
    else {
        fMemAbscisseSinus = fabs( fMemAbscisseSinus - cos( moveComp ->mVectFCustumVar[ 0 ] ) * moveComp -> mVectFCustumVar[ 1 ] );
    }

    if( moveComp -> mbCustomVarA )
        posComp -> mfPositionX -= fMemAbscisseSinus;
    else posComp -> mfPositionX += fMemAbscisseSinus;

    //traitement mouvement horizontal coordonnée Y = Ordonnée origine + sin( angle actuel ) * amplitude
    posComp -> mfPositionY = moveComp -> mVectFCustumVar[ 2 ] +
            sin( moveComp ->mVectFCustumVar[ 0 ] ) * moveComp -> mVectFCustumVar[ 1 ];
}

/**
 * @brief IASystem::actionRing Fonction de calcul de la rotation d'une entité autour d'un point.
 * @param posComp Le composant position de l'entité en cour de traitement.
 * @param moveComp Le composant mouvement de l'entité en cour de traitement.
 */
void IASystem::actionRing( PositionComponent * posComp, MoveableComponent * moveComp ){

    /*vérification de l'instanciation des 2 composants et si l'entité(par le numéro d'identifiant) associée aux 2
    composants est bien la même*/
    if( ! posComp || ! moveComp || posComp -> muiGetIdEntityAssociated() != moveComp -> muiGetIdEntityAssociated() )return;

    //modification de la valeur de l'angle en fonction de la vélocité
    moveComp -> mVectFCustumVar[ 1 ] += moveComp -> mfVelocite;
    if( moveComp -> mVectFCustumVar[ 1 ] >= 360 )moveComp -> mVectFCustumVar[ 1 ] = 0;

    //calcul de la nouvelle position en fonction de l'angle du cercle
    posComp -> mfPositionX = posComp -> mfPositionX + ( cos( moveComp -> mVectFCustumVar[ 1 ] ) * moveComp -> mVectFCustumVar[ 0 ] );
    posComp -> mfPositionY = posComp -> mfPositionY + ( sin( moveComp -> mVectFCustumVar[ 1 ] ) * moveComp -> mVectFCustumVar[ 0 ] );
}

/**
 * @brief IASystem::moveEntityAngle Fonction de déplacement d'une entité à partir d'une longueur et d'un angle.
 * Application des formules (cosinus sinus).
 * @param posComp le composant position à modifier.
 * @param fNbrPixels Le nombre de pixels.
 * @param fAngle l'angle dans lequel se fait le déplacement.
 */
void IASystem::moveEntityAngle( PositionComponent * posComp, float fNbrPixels, float fAngle ){
    float fMultipleX, fMultipleY, fMoveX, fMoveY, fAngleRadian;

    if( ! posComp )return;

    fAngleRadian = fAngle * PI / 180.0;
    fMultipleX = cos( fAngleRadian );
    fMultipleY = sin( fAngleRadian ) ;

    fMoveX = fNbrPixels * fMultipleX;
    fMoveY = fNbrPixels * fMultipleY;

    posComp -> mfPositionX += fMoveX;
    posComp -> mfPositionY += fMoveY;
}

/**
 * @brief moveEntity Fonction de déplacement d'une entité à partir du nombre de pixels abscisses et ordonnés.
 * @param posComp le composant position à modifier.
 * @param fNbrPixelsX le nombre de pixels abscisses.
 * @param fNbrPixelsY le nombre de pixels ordonnés.
 */
void moveEntity( PositionComponent * posComp, float fNbrPixelsX, float fNbrPixelsY ){
    if( ! posComp )return;
    posComp -> mfPositionX += fNbrPixelsX;
    posComp -> mfPositionY += fNbrPixelsY;
}


/**
 * @brief IASystem::~IASystem Destructeur de la classe IASystem.
 */
IASystem::~IASystem(){

}

