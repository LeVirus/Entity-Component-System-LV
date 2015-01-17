#include "componentmanager.hpp"
#include "engine.hpp"
#include "displaycomponent.hpp"
#include "positioncomponent.hpp"
#include <iostream>

ComponentManager::ComponentManager(){
    mVectComponent.resize( 20 );
}

/**
 * @brief ComponentManager::bUpdateComponentFromEntity Fonction de mise à jour des composants
 * a partir des caractéristiques des entités. La fonction va vérifier si le booléen (statique) est a true,
 * si ce n'est pas le cas la mise a jour ne sera pas effectué.
 * @return true si la mise à jour est effectuée, false sinon.
 */
bool ComponentManager::bUpdateComponentFromEntity(){

    bool breturn = true;
    const std::vector< Entity > & vectEntitycst = mptrEngine -> getVectEntity();
    for( unsigned int i = 0 ; i < vectEntitycst.size() ; ++i ){
        //si l'entité est à jour
        if( vectEntitycst[ i ].bEntityIsUpToDate() )continue;
        const std::bitset< NUMBR_COMPONENT > & bitsetComponent = vectEntitycst[ i ].getEntityBitSet();
        for( unsigned int j = 0 ; j < bitsetComponent.size() ; ++j ){
            //si la case du bitset est à true et que la case correspondante dans le vector de component est à NULL
            if( bitsetComponent[ j ] && ! mVectComponent[ i * NUMBR_COMPONENT + j ] ){
                instanciateComponent( i * NUMBR_COMPONENT + j );
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
        default :{
            break;
        }
    }
}

/**
 * @brief ComponentManager::displayComponent Affichage des composant contenu dans le vector.
 */
void ComponentManager::displayComponent()const{
    std::cout << "DEBUT AFFICH COMPONENT\n";
    for( unsigned int i = 0 ; i < mVectComponent.size() ; ++i ){
        if( ! mVectComponent[ i ] )continue;
        std::cout << "i\n";
    }
}

/**
 * @brief ComponentManager::linkEngineToComponentManager Fonction liant Engine à ComponentManager par un pointeur.
 * @param ptrEngine Un pointeur vers Engine
 */
void ComponentManager::linkEngineToComponentManager( Engine *ptrEngine ){
    mptrEngine = ptrEngine;
}


