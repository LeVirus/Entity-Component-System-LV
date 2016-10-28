#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "system.hpp"


namespace ecs
{

/**
 * @brief La classe InputSystem gère les évènements venant du joueur.
 */
class InputSystem : public System{
public:
    InputSystem();
    void execSystem()override;
    ~InputSystem();
};

}//fin namespace
#endif // INPUTSYSTEM_H
