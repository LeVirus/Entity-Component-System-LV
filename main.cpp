#include <iostream>
#include "engine.hpp"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Engine engine;
    engine.AddEntity();
    engine.AddEntity();
    engine.AddEntity();
    engine.displayVectEntity();
    engine.bRmEntity(1);
    engine.displayVectEntity();
    engine.RmAllEntity();
    engine.displayVectEntity();
    return 0;
}

