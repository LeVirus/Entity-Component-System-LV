#ifndef ENGINE_HPP
#define ENGINE_HPP


#include <vector>

/**
 * @brief La classe Engine est la classe de base de la bibliothèque.
 * Elle contient un vector d'Entity et un objet SystemManager
 *
 * Cette classe permet d'ajouter/supprimer les Entity, et de lancer ou stoper la gestion des systèmes.
 */

class Engine
{
private:
    std::vector< Entity > mVectEntity;
    SystemManager mSystemManager;
public:
    Engine();
    bool bAddEntity();
    bool bRmEntity( unsigned int uiIdEntity );
    bool bRmAllEntity();
};

#endif // ENGINE_HPP
