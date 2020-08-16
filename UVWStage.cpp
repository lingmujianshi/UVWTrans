/**
 * @file UVWStage.cbpp
 * @brief UVWステージの計算
 * @author tsuzuki
 * @date 2020.08.15
 */

#include "UVWStage.hpp"

UVWStage::UVWStage():
    U(ux, uy, ud),
    V(vx, vy, vd),
    W(wx, wy, wd)
    {    
    }

void UVWStage::UVWTrans(double x, double y, double tdeg)
{
    double t = rad(tdeg);
    U.pos = U.movT(x, y, t, 0.0);
    V.pos = V.movT(x, y, t, 0.0);
    W.pos = W.movT(x, y, t, 0.0);

    cout << "X:" << x <<   ", Y:" << y <<  ", T:" << tdeg << ", ";
    printPos(); 
}

void UVWStage::printPos()
{
    cout << "U:" << U.get_pos() << " ,V:" << V.get_pos() << " ,W:" <<W.get_pos() << endl;
}

void UVWStage::printAxis()
{
    cout << "U軸 R: " << U.get_R() << " ,tr: " << deg(U.get_tR()) << "deg dir: " << U.get_dir() << endl;
    cout << "V軸 R: " << V.get_R() << " ,tr: " << deg(V.get_tR()) << "deg dir: " << V.get_dir() << endl;
    cout << "W軸 R: " << W.get_R() << " ,tr: " << deg(W.get_tR()) << "deg dir: " << W.get_dir() << endl;
}

void UVWStage::UVWtoXYT(double upos, double vpos, double wpos)
{
    double bX, bY, bT, t;
    bX = (vpos + wpos) / 2.0;
    t = vpos - bX;
    bY = t + upos;

    bT = deg(atan(t/180.0));
    cout << "U: " << upos << ", V:" << vpos << ", W:" << wpos << " --> X: " << bX << ", Y:" << bY << ", T:" << bT << ", t:" << t << endl;
}