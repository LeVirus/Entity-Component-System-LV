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
bool IASystem::initMoveable( BehaviorComponent *behavComp, PositionComponent *posComp, MoveableComponent *moveComp ){

    if( ! posComp || ! moveComp || posComp -> muiGetIdEntityAssociated() != moveComp -> muiGetIdEntityAssociated()
          || posComp -> muiGetIdEntityAssociated() != behavComp -> muiGetIdEntityAssociated() )return false;

    switch( behavComp -> muiTypeBehavior ){
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
void IASystem::initMoveableSinusoid( PositionComponent * posComp, MoveableComponent * moveComp ){
    if( ! posComp || ! moveComp )return;

    moveComp -> mVectFCustumVar . resize( 3 );
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
}

/**
 * @brief IASystem::initMoveableRing La fonction initialise les variables contenues dans le composant selon les critères du
 * comportement ring.
 * @param posComp Le composant position.
 * @param moveComp Le composant mouvement.
 */
void IASystem::initMoveableRing( PositionComponent * posComp, MoveableComponent * moveComp ){
    if( ! posComp || ! moveComp )return;

    moveComp -> mVectFCustumVar . resize( 4 );
    //si vélocité non initialisée ou hors limite
    if( moveComp -> mfVelocite == 0 || moveComp -> mfVelocite > 50 )
        moveComp -> mfVelocite = 10;

    moveComp -> mVectFCustumVar . resize( 4 );
    //si valeur rayon cercle non initialisée
    if( moveComp -> mVectFCustumVar[ 0 ] == 0 )moveComp -> mVectFCustumVar[ 0 ] = 50;

    //initialisation du centre du cercle avec les valeurs contenues dans posComp
    moveComp -> mVectFCustumVar[ 2 ] = posComp -> mfPositionX;
    moveComp -> mVectFCustumVar[ 3 ] = posComp -> mfPositionY;
}

/**
 * @brief IASystem::initMoveableRoundTrip La fonction initialise les variables contenues dans le composant selon les critères du
 * comportement roundtrip.
 * @param posComp Le composant position.
 * @param moveComp Le composant mouvement.
 */
void IASystem::initMoveableRoundTrip( PositionComponent * posComp, MoveableComponent * moveComp ){
    if( ! posComp || ! moveComp )return;

    moveComp -> mVectFCustumVar . resize( 6 );

    //si vélocité non initialisée ou hors limite
    if( moveComp -> mfVelocite == 0 || moveComp -> mfVelocite > 50 )
        moveComp -> mfVelocite = 10;

    //si valeur de l'angle est hors limite valeur = 0
    if( moveComp -> mVectFCustumVar[ 0 ] >= 360 )
        moveComp -> mVectFCustumVar[ 0 ] = 0;

    //si valeur de la longueur du parcour est hors limite valeur par défaut
    if( moveComp -> mVectFCustumVar[ 1 ] == 0 || moveComp -> mVectFCustumVar[ 1 ] > 100 )
        moveComp -> mVectFCustumVar[ 1 ] = 10;

    //initialisation de l'origine du parcour
    moveComp -> mVectFCustumVar[ 2 ] = posComp -> mfPositionX;
    moveComp -> mVectFCustumVar[ 3 ] = posComp -> mfPositionY;

    //calcul de la position de destination
    //modification de la position a l'aide de la fonction de déplacement
    moveEntityAngle( posComp, moveComp -> mVectFCustumVar[ 1 ], moveComp -> mVectFCustumVar[ 0 ] );
    //récupération des valeurs obtenues
    moveComp -> mVectFCustumVar[ 4 ] = posComp -> mfPositionX;
    moveComp -> mVectFCustumVar[ 5 ] = posComp -> mfPositionY;
    //remise à la position d'origine
    posComp -> mfPositionX = moveComp -> mVectFCustumVar[ 2 ];
    posComp -> mfPositionY = moveComp -> mVectFCustumVar[ 3 ];

    //initialisation du sens
    moveComp -> mbCustomVarA = true;
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
            initMoveable( behaviorComponent, positionComp, moveableComponent );
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
            actionRoundTrip( positionComp, moveableComponent );
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
        //calcul du parcour sur l'abscisse dans la partie : 0 -> PI
        fMemResult = fabs( fMemAbscisseSinus - cos( 180 ) * moveComp -> mVectFCustumVar[ 1 ] );
        //calcul du parcour sur l'abscisse dans la partie : PI -> 2PI et addition des 2
        //cos( 180 )==-1    ==>     cos( 180 ) * amplitude = -amplitude
        fMemAbscisseSinus = fMemResult + fabs( ( -1 * moveComp -> mVectFCustumVar[ 1 ] ) - ( cos( moveComp ->mVectFCustumVar[ 0 ] ) *
                moveComp -> mVectFCustumVar[ 1 ] ) );
    }
    //cas du passage d'un angle 360 >> 0
    else if( ( moveComp -> mVectFCustumVar[ 0 ] - moveComp -> mfVelocite ) > 180 && moveComp -> mVectFCustumVar[ 0 ] < 180  ){
        //calcul du parcour sur l'abscisse dans la partie : PI -> 2PI
        fMemResult = fabs( fMemAbscisseSinus - cos( 0 ) * moveComp -> mVectFCustumVar[ 1 ] );
        //calcul du parcour sur l'abscisse dans la partie : 0 -> PI et addition des 2
        //cos( 0 )==1    ==>     cos( 0 ) * amplitude = amplitude
        fMemAbscisseSinus = fMemResult + fabs( moveComp -> mVectFCustumVar[ 1 ] - cos( moveComp ->mVectFCustumVar[ 0 ] ) *
                moveComp -> mVectFCustumVar[ 1 ] );
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
 * @brief IASystem::actionRoundTrip Traitement d'un parcour aller retour d'une entité, suivant une position d'origine,
 * une longueur et un angle.
 * @param posComp Le composant position de l'entité en cour de traitement.
 * @param moveComp Le composant mouvement de l'entité en cour de traitement.
 */
void IASystem::actionRoundTrip( PositionComponent * posComp, MoveableComponent * moveComp ){

    float fCurrentAngle, fCurrentDestinationX, fCurrentDestinationY;

    /*vérification de l'instanciation des 2 composants et si l'entité(par le numéro d'identifiant) associée aux 2
    composants est bien la même*/
    if( ! posComp || ! moveComp || posComp -> muiGetIdEntityAssociated() != moveComp -> muiGetIdEntityAssociated() )return;

    //sens origine vers destination
    if( moveComp -> mbCustomVarA ){
        fCurrentAngle = moveComp -> mVectFCustumVar[ 0 ];
        fCurrentDestinationX = moveComp -> mVectFCustumVar[ 4 ];
        fCurrentDestinationY = moveComp -> mVectFCustumVar[ 5 ];
    }
    else{
        fCurrentAngle = static_cast< int >( moveComp -> mVectFCustumVar[ 0 ] + 180 ) % 360;
        fCurrentDestinationX = moveComp -> mVectFCustumVar[ 2 ];
        fCurrentDestinationY = moveComp -> mVectFCustumVar[ 3 ];
    }

    //appel de la fonction de mouvement en fonction de la vélocité et l'angle de l'entité
    moveEntityAngle( posComp, moveComp -> mfVelocite, fCurrentAngle );

    //vérification si la destination est atteinte ou dépassée
    if( bVerifExceedingMovement( posComp -> mfPositionX, posComp -> mfPositionY, fCurrentDestinationX,
                                 fCurrentDestinationX, fCurrentAngle ) ){
        //positionner entité a la valeur de la destination et inverser le booléen
        positionEntity( posComp, fCurrentDestinationX, fCurrentDestinationY );
        moveComp -> mbCustomVarA = ! moveComp -> mbCustomVarA;
    }
}

/**
 * @brief IASystem::bVerifExceedingMovement Fonction vérifiant si il y a dépassement de la destination lors d'un déplacement d'une
 * entité ayant comme comportement ROUND_TRIP(aller-retour).
 * @param fCurrentX L'abscisse de la position actuelle.
 * @param fCurrentY L'ordonnée de la position actuelle.
 * @param fDestinationX L'abscisse de la destination.
 * @param fDestinationY L'ordonnée de la destination.
 * @param fAngle L'angle déterminant la direction.
 * @return true si dépassement il y a, false sinon.
 */
bool IASystem::bVerifExceedingMovement( float fCurrentX, float fCurrentY, float fDestinationX, float fDestinationY, float fAngle ){

    //traitement Y uniquement pour angle = 90 ou 270
    if( fAngle == 90 ){
       if( fCurrentY <= fDestinationY )
           return true;
       return false;
    }
    else if( fAngle == 270 ){
        if( fCurrentY >= fDestinationY )
            return true;
        return false;
    }

    //Traitement abscisse
    else{
        //Si valeur angle de 0 à 89 ou de 271 à 359
        if( fAngle < 90 || fAngle > 270 ){
            if( fCurrentX <= fDestinationX )
                return false;
            return true;
        }
        //Si valeur angle de 91 à 269
        else{
            if( fCurrentX >= fDestinationX )
                return false;
            return true;
        }
    }


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
 * @brief IASystem::moveEntity Fonction de déplacement d'une entité à partir du nombre de pixels abscisses et ordonnés.
 * @param posComp le composant position à modifier.
 * @param fNbrPixelsX le nombre de pixels abscisses.
 * @param fNbrPixelsY le nombre de pixels ordonnés.
 */
void IASystem::moveEntity( PositionComponent * posComp, float fNbrPixelsX, float fNbrPixelsY ){
    if( ! posComp )return;
    posComp -> mfPositionX += fNbrPixelsX;
    posComp -> mfPositionY += fNbrPixelsY;
}

/**
 * @brief IASystem::positionEntity Modification de la position de l'entité avec les valeurs envoyées en arguments.
 * @param posComp le composant position à modifier.
 * @param fPosX la nouvelle valeur abscisse.
 * @param fPosY la nouvelle valeur ordonnée.
 */
void IASystem::positionEntity( PositionComponent * posComp, float fPosX, float fPosY ){
    if( ! posComp )return;
    posComp -> mfPositionX = fPosX;
    posComp -> mfPositionY = fPosY;
}


/**
 * @brief IASystem::~IASystem Destructeur de la classe IASystem.
 */
IASystem::~IASystem(){

}

