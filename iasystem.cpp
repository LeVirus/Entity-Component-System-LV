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
 * !!!Le composant PositionComponent est supposé initialisé!!!
 */
void IASystem::initMoveable( unsigned int uiNumBehavior, PositionComponent *posComp, MoveableComponent *moveComp ){
    if( ! posComp || ! moveComp )return;
    switch( uiNumBehavior ){
    case UNSPECIFIED:
        break;
    case SINUSOIDAL:
        moveComp -> mVectFCustumVar . resize( 3 );
        //fabs(a.x - x) < std::numeric_limits<float>::epsilon()
        if( moveComp -> mfVelocite == 0/*std::numeric_limits< float >::epsilon()*/ ||
                moveComp -> mfVelocite > 100 )
            moveComp -> mfVelocite = 10;//!!!!float == 0!!!!si velocité non initialisée::valeur par défault

        if( moveComp -> mfCustomVarB == 0/*std::numeric_limits< float >::epsilon()*/ ||
                moveComp -> mfCustomVarB > 500 )
            moveComp -> mfCustomVarB = 100;//si mfCustomVarB(taille mvmt vertical/2 de la sinusoide) non initialisée::valeur par défault

        moveComp -> mfCustomVarA = posComp -> mfPositionY - moveComp -> mfCustomVarB;//maxY
        moveComp -> mfCustomVarB = posComp -> mfPositionY + moveComp -> mfCustomVarB;//minY
        break;
    case RING:
        break;
    case ROUND_TRIP:
        break;
    case TOWARD_PLAYER:
        break;
    }
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

            break;
        case RING:
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
 * Le déplacement horizontal sera constant, son sens sera définis par mbCustomVarD.
 * @param posComp Le composant position de l'entité en cour de traitement
 * @param moveComp Le composant mouvement de l'entité en cour de traitement
 */
void IASystem::actionSinusoid( PositionComponent * posComp, MoveableComponent * moveComp ){
    if( ! posComp || ! moveComp || posComp -> muiGetIdEntityAssociated() != moveComp -> muiGetIdEntityAssociated() )return;

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

