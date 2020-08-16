/**
 * @file UVWStage.hpp
 * @brief UVWステージの計算
 * @author tsuzuki
 * @date 2020.08.15
 */

#ifndef __INCLUDED_UVWSTAGE_HPP
#define __INCLUDED_UVWSTAGE_HPP

#include <iostream>
#include <cmath>
#include <string>
#include "CrossRoller.hpp"
#include "Calc.hpp"

class UVWStage
{
private:
    typedef CrossRoller::Direction DIR;
    double ux = -180.0;      // U軸 クロスローラステージセンターからの位置 X方向
    double uy =  180.0;      // U軸 クロスローラステージセンターからの位置 Y方向
    DIR ud    = DIR::UP;     // U軸 クロスローラについているモータが＋に動いたときの方向
    double vx =  180.0;      // V軸 クロスローラステージセンターからの位置 X方向
    double vy =  180.0;      // V軸 クロスローラステージセンターからの位置 Y方向
    DIR vd    = DIR::RIGHT;  // V軸 クロスローラについているモータが＋に動いたときの方向
    double wx = -180.0;      // W軸 クロスローラステージセンターからの位置 X方向
    double wy = -180.0;      // W軸 クロスローラステージセンターからの位置 Y方向
    DIR wd    = DIR::RIGHT;  // W軸 クロスローラについているモータが＋に動いたときの方向

    CrossRoller U; // U軸
    CrossRoller V; // V軸
    CrossRoller W; // W軸

public:
    UVWStage();

    /**
     * @fn
     * XYθ座標をUVWへ変換する。
     * @param x X位置
     * @param y Y位置
     * @param t θ位置
     * @return なし
    */
    void UVWTrans(double x, double y, double t);

    /**
     * 現在のポジションを標準出力
    */
    void printPos();
    
    /**
     * 現在のモータ位置を標準出力
    */
    void printAxis();
    
    /**
     * @fn
     * UVWモータの現在位置からXYθ座標へ変換する。
     * @param upos　U軸現在位置
     * @param vpos　V軸現在位置
     * @param wpos　W軸現在位置
     * @return なし
    */
    void UVWtoXYT(double upos, double vpos, double wpos);
};
#endif  //__INCLUDED_UVWSTAGE_HPP