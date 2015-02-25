#ifndef IASYSTEM_H
#define IASYSTEM_H

#include "system.hpp"

/**
 * @brief La classe IASystem éxecute le comportement que doivent avoir les entités,
 * en fonction de leurs caractéristiques présentes dans les différents composants.
 */
class IASystem : public System{
public:
    IASystem();
    void execSystem() override;
    ~IASystem();
};

#endif // IASYSTEM_H
