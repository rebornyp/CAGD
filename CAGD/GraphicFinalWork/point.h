#ifndef POINT_H
#define POINT_H

//QPoint只提供x和y二维，所以我自己定义了一个三维的点类
class Point
{
public:
    Point();
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;

};

#endif // POINT_H
