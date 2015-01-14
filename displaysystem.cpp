#include "displaysystem.hpp"
#include "constantes.hpp"
#include <iostream>

DisplaySystem::DisplaySystem(){
    if( bAddComponentToSystem( POSITION_COMPONENT ) ){
        std::cout << "DisplaySystem ajout positionComponent." << std::endl;
    }
    if( bAddComponentToSystem( DISPLAY_COMPONENT ) ){
        std::cout << "DisplaySystem ajout displayComponent." << std::endl;
    }
}

/**
 * @brief DisplaySystem::execSystem Fonction(surchargée) d'exécution du système sur les noeuds stockés
 * dans le système.
 * La fonction va mettre a jour les noeud(fonction de la classe mère System::bRefreshNode) avant de lancer l'exécution.
 */
void DisplaySystem::execSystem(){

}
