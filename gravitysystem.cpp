#include "gravitysystem.hpp"
#include "ECSconstantes.hpp"
#include "positioncomponent.hpp"
#include "moveablecomponent.hpp"

/**
 * @brief GravitySystem::GravitySystem Constructeur de GravitySystem.
 */
GravitySystem::GravitySystem(){
    muiValueGravity = 20;
    if( ! bAddComponentToSystem( POSITION_COMPONENT ) ){
        std::cout << "Erreur GravitySystem ajout POSITION_COMPONENT.\n";
    }
    if( ! bAddComponentToSystem( MOVEABLE_COMPONENT ) ){
        std::cout << "Erreur GravitySystem ajout MOVEABLE_COMPONENT.\n";
    }
}

/**
 * @brief GravitySystem::bSetGravityValue Modification de la valeur de gravité, qui s'applique aux entités de type terrestre.
 * Si la valeur en paramètre est hors limite, aucune modification n'est faite.
 * @param uiValueGravity La nouvelle valeur de la gravité.
 * @return true si la nouvelle valeur a été intégré, false sinon.
 */
bool GravitySystem::bSetGravityValue( unsigned int uiValueGravity ){
    if( uiValueGravity > 50 )return false;
    muiValueGravity = uiValueGravity;
    return true;
}

/**
 * @brief GravitySystem::execSystem Fonction(surchargée) d'exécution du système sur les entités concernées
 * par le système.
 * La fonction va vérifier si les entités sont de type terrestre et si elle se trouve en l'air.
 * Si tel est le cas la gravité va s'appliquer sur ces dernières.
 * Pendant la procédure les références des composants PositionComponent et MoveableComponent des entités traitées
 * vont être récupéré et placé dans le multimap de la classe(cela permettra d'exporter les
 * données pour traiter les intéractions avec le sol).
 */
void GravitySystem::execSystem(){
    System::execSystem();
    for( unsigned int i = 0 ; i < mVectNumEntity.size() ; ++i ){
        PositionComponent * positionComp = stairwayToComponentManager() .
                searchComponentByType < PositionComponent > ( mVectNumEntity[ i ], POSITION_COMPONENT );
        if( ! positionComp ){
            std::cout << " Erreur GravitySystem pointeur NULL positionComp \n";
            continue;
        }

        MoveableComponent * moveableComponent = stairwayToComponentManager() .
                searchComponentByType < MoveableComponent > ( mVectNumEntity[ i ], MOVEABLE_COMPONENT );
        if( ! moveableComponent ){
            std::cout << " Erreur GravitySystem pointeur NULL moveableComponent \n";
            continue;
        }

        if( moveableComponent -> mbTerrestrial ){
            if( ! moveableComponent -> mbOnTheGround ){
                positionComp -> mfPositionY -= muiValueGravity;
                //a modifier prendre en compte l'inertie
            }
            //mémorisation des composant pour le traitement des collisions avec le sol
            mMultiMapComponentGravitySystem.insert( std::multimap< MoveableComponent *,PositionComponent * >::value_type(
                                                        moveableComponent , positionComp ) );
        }
    }
}

/**
 * @brief GravitySystem::getMapComponentGravitySystem
 * @return
 */
std::multimap< MoveableComponent *, PositionComponent * > & GravitySystem::getMapComponentGravitySystem(){
    return mMultiMapComponentGravitySystem;
}

/**
 * @brief GravitySystem::~GravitySystem Destructeur de GravitySystem.
 */
GravitySystem::~GravitySystem(){

}

