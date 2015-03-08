#ifndef DISPLAYSYSTEM_HPP
#define DISPLAYSYSTEM_HPP

#include "displaycomponent.hpp"
#include "positioncomponent.hpp"
#include "system.hpp"
#include <map>

/**
 * @brief La classe DisplaySystem permet d'afficher les entités qui ont les composants nécessaires.
 */
class DisplaySystem : public System{
    std::multimap< DisplayComponent *, PositionComponent * > mMultiMapComponentDisplaySystem;
public:
    DisplaySystem();
    void execSystem() override;
    const std::multimap< DisplayComponent *, PositionComponent * > & getMapComponentDisplaySystem()const;
};

#endif // DISPLAYSYSTEM_HPP
