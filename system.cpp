#include "system.hpp"
#include "constantes.hpp"
#include "entity.hpp"
#include "engine.hpp"
#include <bitset>

/**
 * @brief System::System Constructeur de la classe System
 */
System::System(){
}

/**
 * @brief SystemManager::linkEngine fonction envoyant un pointeur d'Engine à SystemManager.
 * @param ptrEngine Un pointeur d'Engine
 */
void System::linkSystemManager( SystemManager* ptrSystemManager ){
    mptrSystemManager = ptrSystemManager;
}

/**
 * @brief System::refreshNode Fonction de synchronisation des entités à modifier par le système.
 * La fonction va rechercher les numéros d'entités à modifier, et les stocker dans mVectNumEntity.
 */
void System::refreshEntity(){
    bool granted;
    unsigned int count = 0;
    const std::vector< Entity > & vectEntity = mptrSystemManager -> getptrEngine() -> getVectEntity();

    for( unsigned int i = 0 ; i < vectEntity . size() ; ++i ){
        granted = true;
        //récupération du bitset de l'entité
        const std::bitset< NUMBR_COMPONENT > & bitSetEntity = vectEntity[ i ] . getEntityBitSet();
        for( unsigned int j = 0 ; j < bitSetEntity.size() ; ++j ){
            //si le composant nécessaire au système n'est pas présent dans l'entité
            if( mBitSetComponentSystem[ j ] == true &&  bitSetEntity[ j ] == false ){
                granted = false;
                break;
            }
        }
        if( granted ){
            if( count >=  mVectNumEntity.size() ){
               mVectNumEntity.resize( count + 1 );
            }
            mVectNumEntity[ count ] = i;
            count++;
            std::cout << "num Entité System::" << i << "\n";
        }
    }
    if( mVectNumEntity.size() != count )mVectNumEntity.resize( count );
}

/**
 * @brief System::displaySystem Fonction d'affichage des caractéristiques du système.
 * Affichage des composants nécessaire au système et descriptif de la fonction du système.
 */
void System::displaySystem()const{
    std::cout << "Affichage numéro des entités a traiter par le systeme \n" ;
    for( unsigned int i = 0 ; i < mVectNumEntity.size() ; ++i ){
        std::cout << mVectNumEntity[ i ] ;
    }
    std::cout << "\n";
}

/**
 * @brief System::addComponentSystem Fonction d'ajout d'un composant au système.
 * @param uiTypeComponent le numéro du composant à intégrer dans le système.
 * @return false si le composant est déja présent ou si uiTypeComponent ne correspond à aucun composants
 * true sinon.
 */
bool System::bAddComponentToSystem( unsigned int uiTypeComponent ){
    bool bReturn = false;
    if( ! bComponentAlreadyExist( uiTypeComponent ) ){//A MODIFIER
        bReturn = true;
        mBitSetComponentSystem[ uiTypeComponent ] = true;

    }
    return bReturn;
}

/**
 * @brief System::execSystem Fonction de base d'execution d'un systeme. Cette fonction appelle System::refreshEntity.
 */
void System::execSystem(){
    refreshEntity();
    //displaySystem();
}

/**
 * @brief System::bAlreadyExist Fonction vérifiant si le numéro de composant(paramètre)
 * est déja présent dans le tableau de stockage des composants(bitset).
 * @param uiTypeComponent Le numéro du composant à vérifier.
 * @return true si le composant est présent, false sinon.
 */
bool System::bComponentAlreadyExist( unsigned int uiTypeComponent ){
    return mBitSetComponentSystem[ uiTypeComponent ];
}

/**
 * @brief System::stairwayToComponentManager Fonction d'envoie d'une référence vers le gestionnaire de composant.
 * (Cette fonction a été faite pour une question de lisibilité du code).
 * @return Une référence vers le gestionnaire de composant( mComponentManager ).
 */
ComponentManager & System::stairwayToComponentManager(){
   return mptrSystemManager -> getptrEngine() -> getComponentManager();
        //searchComponentByType < DisplayComponent > ( 1, DISPLAY_COMPONENT );
}
