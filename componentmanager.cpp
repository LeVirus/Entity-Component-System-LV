#include "componentmanager.hpp"
#include "engine.hpp"
#include "entity.hpp"
#include "displaycomponent.hpp"
#include "positioncomponent.hpp"
#include "behaviorcomponent.hpp"
#include "moveablecomponent.hpp"
#include "inputcomponent.hpp"
#include "physicscomponent.hpp"
#include "groundcomponent.hpp"
#include "ringbehaviorcomponent.hpp"
#include "roundtripbehaviorcomponent.hpp"
#include "sinusoidbehaviorcomponent.hpp"
#include "collrectboxcomponent.hpp"
#include "collsegmentcomponent.hpp"
#include <iostream>
#include <cassert>

ComponentManager::ComponentManager(){
}

/**
 * @brief ComponentManager::bUpdateComponentFromEntity Fonction de mise à jour des composants
 * a partir des caractéristiques des entités. La fonction va vérifier sur chaque entité si elle est à jour,
 * si ce n'est pas le cas la fonction enchaine sur l'itération suivante.
 */
void ComponentManager::updateComponentFromEntity(){
    const std::vector< Entity > & vectEntitycst = mptrEngine -> getVectEntity();

    //en cas de besoin resize du tableau de composants
    if( mVectComponent.size() < vectEntitycst.size() * NUMBR_COMPONENT ){
        mVectComponent.resize( vectEntitycst.size() * NUMBR_COMPONENT );
    }

    for( unsigned int i = 0 ; i < vectEntitycst . size() ; ++i ){
        //si l'entité est à jour
        if( vectEntitycst[ i ] . bEntityIsUpToDate() )continue;

        const std::bitset< NUMBR_COMPONENT > & bitsetComponent = vectEntitycst[ i ].getEntityBitSet();
        for( unsigned int j = 0 ; j < bitsetComponent.size() ; ++j ){
            //si la case du bitset est à true et que la case correspondante dans le vector de component est à NULL
            if( bitsetComponent[ j ] && ! mVectComponent[ i * NUMBR_COMPONENT + j ] ){
                instanciateComponent( i * NUMBR_COMPONENT + j );
                //Indiquer le numéro de l'entité associé au composant
                mVectComponent[ i * NUMBR_COMPONENT + j ] -> setIDEntityAssociated( vectEntitycst[ i ] . muiGetIDEntity() );
            }
            //si la case du bitset est à false et que la case correspondante dans le vector de component est instanciée
            else if( ! bitsetComponent[ j ] && mVectComponent[ i * NUMBR_COMPONENT + j ] ){
                mVectComponent[ i * NUMBR_COMPONENT + j ].reset();
            }
        }
    }
}

/**
 * @brief ComponentManager::instanciateComponent Instanciation du composant
 * correspondant au numéro de case envoyé en paramètre.
 * Le type de composant est déterminé avec uiNumCase % NUMBR_COMPONENT.
 * @param uiNumCase Le numéro de case ou sera instancié le nouveau composant.
 */
void ComponentManager::instanciateComponent( unsigned int uiNumCase ){
    switch( uiNumCase % NUMBR_COMPONENT ){
    case DISPLAY_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< DisplayComponent >();
        break;
    }
    case POSITION_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< PositionComponent >();
        break;
    }
    case BEHAVIOR_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< BehaviorComponent >();
        break;
    }
    case MOVEABLE_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< MoveableComponent >();
        break;
    }
    case PHYSIC_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< PhysicComponent >();
        break;
    }
    case INPUT_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< InputComponent >();
        break;
    }
    case GROUND_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< GroundComponent >();
        break;
    }
    case ROUND_TRIP_BEHAVIOR_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< RoundTripBehaviorComponent >();
        break;
    }
    case SINUSOID_BEHAVIOR_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< SinusoidBehaviorComponent >();
        break;
    }
    case RING_BEHAVIOR_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< RingBehaviorComponent >();
        break;
    }
    case COLL_RECTBOX_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< CollRectBoxComponent >();
        break;
    }
    case COLL_SEGMENT_COMPONENT :{
        mVectComponent[ uiNumCase ] = std::make_unique< CollSegmentComponent >();
        break;
    }
    default :{
        assert( false && " Num Component Incorrect\n " );
        break;
    }
    }
}

/**
 * @brief ComponentManager::bVerifComponentInstanciate La fonction vérifie si la case demandée est bien dans le tableau
 * dans un premier temps, et si le pointeur en question n'est pas NULL.
 * @param uiNumEntity le numéro de l'entité à qui appartient le composant.
 * @param uiTypeComponent Le type de composant demandé.
 * @return false si le pointeur est NULL, true sinon.
 */
bool ComponentManager::bVerifComponentInstanciate( unsigned int uiNumEntity, unsigned int uiTypeComponent ){
    if( uiNumEntity * NUMBR_COMPONENT + uiTypeComponent >= mVectComponent.size() )
        return false;
    if( mVectComponent[ uiNumEntity * NUMBR_COMPONENT + uiTypeComponent ] )
        return true;
    return false;
}

/**
 * @brief ComponentManager::displayComponent Affichage des composant contenu dans le vector.
 */
void ComponentManager::displayComponent()const{
    std::cout << "DEBUT AFFICHAGE COMPONENT\n";
    for( unsigned int i = 0 ; i < mVectComponent.size() ; ++i ){
        if( ! mVectComponent[ i ] )continue;
        std::cout << "i::" << i << "\n";
        mVectComponent[ i ] -> displayComponent();
    }
    std::cout << "FIN AFFICHAGE COMPONENT\n";
}

/**
 * @brief ComponentManager::linkEngineToComponentManager Fonction liant Engine à ComponentManager par un pointeur.
 * @param ptrEngine Un pointeur vers Engine
 */
void ComponentManager::linkEngineToComponentManager( Engine *ptrEngine ){
    mptrEngine = ptrEngine;
}


