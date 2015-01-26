#ifndef DISPLAYSYSTEM_HPP
#define DISPLAYSYSTEM_HPP

#include "displaycomponent.hpp"
#include "system.hpp"

/**
 * @brief La classe DisplaySystem permet d'afficher les entités prévues à cet effet.
 */
class DisplaySystem : public System{
public:
    DisplaySystem();
    void execSystem() override;

};

#endif // DISPLAYSYSTEM_HPP
