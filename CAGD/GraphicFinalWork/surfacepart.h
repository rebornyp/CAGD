#ifndef SURFACEPART_H
#define SURFACEPART_H

#include <QWidget>
#include <qgl.h>
#include <GL/glut.h>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <qDebug>
#include <QMouseEvent>
#include <QPoint>
#include <QWheelEvent>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <point.h>
#include <vector>
#include <surfaceinfo.h>
#include <QFileDialog>

namespace Ui {
class SurfacePart;
}

class SurfacePart : public QGLWidget
{
    Q_OBJECT

public:
    explicit SurfacePart(QGLWidget *parent = 0);
    ~SurfacePart();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *e);
    void drawPoint(double x, double y, double z); //绘制点的方法
    Point countPoint(double u, double v); //计算曲面插值点的方法
    double N(double u, int i, int k, double *arr); //求算曲面的基函数方法1
    double Basisfun(int i, int k, double *knot, double u); //求算曲面的基函数方法2
    void deal(double *u, int a, int b); //处理求算节点矢量方法

private slots:
    void clcFunc(); //清屏
    void draw(surfaceInfo *i); //绘图槽函数
    void getInfo(); //获取信息槽函数
    void applyRead(); //获得信息后处理槽函数
    void clc(); //清屏槽函数

private:
    Ui::SurfacePart *ui; // 内部的自身的ui类
    GLfloat tra, xRot, yRot, zRot; //控制缩放等的多个数值
    double trax, tray; //控制视景体平移的两个参量
    QPoint oldPoint; //当前鼠标点击的QPoint类型值
    bool isInputting;
    QVector<Point> pointVector; //存放点的容器
    void drawPoint(Point a); //绘制点的函数
    void drawLines(Point a, Point b); //绘制直线函数
    Point p[5][5]; //全局变量存放控制顶点
    double *ut, *vt; //两个存放double类型的数组的指针
    surfaceInfo *info; //存放信息的指针
    bool isDraw, isRead; //用于判断绘制曲面的两个布尔值

};

#endif // SURFACEPART_H
