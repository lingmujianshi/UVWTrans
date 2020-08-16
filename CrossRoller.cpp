/**
 * @file CrossRoller.pp
 * @brief CrossRollerクラス
 * @author tsuzuki
 * @date 2020.08.15
 */

#include "CrossRoller.hpp"

CrossRoller::CrossRoller(double posX,double posY,Direction d)
{
    setCrossRoller(posX,posY,d);
}

void CrossRoller::setCrossRoller(double posX,double posY,Direction d)
{
    R = sqrt(pow(posX,2)+pow(posY,2));
    tR = atan2(posY,posX);
    dir = d;
}

double CrossRoller::get_R(){return R;}
double CrossRoller::get_tR(){return tR;}
double CrossRoller::get_pos(){return pos;};
CrossRoller::Direction CrossRoller::get_Direct(){return dir;}
std::string CrossRoller::get_dir()
{
    std::string d;
    switch (dir)
    {
    case Direction::UP: d = "↑"; break;
    case Direction::DOWN: d = "↓"; break;
    case Direction::LEFT: d = "←"; break;
    case Direction::RIGHT: d = "→"; break;
    default:
        break;
    }
    return d;
}

// 軸が横方向ならTrue,縦方向ならfalse
bool CrossRoller::isH(){return dir == Direction::LEFT or dir == Direction::RIGHT;}

double CrossRoller::movT(double t, double t0 )
{
    double m;
    if (isH()) 
        m = R * cos(t + tR + t0 ) - R * cos(tR + t0 );
    else
        m = R * sin(t + tR + t0 ) - R * sin(tR + t0 );
    return m;
}


double CrossRoller::movT(double x, double y, double t, double t0 )
{
    double m=0.0;
    m = movT(t,t0);
    
    if (isH())
        m = m + x;
    else
        m = m + y;

    return m;
}