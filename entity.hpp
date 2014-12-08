#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <bitset>

/**
 * @brief La classe Entity est représentative d'un élément de la scène du jeu.
 * Elle contient un vector de Component.
 *
 * Cette classe permet d'ajouter/supprimer les composents de l'entité.
 */
class Entity
{
private:
    unsigned int mUiIDEntity;
    std::bitset<16> mBitSetComponent;
    std::vector< Component > mVectComponent;
public:
    Entity();
    bool bAddComponent();
    bool bRmComponent( unsigned int uiIdComponent );
    bool bRmAllComponent();
};

#endif // ENTITY_HPP
