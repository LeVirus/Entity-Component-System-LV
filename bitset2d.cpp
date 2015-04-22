#include "bitset2d.hpp"
#include <cassert>
#include <iostream>

/**
 * @brief BitSet2d::BitSet2d Constructeur de BitSet2d.
 */
BitSet2d::BitSet2d(): muiTabLength{ 20 }, muiTabHeight{ 20 } {
    mvectBool . resize( muiTabLength * muiTabHeight );
}

/**
 * @brief BitSet2d::BitSet2d Constructeur de BitSet2d avec la largeur et la longueur du tableau comme arguments.
 * @param uiLenght La largeur à attribuer au tableau.
 * @param uiHeight La longueur à attribuer au tableau.
 */
BitSet2d::BitSet2d( unsigned int uiLenght, unsigned int uiHeight ) : muiTabLength{ uiLenght }, muiTabHeight{ uiHeight } {
    mvectBool . resize( muiTabLength * muiTabHeight );
}

/**
 * @brief BitSet2d::resizeTab Fonction modifiant la taille du tableau de bit.
 * @param uiLenght La largeur à attribuer au tableau.
 * @param uiHeight La longueur à attribuer au tableau.
 */
void BitSet2d::resizeTab( unsigned int uiNewLenght, unsigned int uiNewHeight ){
    muiTabLength = uiNewLenght;
    muiTabHeight = uiNewHeight;
    mvectBool . resize( muiTabLength * muiTabHeight );
}

/**
 * @brief BitSet2d::getValAt Fonction renvoyant la valeur du bit à la case dont les coordonnées sont envoyées en paramètres.
 * Une assertion est effectuée si la case demandée est hors des bornes du tableau.
 * @param uiCaseX La coordonnée en X de la case demandée.
 * @param uiCaseY La coordonnée en Y de la case demandée.
 * @return La valeur de la case.
 */
bool BitSet2d::getValAt( unsigned int uiCaseX, unsigned int uiCaseY )const{
    assert( uiCaseX < muiTabLength && uiCaseY < muiTabHeight && "Valeur hors tab.\n" );
    return mvectBool[ muiTabLength * uiCaseY + uiCaseX ];
}

/**
 * @brief BitSet2d::getTab Fonction renvoyant une référence constante du tableau de bit.
 * @return Le tableau en référence constante.
 */
const std::vector< bool > &BitSet2d::getTab()const{
    return mvectBool;
}

/**
 * @brief BitSet2d::bAttributeTab Fonction d'attribution d'un nouveau tableau.
 * La valeur du tableau est modifié en fonction des paramètres X et Y
 * @param vectBool Le vector à copier.
 * @param uiLenght La longueur du tableau.
 * @param uiHeight La largeur du tableau.
 * @return true si le vector a bien été modifié, false sinon.
 */
bool BitSet2d::bAttributeTab( const std::vector< bool > & vectBool, unsigned int uiLenght, unsigned int uiHeight ){
    if( uiLenght * uiHeight != vectBool.size() )return false;

    resizeTab( uiLenght, uiHeight );

    for( unsigned int i = 0; i < vectBool . size() ;++i ){
        mvectBool[ i ] = vectBool[ i ];
    }
    return true;
}


/**
 * @brief BitSet2d::displayTab Fonction d'affichage du tableau.
 */
void BitSet2d::displayTab()const{
    std::cout << "AFFICHAGE TABLEAU BIT\n";
    for( unsigned int i = 0; i < mvectBool . size() ;++i ){
        std::cout << mvectBool[ i ];
        if( i != 0 && i % muiTabLength == 0 )std::cout << "\n";
    }
    std::cout << "FIN AFFICHAGE TABLEAU BIT\n";
}

/**
 * @brief BitSet2d::~BitSet2d Destructeur de BitSet2d.
 */
BitSet2d::~BitSet2d(){
}
