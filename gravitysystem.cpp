#include "gravitysystem.hpp"
#include "ECSconstantes.hpp"
#include "positioncomponent.hpp"
#include "moveablecomponent.hpp"
#include "groundcomponent.hpp"
#include "displaycomponent.hpp"
#include <cassert>

/**
 * @brief GravitySystem::GravitySystem Constructeur de GravitySystem.
 */
GravitySystem::GravitySystem(){
    muiValueGravity = 20;
    if( ! bAddComponentToSystem( POSITION_COMPONENT ) ){
        std::cout << "Erreur GravitySystem ajout POSITION_COMPONENT.\n";
    }
    if( ! bAddComponentToSystem( MOVEABLE_COMPONENT ) ){
        std::cout << "Erreur GravitySystem ajout MOVEABLE_COMPONENT.\n";
    }
    if( ! bAddComponentToSystem( GROUND_COMPONENT ) ){
        std::cout << "Erreur GravitySystem ajout GROUND_COMPONENT.\n";
    }
}

/**
 * @brief GravitySystem::bSetGravityValue Modification de la valeur de gravité, qui s'applique aux entités de type terrestre.
 * Si la valeur en paramètre est hors limite, aucune modification n'est faite.
 * @param uiValueGravity La nouvelle valeur de la gravité.
 * @return true si la nouvelle valeur a été intégré, false sinon.
 */
bool GravitySystem::bSetGravityValue( unsigned int uiValueGravity ){
    if( uiValueGravity > 50 )return false;
    muiValueGravity = uiValueGravity;
    return true;
}

/**
 * @brief GravitySystem::recupComponentToEntity Recupération des pointeur des composants "PositionComponent" et "MoveableComponent"
 * de chaque entité à traiter par GravitySystem.
 * Les pointeurs sont stockées dans un vector de pair.
 * Une vérification de l'instanciation de chaque pointeur est effectuée.
 */
void GravitySystem::recupComponentToEntity(){
    System::execSystem();


    mVectTupleComponentGravitySystem.clear();

    for( unsigned int i = 0 ; i < mVectNumEntity.size() ; ++i ){

        //vérification de l'instanciation des 2 composants
        if( ! stairwayToComponentManager() . bVerifComponentInstanciate( mVectNumEntity[ i ], POSITION_COMPONENT ) ||
                ! stairwayToComponentManager() . bVerifComponentInstanciate( mVectNumEntity[ i ], MOVEABLE_COMPONENT ) ||
                ! stairwayToComponentManager() . bVerifComponentInstanciate( mVectNumEntity[ i ], GROUND_COMPONENT ) )
            continue;

        PositionComponent * positionComp = stairwayToComponentManager() .
                searchComponentByType < PositionComponent > ( mVectNumEntity[ i ], POSITION_COMPONENT );
        assert( positionComp  && "positionComp non instancié" );
        //verif du pointeur

        MoveableComponent * moveableComponent = stairwayToComponentManager() .
                searchComponentByType < MoveableComponent > ( mVectNumEntity[ i ], MOVEABLE_COMPONENT );
        assert( moveableComponent && "moveableComponent non instancié" );

        GroundComponent * groundComponent = stairwayToComponentManager() .
                searchComponentByType < GroundComponent > ( mVectNumEntity[ i ], GROUND_COMPONENT );
        assert( groundComponent && "groundComponent non instancié" );

            //mémorisation des composant pour le traitement des collisions avec le sol
            mVectTupleComponentGravitySystem.push_back( std::make_tuple( moveableComponent , positionComp,
                                                                         groundComponent, i ) );

    }
}


/**
 * @brief GravitySystem::execSystem Fonction(surchargée) d'exécution du système sur les entités concernées
 * par le système.
 * La fonction va vérifier si les entités sont de type terrestre et si elle se trouve en l'air.
 * Si tel est le cas la gravité va s'appliquer sur ces dernières.
 * Pendant la procédure les références des composants PositionComponent et MoveableComponent des entités traitées
 * vont être récupéré et placé dans le multimap de la classe(cela permettra d'exporter les
 * données pour traiter les intéractions avec le sol).
 */
void GravitySystem::execSystem(){
    recupComponentToEntity();

    for( unsigned int i = 0 ; i < mVectTupleComponentGravitySystem.size() ; ++i ){
        if( ! std::get< 2 >( mVectTupleComponentGravitySystem[ i ] ) -> mbOnTheGround ){

            std::get< 2 >( mVectTupleComponentGravitySystem[ i ] ) ->
                    mCollSegment . bAttributePointAToSegment(
                        Vector2D( std::get< 1 >( mVectTupleComponentGravitySystem[ i ] ) -> vect2DPosComp ) );

            std::get< 1 >( mVectTupleComponentGravitySystem[ i ] ) -> vect2DPosComp . mfX += muiValueGravity;

            std::get< 2 >( mVectTupleComponentGravitySystem[ i ] ) ->
                    mCollSegment . bAttributePointBToSegment(
                        Vector2D( std::get< 1 >( mVectTupleComponentGravitySystem[ i ] ) -> vect2DPosComp ) );

            //a modifier prendre en compte l'inertie
        }
    }
}

/**
 * @brief GravitySystem::getMapComponentGravitySystem
 * @return
 */
std::vector< std::tuple< MoveableComponent *, PositionComponent *, GroundComponent *, unsigned int > > *
GravitySystem::getVectTupleComponentGravitySystem(){
    return &mVectTupleComponentGravitySystem;
}

/**
 * @brief GravitySystem::~GravitySystem Destructeur de GravitySystem.
 */
GravitySystem::~GravitySystem(){

}

