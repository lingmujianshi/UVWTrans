/**
 * @file Calc.hpp
 * @brief UVWステージの計算の補助関数
 * @author tsuzuki
 * @date 2020.08.15
 */

#ifndef __INCLUDED_CALC_HPP
#define __INCLUDED_CALC_HPP

#include <iostream>
#include <cmath>

/**
 * @fn
 * 度からラジアンを求める
 * @param (deg) 度
 * @return ラジアン
*/
static double rad(double deg)
{
    return deg * M_PI / 180.0;
}

/**
 * @fn
 * ラジアンから度を求める
 * @param ラジアン
 * @return 度
*/
static double deg(double rad)
{
    return rad * 180.0 / M_PI;
}

#endif //__INCLUDED_CALC_HPP