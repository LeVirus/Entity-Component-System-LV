#ifndef BITSET2D_H
#define BITSET2D_H

#include <vector>


namespace ecs
{

/**
 * @brief La classe BitSet2d représente un tableau à 2 dimensions de bit, dans un bitset unidimentionnel.
 * Le tableau est
 */
class BitSet2d{
private:
    unsigned int muiTabLength, muiTabHeight;
    std::vector< bool > mvectBool;
public:
    BitSet2d();
    BitSet2d( unsigned int uiLenght, unsigned int uiHeight );
    void resizeTab( unsigned int uiNewLenght, unsigned int uiNewHeight );

    bool getValAt( unsigned int uiCaseX, unsigned int uiCaseY )const;

    const std::vector< bool > &getTab()const;

    bool bAttributeTab( const std::vector< bool > & vectBool, unsigned int uiLenght, unsigned int uiHeight );

    void attributeValToCase( unsigned int uiX, unsigned int uiY, bool bNewVal );
    unsigned int getLength()const{ return muiTabLength; }
    unsigned int getHeight()const{ return muiTabHeight; }
    unsigned int getTotalLength()const{ return muiTabLength * muiTabHeight; }

    void displayTab()const;

    ~BitSet2d();
};

}//fin namespace
#endif // BITSET2D_H
