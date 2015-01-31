#ifndef DISPLAYSYSTEM_HPP
#define DISPLAYSYSTEM_HPP

#include "displaycomponent.hpp"
#include "positioncomponent.hpp"
#include "system.hpp"
#include <map>

/**
 * @brief La classe DisplaySystem permet d'afficher les entités prévues à cet effet.
 */
class DisplaySystem : public System{
    std::map< DisplayComponent *, PositionComponent * > mMapComponentDisplaySystem;
public:
    DisplaySystem();
    void execSystem() override;
    const std::map< DisplayComponent *, PositionComponent * > & getMapComponentDisplaySystem()const;
};

#endif // DISPLAYSYSTEM_HPP
