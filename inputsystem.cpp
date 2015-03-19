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
 * A la fin de la fonction le bitset contenant les actions demandées est réinitalisé.
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

        bool bAllFalse = true;
        //si aucune entré utilisateur entité suivante
        for( unsigned int j = 0; j < inputComponent -> mBitsetInput.size();j++ ){
            if( inputComponent -> mBitsetInput[ j ] ){
                bAllFalse = false;
                break;
            }
        }
        if( bAllFalse )continue;

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

        //traitement évènement joueur



        //if( moveableComponent -> mbTerrestrial && moveableComponent -> mbOnTheGround ){
            if( inputComponent -> mBitsetInput[ MOVE_RIGHT ] )positionComp -> mfPositionX +=  moveableComponent -> mfVelocite;
            else if( inputComponent -> mBitsetInput[ MOVE_LEFT ] )positionComp -> mfPositionX -=  moveableComponent -> mfVelocite;
            //JUMP a implémenter
        //}
        //else{
            if( inputComponent -> mBitsetInput[ MOVE_RIGHT ] )positionComp -> mfPositionX +=  moveableComponent -> mfVelocite;
            else if( inputComponent -> mBitsetInput[ MOVE_LEFT ] )positionComp -> mfPositionX -=  moveableComponent -> mfVelocite;

            if( inputComponent -> mBitsetInput[ MOVE_UP ] )positionComp -> mfPositionY -=  moveableComponent -> mfVelocite;
            else if( inputComponent -> mBitsetInput[ MOVE_DOWN ] )positionComp -> mfPositionY +=  moveableComponent -> mfVelocite;
        //}

        //réinitialisation du bitset du composant
        inputComponent -> mBitsetInput . reset();

    }
}

/**
 * @brief InputSystem::~InputSystem Destructeur de InputSystem.
 */
InputSystem::~InputSystem(){

}

