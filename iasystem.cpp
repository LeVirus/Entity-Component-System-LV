#include "iasystem.hpp"
#include "entity.hpp"
#include "engine.hpp"
#include "moveablecomponent.hpp"
#include "behaviorcomponent.hpp"
#include "physicscomponent.hpp"
#include "positioncomponent.hpp"
#include "ringbehaviorcomponent.hpp"
#include "roundtripbehaviorcomponent.hpp"
#include "sinusoidbehaviorcomponent.hpp"
#include "vector2D.hpp"
#include <cassert>
#include <cmath>
//#include <limits>

/**
 * @brief IASystem::IASystem Constructeur de la classe IASystem.
 */
IASystem::IASystem(){
    /*if( ! bAddComponentToSystem( PHYSIC_COMPONENT ) ){
        std::cout << "Erreur displaySystem ajout PHYSIC_COMPONENT.\n";
    }*/
    if( ! bAddComponentToSystem( BEHAVIOR_COMPONENT ) ){
        std::cout << "Erreur displaySystem ajout BEHAVIOR_COMPONENT.\n";
    }
    if( ! bAddComponentToSystem( POSITION_COMPONENT ) ){
        std::cout << "Erreur displaySystem ajout POSITION_COMPONENT.\n";
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
bool IASystem::initMoveable( unsigned int uiNumEntity ){

    BehaviorComponent * behavComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< BehaviorComponent >( uiNumEntity, BEHAVIOR_COMPONENT );
    assert( behavComp && "initMoveable behavComp non instancié.\n" );

    MoveableComponent * moveComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< MoveableComponent >( uiNumEntity, MOVEABLE_COMPONENT );
    assert( moveComp && "initMoveable moveComp non instancié.\n" );

    //si vélocité non initialisée ou hors limite
    assert( ! ( moveComp -> mfVelocite <= 0 || moveComp -> mfVelocite > 50 ) && "mfVelocite hors limite.\n" );

    switch( behavComp -> muiTypeBehavior ){
    case UNSPECIFIED:
        break;
    case SINUSOIDAL:
        initMoveableSinusoid( uiNumEntity );
        break;
    case RING:
        initMoveableRing( uiNumEntity );
        break;
    case ROUND_TRIP:
        initMoveableRoundTrip( uiNumEntity );
        break;
    case TOWARD_PLAYER:
        break;
    }
    moveComp -> mbMoveUpToDate = true;
    return true;
}

/**
 * @brief IASystem::initMoveableSinusoid La fonction initialise les variables contenues dans le composant selon les critères du
 * comportement sinusoide.
 * L'angle de départ est initialisé à 1, la valeur de l'amplitude de la sinusoide est vérifié, si cette dernière est hors limite elle
 * est mise à une valeur par défaut.
 * @param posComp Le composant position.
 * @param moveComp Le composant mouvement.
 */
void IASystem::initMoveableSinusoid( unsigned int uiNumEntity ){

    SinusoidBehaviorComponent * sinusBehaviorComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< SinusoidBehaviorComponent >( uiNumEntity, SINUSOID_BEHAVIOR_COMPONENT );
    assert( sinusBehaviorComp && "initMoveable sinusBehaviorComp non instancié.\n" );

    PositionComponent * posComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< PositionComponent >( uiNumEntity, POSITION_COMPONENT );
    assert( posComp && "initMoveable posComp non instancié.\n" );

    //si valeur de la direction de la sinusoide est hors limites
    assert( ! ( sinusBehaviorComp -> mfDirectionAxisSinusoid > 359 || sinusBehaviorComp -> mfDirectionAxisSinusoid < 0 ) &&
            "Direction Axe sinusoide hors limite.\n" );

    //vérification de la valeur de l'amplitude de la sinusoide(possibilité de l'initialiser antérieurement).
    //si valeur hors limite valeur par défaut
    assert( ! ( sinusBehaviorComp -> mfAmplitudeSinusoid <= 0 || sinusBehaviorComp -> mfAmplitudeSinusoid > 500 ) &&
            "Amplitude sinusoide hors limite.\n" );

    //définition de l'abscisse et de l'ordonnée de la droite d'origine de la fonction
    //sinusoide à partir de la position actuelle de l'entité
    sinusBehaviorComp -> mvect2DCurrentPositionSinusoidAxis = posComp -> vect2DPosComp;

    //initialisation de l'angle de la fonction sinusoide
    //sinusBehaviorComp -> mfCurrentAngleSinusoid;
}

/**
 * @brief IASystem::initMoveableRing La fonction initialise les variables contenues dans le composant RingBehaviorComponent
 * selon les critères du comportement ring.
 * La position de l'entité est prise pour le centre de rotation.
 */
void IASystem::initMoveableRing( unsigned int uiNumEntity ){
    RingBehaviorComponent * ringBehaviorComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< RingBehaviorComponent >( uiNumEntity, RING_BEHAVIOR_COMPONENT );
    assert( ringBehaviorComp && "initMoveable ringBehaviorComp non instancié.\n" );

    PositionComponent * posComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< PositionComponent >( uiNumEntity, POSITION_COMPONENT );
    assert( ringBehaviorComp && "initMoveable posComp non instancié.\n" );

    //initialisation du centre du cercle avec les valeurs contenues dans posComp
    ringBehaviorComp -> mvect2DRotationCenter = posComp -> vect2DPosComp;
    posComp -> vect2DPosComp . mfX += ringBehaviorComp -> mfRadiusCircle;
}

/**
 * @brief IASystem::initMoveableRoundTrip La fonction initialise les variables contenues dans le composant selon les critères du
 * comportement roundtrip.
 *
 * @param posComp Le composant position.
 * @param moveComp Le composant mouvement.
 */
void IASystem::initMoveableRoundTrip( unsigned int uiNumEntity ){
    std::cout << "INIT ROUND TRIP\n";
    PositionComponent * posComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< PositionComponent >( uiNumEntity, POSITION_COMPONENT );
    assert( posComp && "initMoveable posComp non instancié.\n" );

    RoundTripBehaviorComponent * roundTripBehavComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< RoundTripBehaviorComponent >( uiNumEntity, ROUND_TRIP_BEHAVIOR_COMPONENT );
    assert( roundTripBehavComp && "initMoveable roundTripBehavComp non instancié.\n" );

    //si valeur de l'angle est hors limite.
    assert( ! ( roundTripBehavComp -> mfDestinationDirection >= 360 || roundTripBehavComp -> mfDestinationDirection < 0 ) &&
            "valeur mfDestinationDirection hors limite.\n" );

    //si valeur de la longueur du parcour est hors limite
    assert( ! ( roundTripBehavComp -> mfTravelsLenght <= 0 || roundTripBehavComp -> mfTravelsLenght > 100 ) &&
            "valeur mfDestinationDirection hors limite.\n" );

    //initialisation de l'origine du parcour.
    roundTripBehavComp -> mvect2DPositionOriginTravels = posComp -> vect2DPosComp;

    //initialisation de la destination avec les valeurs de l'origine.
    roundTripBehavComp -> mvect2DPositionDestinationTravels = posComp -> vect2DPosComp;

    //déplacement du point de destination avec l'angle et la longueur du trajet.
    roundTripBehavComp -> mvect2DPositionDestinationTravels = moveVectorAngle(
                roundTripBehavComp -> mvect2DPositionDestinationTravels, roundTripBehavComp -> mfTravelsLenght,
                roundTripBehavComp -> mfDestinationDirection );

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
        //std::cout << mVectNumEntity[ i ] << "\n";

        /*PhysicComponent * physicComp = stairwayToComponentManager() .
                searchComponentByType < PhysicComponent > ( mVectNumEntity[ i ], PHYSIC_COMPONENT );
        if( ! physicComp ){
            std::cout << " Erreur IASystem pointeur NULL physicComp " << "\n";
            continue;
        }*/

        PositionComponent * positionComp = stairwayToComponentManager() .
                searchComponentByType < PositionComponent > ( mVectNumEntity[ i ], POSITION_COMPONENT );
        assert( positionComp && "Erreur IASystem pointeur NULL positionComp \n" );

        BehaviorComponent * behaviorComponent = stairwayToComponentManager() .
                searchComponentByType < BehaviorComponent > ( mVectNumEntity[ i ], BEHAVIOR_COMPONENT );
        assert( behaviorComponent && "Erreur IASystem pointeur NULL behaviorComponent \n" );

        MoveableComponent * moveableComponent = stairwayToComponentManager() .
                searchComponentByType < MoveableComponent > ( mVectNumEntity[ i ], MOVEABLE_COMPONENT );
        //assert( moveableComponent && "Erreur IASystem pointeur NULL moveableComponent \n" );


        //vérifier si moveableComponent est instancié
        if( ! moveableComponent )continue;
        //si l'entité "moveable" n'est pas initialisé(le composant MoveableComponent n'est pas initialisé)
        if( ! moveableComponent -> mbMoveUpToDate ){
            //appel de la fonction adéquate
            initMoveable( i );
        }

        switch( behaviorComponent -> muiTypeBehavior ){
        case UNSPECIFIED:
            break;
        case SINUSOIDAL:
            actionSinusoid( i );
            break;
        case RING:
            actionRing( i );
            break;
        case ROUND_TRIP:
            actionRoundTrip( i );
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
 *
 * mVectFCustumVar[ 0 ] :: Direction de la sinusoide(en degré).
 * mVectFCustumVar[ 1 ] :: Représente l'amplitude de la sinusoide.
 * mVectFCustumVar[ 2 ] :: L'abscisse de la droite d'origine de la sinusoide(valeur de l'abscisse de la sinusoide pour sin(0)).
 * mVectFCustumVar[ 3 ] :: L'ordonnée de la droite d'origine de la sinusoide(valeur de l'ordonnée de la sinusoide pour sin(0)).
 * mVectFCustumVar[ 4 ] :: Mémorisation de l'angle(en degré) en fonction duquel l'abscisse et l'ordonnée seront
 *
 */
void IASystem::actionSinusoid( unsigned int uiNumEntity ){
    std::cout << " SINUSOIDE \n";

    SinusoidBehaviorComponent * sinusBehaviorComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< SinusoidBehaviorComponent >( uiNumEntity, SINUSOID_BEHAVIOR_COMPONENT );
    assert( sinusBehaviorComp && "initMoveable sinusBehaviorComp non instancié.\n" );

    PositionComponent * posComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< PositionComponent >( uiNumEntity, POSITION_COMPONENT );
    assert( posComp && "initMoveable posComp non instancié.\n" );

    MoveableComponent * moveComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType< MoveableComponent >( uiNumEntity, MOVEABLE_COMPONENT );
    assert( moveComp && "initMoveable moveComp non instancié.\n" );

    float fMemAbscisseSinus, fMemOrdonneeSinus, fMemResult;

    /*vérification de l'instanciation des 2 composants et si l'entité(par le numéro d'identifiant) associée aux 2
    composants est bien la même*/

    //récupération abscisse sinusoide position précédente
    fMemAbscisseSinus = cos( radian( sinusBehaviorComp -> mfCurrentAngleSinusoid ) ) * sinusBehaviorComp -> mfAmplitudeSinusoid;

    //modification valeur angle en fonction de vélocité
    sinusBehaviorComp -> mfCurrentAngleSinusoid = addToAngle( sinusBehaviorComp -> mfCurrentAngleSinusoid,
                                                                  moveComp -> mfVelocite );

    /*traitement mouvement vertical en fonction du sens
      Calcul du déplacement a effectuée sur les abscisses*/

    //cas du passage d'un angle supérieur à 180°
    if( ( sinusBehaviorComp -> mfCurrentAngleSinusoid - moveComp -> mfVelocite ) < 180 &&
            sinusBehaviorComp -> mfCurrentAngleSinusoid > 180 ){
        //calcul du parcour sur l'abscisse dans la partie : 0 -> PI
        fMemResult = fabs( fMemAbscisseSinus - cos( radian( 180 ) ) * sinusBehaviorComp -> mfAmplitudeSinusoid );
        //calcul du parcour sur l'abscisse dans la partie : PI -> 2PI et addition des 2
        //cos( 180 )==-1    ==>     cos( 180 ) * amplitude = -amplitude
        fMemAbscisseSinus = fMemResult + fabs( ( -1 * sinusBehaviorComp -> mfAmplitudeSinusoid ) -
                ( cos( radian( sinusBehaviorComp -> mfCurrentAngleSinusoid ) ) * sinusBehaviorComp -> mfAmplitudeSinusoid ) );
    }
    //cas du passage d'un angle 360 >> 0
    else if( ( sinusBehaviorComp -> mfCurrentAngleSinusoid - moveComp -> mfVelocite ) > 180 &&
             sinusBehaviorComp -> mfCurrentAngleSinusoid < 180  ){
        //calcul du parcour sur l'abscisse dans la partie : PI -> 2PI
        fMemResult = fabs( fMemAbscisseSinus - cos( 4 ) * sinusBehaviorComp -> mfAmplitudeSinusoid );
        //calcul du parcour sur l'abscisse dans la partie : 0 -> PI et addition des 2
        //cos( 0 )==1    ==>     cos( 0 ) * amplitude = amplitude
        fMemAbscisseSinus = fMemResult + fabs( sinusBehaviorComp -> mfAmplitudeSinusoid -
                                               cos( radian( sinusBehaviorComp -> mfCurrentAngleSinusoid ) ) *
                                             sinusBehaviorComp -> mfAmplitudeSinusoid );
    }
    else {
        fMemAbscisseSinus = fabs( fMemAbscisseSinus - cos( radian( sinusBehaviorComp -> mfCurrentAngleSinusoid ) ) *
                sinusBehaviorComp -> mfAmplitudeSinusoid );
    }

    //positionnement de la sinusoide en fonction de l'avancée abscisse de la sinusoide suivant l'angle d'orientation de celle ci
    moveVectorAngle( sinusBehaviorComp -> mvect2DCurrentPositionSinusoidAxis,
                    fMemAbscisseSinus, sinusBehaviorComp -> mfDirectionAxisSinusoid );

    //modification de la position de l'entité à la ligne d'origine de la sinusoide
    posComp -> vect2DPosComp = sinusBehaviorComp -> mvect2DCurrentPositionSinusoidAxis;

    //mémorisation de la position verticale de la nouvelle position sur la sinusoide
    fMemOrdonneeSinus = sin( radian( sinusBehaviorComp -> mfCurrentAngleSinusoid ) ) * sinusBehaviorComp -> mfAmplitudeSinusoid;

    //traitement mouvement horizontal coordonnée Y = Ordonnée origine + sin( angle actuel * PI / 180 ) * amplitude
    moveVectorAngle( posComp -> vect2DPosComp, fMemOrdonneeSinus, sinusBehaviorComp -> mfDirectionAxisSinusoid + 90 );
    //!!!verif pb avec valeur absolue!!!!!!
}

/**
 * @brief IASystem::actionRing Fonction de calcul de la rotation d'une entité autour d'un point.
 * @param posComp Le composant position de l'entité en cour de traitement.
 * @param moveComp Le composant mouvement de l'entité en cour de traitement.
 */
void IASystem::actionRing( unsigned int uiNumEntity ){
    std::cout << " RING \n";

    PositionComponent * posComp = stairwayToComponentManager() .
            searchComponentByType < PositionComponent > ( uiNumEntity , POSITION_COMPONENT );
    assert( posComp && "Erreur posComp non instancié\n" );

    RingBehaviorComponent * ringBehaviorComponent = stairwayToComponentManager() .
            searchComponentByType < RingBehaviorComponent > ( uiNumEntity , RING_BEHAVIOR_COMPONENT );
    assert( ringBehaviorComponent && "Erreur ringBehaviorComponent non instancié \n" );

    MoveableComponent * moveComp = stairwayToComponentManager() .
            searchComponentByType < MoveableComponent > ( uiNumEntity , MOVEABLE_COMPONENT );
    assert( moveComp && "Erreur moveComp non instancié \n" );

    ringBehaviorComponent -> mfCurrentAngle = addToAngle( ringBehaviorComponent -> mfCurrentAngle, moveComp -> mfVelocite );
    posComp -> vect2DPosComp . rotate( ringBehaviorComponent -> mfCurrentAngle, ringBehaviorComponent -> mvect2DRotationCenter );
    std::cout << " positionX::"<< posComp -> vect2DPosComp . mfX << "\n";
    std::cout << " positionY::"<< posComp -> vect2DPosComp . mfY << "\n";
}

/**
 * @brief IASystem::actionRoundTrip Traitement d'un parcour aller retour d'une entité, suivant une position d'origine,
 * une longueur et un angle.
 *
 * mVectFCustumVar[ 0 ] :: Angle sur lequel le composant va effectuer ses aller-retours (origine --> destination).
 * mVectFCustumVar[ 1 ] :: Longueur sur laquelle le composant va se déplacer.
 * mVectFCustumVar[ 2 ] :: Abscisse de l'origine du parcour.
 * mVectFCustumVar[ 3 ] :: Ordonnée de l'origine du parcour.
 * mVectFCustumVar[ 4 ] :: Abscisse de la destination du parcour.
 * mVectFCustumVar[ 5 ] :: Ordonnée de la destination du parcour.
 * mbCustomVarA true = sens point origine ==> point destination, false = sens point destination ==> point origine.
 * L'origine du parcour sera définis par les valeurs présentes dans le composant position(supposé initialisé).
 * La destination sera calculé dans initMoveableRoundTrip de la classe IASystem.
 *
 * @param posComp Le composant position de l'entité en cour de traitement.
 * @param moveComp Le composant mouvement de l'entité en cour de traitement.
 */
void IASystem::actionRoundTrip( unsigned int uiNumEntity ){    
    float fCurrentAngle;
    Vector2D * ptrVect2DCurrentOrigin, * ptrVect2DCurrentDestination;

    std::cout << " ROUNDTRIP \n";

    PositionComponent * posComp = stairwayToComponentManager() .
            searchComponentByType < PositionComponent > ( uiNumEntity , POSITION_COMPONENT );
    assert( posComp && "Erreur posComp non instancié\n" );

    RoundTripBehaviorComponent * roundTripBehavComp = stairwayToComponentManager() .
            searchComponentByType < RoundTripBehaviorComponent > ( uiNumEntity , ROUND_TRIP_BEHAVIOR_COMPONENT );
    assert( roundTripBehavComp && "Erreur roundTripBehavComp non instancié \n" );

    MoveableComponent * moveComp = stairwayToComponentManager() .
            searchComponentByType < MoveableComponent > ( uiNumEntity , MOVEABLE_COMPONENT );
    assert( moveComp && "Erreur moveComp non instancié \n" );

    fCurrentAngle = roundTripBehavComp -> mfDestinationDirection;

    //sens Origine ==> Destination
    if( roundTripBehavComp -> mbTowardDirection ){
        ptrVect2DCurrentDestination = & roundTripBehavComp -> mvect2DPositionDestinationTravels;
        ptrVect2DCurrentOrigin = & roundTripBehavComp -> mvect2DPositionOriginTravels;
    }
    //sens Destination ==> Origine
    else{
        fCurrentAngle = addToAngle( fCurrentAngle, 180 );
        ptrVect2DCurrentDestination = & roundTripBehavComp -> mvect2DPositionOriginTravels;
        ptrVect2DCurrentOrigin = & roundTripBehavComp -> mvect2DPositionDestinationTravels;

    }

    //appel de la fonction de mouvement en fonction de la vélocité et l'angle de l'entité
    moveVectorAngle( posComp -> vect2DPosComp, moveComp -> mfVelocite, fCurrentAngle );

    //vérification du dépassement
    if( distance( posComp -> vect2DPosComp, * ptrVect2DCurrentOrigin ) >=
            roundTripBehavComp -> mfTravelsLenght ){
        //si la longueur du trajet est dépassé par rapport à l'origine courante
        roundTripBehavComp -> mbTowardDirection = ! roundTripBehavComp -> mbTowardDirection;
        //l'entité est positionnée sur la destination courante
        posComp -> vect2DPosComp = * ptrVect2DCurrentDestination;
    }
}


/**
 * @brief IASystem::~IASystem Destructeur de la classe IASystem.
 */
IASystem::~IASystem(){

}

