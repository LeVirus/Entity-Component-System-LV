#include "displaysystem.hpp"
#include "positioncomponent.hpp"
#include "ECSconstantes.hpp"
#include "engine.hpp"
#include <iostream>

namespace ecs
{

/**
 * @brief DisplaySystem::DisplaySystem Constructeur de la classe DisplaySystem.
 * Ajout des composants au système.
 */
DisplaySystem::DisplaySystem()
{
    if( ! bAddComponentToSystem( POSITION_COMPONENT ) ){
		std::cout << "Erreur displaySystem ajout positionComponent.\n";
    }
    if( ! bAddComponentToSystem( DISPLAY_COMPONENT ) ){
		std::cout << "Erreur displaySystem ajout displayComponent.\n";
    }
}

/**
 * @brief DisplaySystem::execSystem Fonction(surchargée) d'exécution du système sur les entités concernées
 * par le système.
 * La fonction va modifier les données contenus dans les composants(associés aux entités).
 * La fonction de la classe mère System::execSystem est appelé en début de fonction.
 */
void DisplaySystem::execSystem(){
    System::execSystem();
    for( unsigned int i = 0 ; i < mVectNumEntity.size() ; ++i ){
        std::cout << mVectNumEntity[ i ] << "\n";
        DisplayComponent * displayComp = stairwayToComponentManager() .
                searchComponentByType < DisplayComponent > ( mVectNumEntity[ i ], DISPLAY_COMPONENT );
        /*if( displayComp ){
            std::cout << " pointeur non NULL dis" << "\n";
        }*/
        PositionComponent * positionComp = stairwayToComponentManager() .
                searchComponentByType < PositionComponent > ( mVectNumEntity[ i ], POSITION_COMPONENT );
        /*if( positionComp ){
            std::cout << " pointeur non NULL pos" << "\n";
        }*/
        if( displayComp && positionComp ){
            mVectComponentDisplaySystem . push_back( { displayComp , positionComp } );
        }
    }
}

/**
 * @brief DisplaySystem::getMapComponentDisplaySystem Fonction renvoyant une référence constante du conteneur
 * map contenant les pointeurs des composants nécessaire au système "DisplaySystem".
 * @return référence constante de mVectComponentDisplaySystem.
 */
const std::vector<std::pair<DisplayComponent *, PositionComponent *> > * DisplaySystem::getVectComponentDisplaySystem()const{
    return &mVectComponentDisplaySystem;
}


}//fin namespace
