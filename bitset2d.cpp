#include "bitset2d.hpp"
#include <cassert>
#include <iostream>

BitSet2d::BitSet2d(): muiTabLength{ 20 }, muiTabHeight{ 20 } {
    mvectBool . resize( muiTabLength * muiTabHeight );
}

BitSet2d::BitSet2d( unsigned int uiLenght, unsigned int uiHeight ) : muiTabLength{ uiLenght }, muiTabHeight{ uiHeight } {
    mvectBool . resize( muiTabLength * muiTabHeight );
}

void BitSet2d::resizeTab( unsigned int uiNewLenght, unsigned int uiNewHeight ){
    muiTabLength = uiLenght;
    muiTabHeight = uiNewHeight;
    mvectBool . resize( muiTabLength * muiTabHeight );
}

bool BitSet2d::getValAt( unsigned int uiCaseX, unsigned int uiCaseY )const{
    assert( uiCaseX < muiTabLength && uiCaseY < muiTabHeight && "Valeur hors tab.\n" );
    return mvectBool[ muiTabLength * uiCaseY + uiCaseX ];
}

const std::vector< bool > &BitSet2d::getTab()const{
    return mvectBool
}

void BitSet2d::displayTab()const{
    for( unsigned int i = 0; i < mvectBool . size() ;++i ){
        std::cout << mvectBool[ i ];
        if( i != 0 && i % muiTabLength == 0 )std::cout << "\n";
    }
}

BitSet2d::~BitSet2d(){

}

