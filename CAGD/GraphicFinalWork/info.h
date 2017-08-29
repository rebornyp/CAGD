#ifndef INFO_H
#define INFO_H

#include <QVector>

//用来存放信息的一个三方类，是自己定义的，用来保存外部主界面的多种信息，比如曲线类型及参数等。

class Info
{
public:
    Info();
    int cb, le, type, num;
    QVector<QPoint> *qvp;

};

#endif // INFO_H
