/**
 * @file CrossRoller.hpp
 * @brief CrossRollerクラス
 * @author tsuzuki
 * @date 2020.08.15
 */

#ifndef __INCLUDED_CROSSROLLER_HPP
#define __INCLUDED_CROSSROLLER_HPP

#include <iostream>
#include <cmath>
#include <string>
using std::cout;
using std::endl;



class CrossRoller
{
public:
     /**
     * @enum Direction
     * UVWステージクロスローラに取り付いているモータが＋に増えたときの進行方向
     */
    enum Direction
    {
        RIGHT,  // 右方向
        LEFT,   // 左方向
        UP,     // 上方向
        DOWN    // 下方向
    };

private:
    double R;   // 各軸に連結されたクロスローラリング中心を通る仮想円の半径[mm]
    double tR;  // クロスリング中心の角度
    Direction dir;  //! モータの移動方向

public:
    double pos; //

public:

CrossRoller(double posX,double posY,Direction d);

/**
 * @fn
 * クロスローラの位置と方向を設定する
 * @param posX ステージセンターからのクロスローラ位置 X方向
 * @param posY ステージセンターからのクロスローラ位置 Y方向
 * @param d モータの移動方向
*/
void setCrossRoller(double posX,double posY,Direction d);

// getter
double get_R();
double get_tR();
double get_pos();
Direction get_Direct();
std::string get_dir();

//! 軸が横方向ならTrue,縦方向ならfalse
bool isH();

/**
 * @fn
 * UVWステージクロスローラ位置を算出
 * @param double t     XYθ入力値
 * @param double t0    計算動作前の角度
 * @return 変換後のクロスローラ位置
*/
double movT(double t, double t0 );

/**
 * @fn
 * UVWステージクロスローラ位置を算出
 * @param double x,y,t     XYθ入力値
 * @param double t0    計算動作前の角度
 * @return 変換後のクロスローラ位置
*/
double movT(double x, double y, double t, double t0 );

};

#endif //__INCLUDED_CROSSROLLER_HPP