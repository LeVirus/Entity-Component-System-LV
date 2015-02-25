#include "iasystem.hpp"
#include "moveablecomponent.hpp"
#include "behaviorcomponent.hpp"
#include "physicscomponent.hpp"
#include "positioncomponent.hpp"
#include <cmath>

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
 * @brief IASystem::execSystem Fonction(surchargée) d'exécution du système sur les entités concernées
 * par le système.
 * La fonction va modifier les données contenus dans les composants(associés aux entités).
 * La fonction de la classe mère System::execSystem est appelé en début de fonction.
 * La fonction va analyser les caractéristiques physiques et comportementales de l'entité,
 * pour ensuite définir quels va(vont) être la(les) prochaine(s) action(s).
 * Ces actions vont être déterminé par le composant MoveableComponent(si non NULL) et/ou (un autre à définir).
 */
void IASystem::execSystem(){
    System::execSystem();
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
        if( positionComp ){
            std::cout << " Erreur IASystem pointeur NULL behaviorComponent " << "\n";
            continue;
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
 * @brief moveEntity Fonction de déplacement d'une entité à partir du nombre de pixels abscisses et ordonnés.
 * @param posComp le composant position à modifier.
 * @param fNbrPixelsX le nombre de pixels abscisses.
 * @param fNbrPixelsY le nombre de pixels ordonnés.
 */
void moveEntity( PositionComponent * posComp, float fNbrPixelsX, float fNbrPixelsY ){
    posComp -> mfPositionX += fMoveX;
    posComp -> mfPositionY += fMoveY;
}


/**
 * @brief IASystem::~IASystem Destructeur de la classe IASystem.
 */
IASystem::~IASystem(){

}

