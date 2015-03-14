#include "inputsystem.hpp"
#include "inputcomponent.hpp"
#include "moveablecomponent.hpp"
#include "positioncomponent.hpp"

/**
 * @brief InputSystem::InputSystem Constructeur de InputSystem.
*/
InputSystem::InputSystem(){
    if( ! bAddComponentToSystem( POSITION_COMPONENT ) ){
        std::cout << "Erreur InputSystem ajout POSITION_COMPONENT.\n";
    }
    if( ! bAddComponentToSystem( MOVEABLE_COMPONENT ) ){
        std::cout << "Erreur InputSystem ajout MOVEABLE_COMPONENT.\n";
    }
    if( ! bAddComponentToSystem( INPUT_COMPONENT ) ){
        std::cout << "Erreur InputSystem ajout INPUT_COMPONENT.\n";
    }
}

/**
 * @brief InputSystem::execSystem Fonction(surchargée) d'exécution du système sur les entités concernées
 * par le système.
 * La fonction va vérifier les actions demandées par le joueur.
 * Ces actions vont être effectuées ou non en fonction du type de l'entité, de l'état de cette entité
 * ou de la possibilité de simultanéités des actions demandées(dans le cas précis).
 */
void InputSystem::execSystem(){
    System::execSystem();
    for( unsigned int i = 0 ; i < mVectNumEntity.size() ; ++i ){

        InputComponent * inputComponent = stairwayToComponentManager() .
                searchComponentByType < InputComponent > ( mVectNumEntity[ i ], INPUT_COMPONENT );
        if( ! inputComponent ){
            std::cout << " IASystem pointeur NULL inputComponent \n";
            continue;
        }


        MoveableComponent * moveableComponent = stairwayToComponentManager() .
                searchComponentByType < MoveableComponent > ( mVectNumEntity[ i ], MOVEABLE_COMPONENT );
        if( ! moveableComponent ){
            std::cout << " IASystem pointeur NULL moveableComponent \n";
            continue;
        }

        PositionComponent * positionComp = stairwayToComponentManager() .
                searchComponentByType < PositionComponent > ( mVectNumEntity[ i ], POSITION_COMPONENT );
        if( ! positionComp ){
            std::cout << " Erreur IASystem pointeur NULL positionComp \n";
            continue;
        }
    }
}

/**
 * @brief InputSystem::~InputSystem Destructeur de InputSystem.
 */
InputSystem::~InputSystem(){

}

