#include "componentmanager.hpp"
#include "engine.hpp"
#include "entity.hpp"
#include "displaycomponent.hpp"
#include "positioncomponent.hpp"
#include "behaviorcomponent.hpp"
#include "moveablecomponent.hpp"
#include "inputcomponent.hpp"
#include "physicscomponent.hpp"
#include <iostream>

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
    default :{
        break;
    }
    }
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


