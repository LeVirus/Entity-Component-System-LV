#include "iasystem.hpp"

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
}

/**
 * @brief DisplaySystem::execSystem Fonction(surchargée) d'exécution du système sur les entités concernées
 * par le système.
 * La fonction va modifier les données contenus dans les composants(associés aux entités).
 * La fonction de la classe mère System::execSystem est appelé en début de fonction.
 * La fonction va analyser les caractéristiques physiques et comportementales de l'entité,
 * pour ensuite définir quels va(vont) être la(les) prochaine(s) action(s).
 * Ces actions vont être déterminé par le composant MoveableComponent(si non NULL) et/ou (un autre à définir).
 */
void DisplaySystem::execSystem(){
    System::execSystem();
}

/**
 * @brief IASystem::~IASystem Destructeur de la classe IASystem.
 */
IASystem::~IASystem(){

}

