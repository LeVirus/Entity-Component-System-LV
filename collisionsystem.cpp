#include "collisionsystem.hpp"
#include "ECSconstantes.hpp"
#include "system.hpp"
#include "physicscomponent.hpp"
#include "entity.hpp"
#include "engine.hpp"
#include <cassert>

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
 * @brief CollisionSystem::execSystem Fonction vérifiant si chaque entité est en collision avec les autres.
 * Un tableau stocke les résultat.
 */
void CollisionSystem::execSystem(){
    const std::vector< Entity > & vectEntity = mptrSystemManager -> getptrEngine() -> getVectEntity();

    System::execSystem();

    for( unsigned int i = 0; i < mVectNumEntity . size() - 1; ++i ){
        //mBitSet2dTagCollision.


        for( unsigned int j = i + 1; j < mVectNumEntity . size(); ++j ){
            bEntityIsInCollision( i, j );
        }
    }

}

/**
 * @brief CollisionSystem::bEntityIsInCollision Fonction vérifiant si 2 entités sont en collision.
 * La fonction vérifie d'abord si les tags de chaque entité corresponde.
 * @param uiEntityA Le numéro de la première entité.
 * @param uiEntityB Le numéro de la deuxième entité.
 * @return false si les 2 entités ne sont pas en collision ou si les tags de ces dernières ne sont pas correspondant,
 * true sinon.
 */
bool CollisionSystem::bEntityIsInCollision( unsigned int uiEntityA, unsigned int uiEntityB ){
    const std::vector< Entity > & vectEntity = mptrSystemManager -> getptrEngine() -> getVectEntity();

    unsigned int uiTabEntitySize =  vectEntity . size();

    assert( ( uiEntityA < uiTabEntitySize && uiEntityB < uiTabEntitySize ) && "Num Entity hors tableau.\n" );

    if( ! bEntityTagMatches( uiEntityA, uiEntityB ) ){
        return false;
    }
    //recup des 2 bitset des 2 entités
    const std::bitset< NUMBR_COMPONENT > & entityBitsetA = vectEntity[ uiEntityA ] . getEntityBitSet(),
           & entityBitsetB = vectEntity[ uiEntityB ] . getEntityBitSet();

    for( unsigned int i = 0; i < entityBitsetA . size() - 1; ++i ){
        for( unsigned int j = i + 1; j < entityBitsetB . size(); ++j ){

        }
    }
}

/**
 * @brief CollisionSystem::bEntityTagMatches Fonction vérifiant dans le tableau du système( mBitSet2dTagCollision ) si les 2 tags des
 * 2 entités sont corespondant.
 * Un assert est appelé si au moins une des 2 entités ne possèdent pas le composant PHYSIC_COMPONENT.
 * @param uiEntityA Le numéro de la première entité.
 * @param uiEntityB Le numéro de la deuxième entité.
 * @return true si les tags correspondent, false sinon.
 */
bool CollisionSystem::bEntityTagMatches( unsigned int uiEntityA, unsigned int uiEntityB ){
    PhysicComponent * physicComponentEntityA = stairwayToComponentManager() .
            searchComponentByType< PhysicComponent >( uiEntityA, PHYSIC_COMPONENT ) ,

            * physicComponentEntityB = stairwayToComponentManager() .
                    searchComponentByType< PhysicComponent >( uiEntityB, PHYSIC_COMPONENT );
    assert( ( physicComponentEntityA && physicComponentEntityB ) && "PhysicComp non instancié.\n" );
    return mBitSet2dTagCollision . getValAt( physicComponentEntityA -> muiTag, physicComponentEntityB -> muiTag );
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
