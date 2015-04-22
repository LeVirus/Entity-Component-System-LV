#include "collisionsystem.hpp"
#include "ECSconstantes.hpp"
#include "system.hpp"

/**
 * @brief CollisionSystem::CollisionSystem Constructeur de CollisionSystem.
 * Le nombre de tag est mis à une valeur par défaut.
 */
CollisionSystem::CollisionSystem():muiNumberTag{ 20 * 20 }{
    muiNumberTag = 20;
    mBitSet2dTagCollision . resizeTab( 20, 20 );

    if( ! bAddComponentToSystem( PHYSIC_COMPONENT ) ){
        std::cout << "Erreur GravitySystem ajout PHYSIC_COMPONENT.\n";
    }
}

/**
 * @brief CollisionSystem::bModifyNumberTag Modification du nombre maximum valeur de tag( identifiant déterminant
 * avec quoi un objet peut entrer en collision ).
 * @param uiNumTag Le nouveau nombre de tag.
 */
void CollisionSystem::bModifyNumberTag( unsigned int uiNumTag ){
    muiNumberTag = uiNumTag;

    mBitSet2dTagCollision . resizeTab( uiNumTag, uiNumTag );
}

/**
 * @brief CollisionSystem::execSystem
 */
void CollisionSystem::execSystem() override{
    const std::vector< Entity > & vectEntity = mptrSystemManager -> getptrEngine() -> getVectEntity();
    System::execSystem();

}

/**
 * @brief CollisionSystem::attributeVectTabTagCollision Attribution d'un nouveau tableau de tag.
 * @param vectBool La référence du tableau à copier.
 * @param uiLenght La longueur du tableau.
 * @return true si l'opération a été effectuée avec succés, false sinon.
 */
bool CollisionSystem::attributeVectTabTagCollision( const std::vector< bool > & vectBool, unsigned int uiLenght ){
    return mBitSet2dTagCollision . bAttributeTab( vectBool, uiLenght, uiLenght );
}
