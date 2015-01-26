#include "displaysystem.hpp"
#include "constantes.hpp"
#include "engine.hpp"
#include <iostream>

/**
 * @brief DisplaySystem::DisplaySystem Constructeur de la classe DisplaySystem.
 * Ajout des composants au système.
 */
DisplaySystem::DisplaySystem(){
    if( bAddComponentToSystem( POSITION_COMPONENT ) ){
        std::cout << "DisplaySystem ajout positionComponent." << std::endl;
    }
    if( bAddComponentToSystem( DISPLAY_COMPONENT ) ){
        std::cout << "DisplaySystem ajout displayComponent." << std::endl;
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

    DisplayComponent & displayComp = mptrSystemManager -> getptrEngine() -> getComponentManager() .
            searchComponentByType < DisplayComponent > ( 1, DISPLAY_COMPONENT );
}
