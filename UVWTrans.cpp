#include <iostream>
#include "UVWStage.hpp"
#include "Calc.hpp"

using std::cout;
using std::endl;

int main()
{
        
    //  ここからUVWStageクラス
    cout << "ここからUVWStageクラス" << endl;
    UVWStage uvw;
    uvw.printAxis();

    cout << "UVWTrans(0.0,0.0,1.0) " << endl;
    uvw.UVWTrans(0.0,0.0,1.0);

    cout << "UVWTrans(1.0,1.0,1.0) " << endl;
    uvw.UVWTrans(1.0,1.0,1.0);

    //  ここからUVWtoXYT
    cout << "ここからUVWtoXYT" << endl;
    uvw.UVWtoXYT(-0.314, 0.314,-0.314);
    uvw.UVWtoXYT(-0.214, 0.314,-0.314);
    uvw.UVWtoXYT(-0.214, 0.414,-0.214);
    uvw.UVWtoXYT( 0.414,-0.214, 0.414);

    return 0;
}