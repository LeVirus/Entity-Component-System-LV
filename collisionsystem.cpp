#include "collisionsystem.hpp"
#include "ECSconstantes.hpp"
#include "system.hpp"
#include "physicscomponent.hpp"
#include "entity.hpp"
#include "engine.hpp"
#include "collsegmentcomponent.hpp"
#include "collrectboxcomponent.hpp"
#include "positioncomponent.hpp"

#include "segment.hpp"
#include "rectbox.hpp"
#include "bitset2d.hpp"
#include <cassert>

/**
 * @brief CollisionSystem::CollisionSystem Constructeur de CollisionSystem.
 * Le nombre de tag est mis à une valeur par défaut.
 */
CollisionSystem::CollisionSystem():muiNumberTag{ 20 }{
    mBitSet2dTagCollision . resizeTab( 20, 20 );

    if( ! bAddComponentToSystem( PHYSIC_COMPONENT ) ){
        std::cout << "Erreur GravitySystem ajout PHYSIC_COMPONENT.\n";
    }
    if( ! bAddComponentToSystem( POSITION_COMPONENT ) ){
        std::cout << "Erreur GravitySystem ajout POSITION_COMPONENT.\n";
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
    bool bEtatCaseBitSet;
    //const std::vector< Entity > & vectEntity = mptrSystemManager -> getptrEngine() -> getVectEntity();

    System::execSystem();

    for( unsigned int i = 0; i < mVectNumEntity . size() - 1; ++i ){
        //mBitSet2dTagCollision.


        for( unsigned int j = i + 1; j < mVectNumEntity . size(); ++j ){

            //vérification des tags.
            if( ! bEntityTagMatches( mVectNumEntity[ i ], mVectNumEntity[ j ] ) ){
                bEtatCaseBitSet = false;
            }
            else{
                bEtatCaseBitSet = bEntityIsInCollision( mVectNumEntity[ i ], mVectNumEntity[ j ] );
            }
            //Mémorisations des collisions dans le tableau
            mBitSet2dInCollision . attributeValToCase( mVectNumEntity[ i ], mVectNumEntity[ j ], bEtatCaseBitSet );
            mBitSet2dInCollision . attributeValToCase( mVectNumEntity[ j ], mVectNumEntity[ i ], bEtatCaseBitSet );
        }
    }

    displaySystem();

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

    unsigned int uiTabEntitySize = vectEntity . size(),
            uiNumComponentCurrent, uiNumEntityCurrent = uiEntityA, uiNumFigureEntityA, uiNumFigureEntityB;

    //Verif si les numéros d'entités sont bien dans le tableau
    assert( ( uiEntityA < uiTabEntitySize && uiEntityB < uiTabEntitySize ) && "Num Entity hors tableau.\n" );

    //Maj de la position des figures de collisions.
    updateCollPosition( uiEntityA );
    updateCollPosition( uiEntityB );

    //Récup des bitsets de composants des entités
    const std::bitset< NUMBR_COMPONENT > & entityBitsetA = vectEntity[ uiEntityA ] . getEntityBitSet(),
            & entityBitsetB = vectEntity[ uiEntityB ] . getEntityBitSet();

    Segment *collSegmentCompA = nullptr, *collSegmentCompB = nullptr;
    RectBox *collRectBoxCompA = nullptr, *collRectBoxCompB = nullptr;

    //parcours de tous les composants et traitement de chacun d'eux 2 à 2
    for( unsigned int i = NUM_MIN_COLL_COMPONENT; i < NUM_MAX_COLL_COMPONENT; ++i ){
        for( unsigned int j = NUM_MIN_COLL_COMPONENT; j < NUM_MAX_COLL_COMPONENT; ++j ){

            //Verification de l'existance des figures
            if( entityBitsetA[ i ] && entityBitsetB[ j ] ){

                //Récupération des 2 figures à tester
                for( unsigned int k = 0; k < 2; ++k ){
                    uiNumComponentCurrent = i;
                    if( k == 1 ){
                        uiNumComponentCurrent = j;
                        uiNumEntityCurrent = uiEntityB;
                    }

                    switch( uiNumComponentCurrent ){
                    case COLL_SEGMENT_COMPONENT:{
                        CollSegmentComponent * collSegmentCompCurrent = stairwayToComponentManager() .
                                searchComponentByType < CollSegmentComponent > ( uiNumEntityCurrent, COLL_SEGMENT_COMPONENT );

                        assert( collSegmentCompCurrent && "collSegmentComp non instancié\n" );

                        if( k == 0 ){
                            collSegmentCompA = &collSegmentCompCurrent -> mCollSegment;;
                            uiNumFigureEntityA = COLL_SEGMENT_COMPONENT - NUM_MIN_COLL_COMPONENT;
                        }
                        else{
                            collSegmentCompB = &collSegmentCompCurrent -> mCollSegment;;
                            uiNumFigureEntityB = COLL_SEGMENT_COMPONENT - NUM_MIN_COLL_COMPONENT;
                        }

                        break;
                    }
                    case COLL_RECTBOX_COMPONENT:{
                        CollRectBoxComponent * collRectBoxCompCurrent = stairwayToComponentManager() .
                                searchComponentByType < CollRectBoxComponent > ( uiNumEntityCurrent, COLL_RECTBOX_COMPONENT );

                        assert( collRectBoxCompCurrent && "collSegmentComp non instancié\n" );

                        if( k == 0 ){
                            collRectBoxCompA = &collRectBoxCompCurrent -> mRectBox;
                            uiNumFigureEntityA = COLL_RECTBOX_COMPONENT - NUM_MIN_COLL_COMPONENT;
                        }
                        else{
                            collRectBoxCompB = &collRectBoxCompCurrent -> mRectBox;
                            uiNumFigureEntityB = COLL_RECTBOX_COMPONENT - NUM_MIN_COLL_COMPONENT;
                        }

                        break;
                    }
                    default:{
                        assert( false && "uiNumComponentCurrent non valide\n" );
                        break;
                    }
                    }//Fin_Switch

                }//Fin_Boucle_k
                //Récupération faite

                //Test collision
                if( uiNumFigureEntityA == COLL_SEGMENT_COMPONENT - NUM_MIN_COLL_COMPONENT &&
                        uiNumFigureEntityB == COLL_SEGMENT_COMPONENT - NUM_MIN_COLL_COMPONENT ){
                    //appel de la fonction correspondante dans le bibliothèque de collisions
                    if( bIsInCollision( *collSegmentCompA, *collSegmentCompB ) )return true;
                }
                else if( uiNumFigureEntityA == COLL_SEGMENT_COMPONENT - NUM_MIN_COLL_COMPONENT &&
                         uiNumFigureEntityB == COLL_RECTBOX_COMPONENT - NUM_MIN_COLL_COMPONENT ){
                    if( bIsInCollision( *collSegmentCompA, *collRectBoxCompB ) )return true;
                }
                else if( uiNumFigureEntityA == COLL_RECTBOX_COMPONENT - NUM_MIN_COLL_COMPONENT &&
                         uiNumFigureEntityB == COLL_SEGMENT_COMPONENT - NUM_MIN_COLL_COMPONENT ){
                    if( bIsInCollision( *collSegmentCompB, *collRectBoxCompA ) )return true;
                }
                else if( uiNumFigureEntityA == COLL_RECTBOX_COMPONENT - NUM_MIN_COLL_COMPONENT &&
                         uiNumFigureEntityB == COLL_RECTBOX_COMPONENT - NUM_MIN_COLL_COMPONENT ){
                    if( bIsInCollision( *collRectBoxCompA, *collRectBoxCompB ) )return true;
                }

            }//Fin_if
        }//Fin_Boucle_j
    }//Fin_Boucle_i
    return false;
}

/**
 * @brief CollisionSystem::updateCollPosition Fonction de mise à jour de la position de la figure de collision par rapport
 * au composant position de l'entité.
 * @param uiEntity Le numéro de l'entité à mettre à jour.
 */
void CollisionSystem::updateCollPosition( unsigned int uiEntity ){
    PositionComponent * posCompEntity = stairwayToComponentManager() .
            searchComponentByType < PositionComponent > ( uiEntity, POSITION_COMPONENT );
    assert( posCompEntity && " posCompEntity non instancié\n " );

    const std::bitset< NUMBR_COMPONENT > & bitSetEntity =
            mptrSystemManager -> getptrEngine() -> getVectEntity()[ uiEntity ] . getEntityBitSet();

    for( unsigned int i = NUM_MIN_COLL_COMPONENT ; i < NUM_MAX_COLL_COMPONENT ; ++i ){
        if( bitSetEntity[ i ] ){
            switch( i ){

            case COLL_SEGMENT_COMPONENT:{
                CollSegmentComponent * collSegmentEntity = stairwayToComponentManager() .
                        searchComponentByType < CollSegmentComponent > ( uiEntity, COLL_SEGMENT_COMPONENT );
                assert( collSegmentEntity && " collSegmentEntity non instancié\n " );

                collSegmentEntity -> mCollSegment . moveSegment( posCompEntity -> vect2DPosComp + collSegmentEntity -> mVect2dVectOrigins );

                break;
            }

            case COLL_RECTBOX_COMPONENT:{
                CollRectBoxComponent * collRectBoxEntity = stairwayToComponentManager() .
                        searchComponentByType < CollRectBoxComponent > ( uiEntity, COLL_RECTBOX_COMPONENT );
                assert( collRectBoxEntity && " collRectBoxEntity non instancié\n " );

                collRectBoxEntity -> mRectBox . modifyOriginsRectBox(
                            posCompEntity -> vect2DPosComp + collRectBoxEntity -> mVect2dVectOrigins );

                break;
            }
            default:{
                assert( false && "Numéro composant invalide\n" );
                break;
            }
            }
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

    //if( physicComponentEntityA -> muiTag == SOL )

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

/**
 * @brief CollisionSystem::displayCollisionSystem Affichage des tableaux de collisions et de tags.
 */
void CollisionSystem::displaySystem()const{
    std::cout << "Affichage Tableau Tag collisions\n";
    mBitSet2dTagCollision . displayTab();
    std::cout << "Affichage Tableau collisions\n";
    mBitSet2dInCollision . displayTab();

}
