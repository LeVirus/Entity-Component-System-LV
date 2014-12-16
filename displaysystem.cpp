#include "displaysystem.hpp"
#include "constantes.hpp"
#include <iostream>

DisplaySystem::DisplaySystem(){
    if( bAddComponentToSystem( POSITION_COMPONENT ) ){
        std::cout << "Erreur DisplaySystem ajout positionComponent."std::endl;
    }
    if( bAddComponentToSystem( DISPLAY_COMPONENT ) ){
        std::cout << "Erreur DisplaySystem ajout displayComponent."std::endl;
    }
}
