#ifndef SURFACEINFO_H
#define SURFACEINFO_H

//曲面面板信息和绘制曲线时候不一样，所以重新定义了这个第三方类。
class surfaceInfo
{
public:
    surfaceInfo();
    int uk, vk, uIndex, vIndex; //分别是u,v方向的次数，以及u.v方向的曲线类型
};

#endif // SURFACEINFO_H
