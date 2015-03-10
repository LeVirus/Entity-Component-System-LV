#ifndef DISPLAYSYSTEM_HPP
#define DISPLAYSYSTEM_HPP

#include "displaycomponent.hpp"
#include "positioncomponent.hpp"
#include "system.hpp"
#include <map>

/**
 * @brief La classe DisplaySystem permet l'affichage des entités qui ont les
 * composants nécessaires(POSITION_COMPONENT, DISPLAY_COMPONENT).
 * La classe stocke les 2 paires de composants nécessaires dans un multimap qui peut être envoyé en référence constante.
 */
class DisplaySystem : public System{
    std::multimap< DisplayComponent *, PositionComponent * > mMultiMapComponentDisplaySystem;
public:
    DisplaySystem();
    void execSystem() override;
    const std::multimap< DisplayComponent *, PositionComponent * > & getMapComponentDisplaySystem()const;
};

#endif // DISPLAYSYSTEM_HPP
