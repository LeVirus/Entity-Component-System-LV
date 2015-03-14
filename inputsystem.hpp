#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "system.hpp"

/**
 * @brief La classe InputSystem gère les évènements venant du joueur.
 */
class InputSystem : public System{
public:
    InputSystem();
    void execSystem()override;
    ~InputSystem();
};

#endif // INPUTSYSTEM_H
