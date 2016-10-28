#ifndef DISPLAYSYSTEM_HPP
#define DISPLAYSYSTEM_HPP

#include "displaycomponent.hpp"
#include "positioncomponent.hpp"
#include "system.hpp"
#include <vector>


namespace ecs
{

/**
 * @brief La classe DisplaySystem permet l'affichage des entités qui ont les
 * composants nécessaires(POSITION_COMPONENT, DISPLAY_COMPONENT).
 * La classe stocke les 2 paires de composants nécessaires dans un multimap qui peut être envoyé en référence constante.
 */
class DisplaySystem : public System{
    std::vector< std::pair< DisplayComponent *, PositionComponent * > > mVectComponentDisplaySystem;
public:
    DisplaySystem();
    void execSystem() override;
    const std::vector< std::pair< DisplayComponent *, PositionComponent * > > * getVectComponentDisplaySystem()const;
};

}//fin namespace
#endif // DISPLAYSYSTEM_HPP
