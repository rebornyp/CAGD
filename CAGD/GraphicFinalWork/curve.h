#ifndef CURVE_H
#define CURVE_H

#include <qgl.h>
#include <GL/glut.h>
#include <QWidget>
#include <QKeyEvent>
#include <qDebug>
#include <QMouseEvent>
#include <QPoint>
#include <QWheelEvent>
#include <QVector>
#include <QtMath>
#include <curvemainwindow.h>
#include <info.h>
#include <QList>
#include <QMap>
#include <QFont>

namespace Ui {
class Curve;
}

class Curve : public QGLWidget
{
    Q_OBJECT

public:
    explicit Curve(QGLWidget *parent = 0);
    ~Curve();

private slots:
    void getInfo(Info *i); //获取信息的槽函数
    void clearAll(); //清屏槽函数
    void editSlot(); //编辑状态的槽函数
    void up(); //更新编辑状态的槽函数

signals:
    void rightBtnClicked(); //邮件绘图的槽函数
    void messagesToBasic(Info *i); //将曲线信息发送到绘制基函数的槽函数

protected:
    void initializeGL(); //从QGLWidget类继承的实现了openGL标准的初始化函数
    void resizeGL(int w, int h); //用于窗口变化后再度自适应的函数
    void paintGL(); //绘图主函数
    void keyPressEvent(QKeyEvent *event); //用于键盘单击事件的函数
    void mousePressEvent(QMouseEvent *event); //用于鼠标单击事件的函数
    void mouseMoveEvent(QMouseEvent *event); //用于鼠标移动的事件
    void mouseReleaseEvent(QMouseEvent *event); //用于鼠标释放的事件
    void wheelEvent(QWheelEvent *e); //用于滚轮滚动的事件
    void drawLine(QPoint a, QPoint b, double h); //绘制直线的事件
    void drawPoint(QPoint a); //绘制点的方法
    void drawPoint(double x, double y); //绘制平面点的重载方法
    void drawPoint(double x, double y, double z); //绘制三维点的重载方法
    QPoint drawBezier(double t, double *a, double *b); //绘制贝齐尔曲线的方法
    QPoint drawBcurves(double u, int a, double *t); //绘制B样条的方法
    double getDistance(QPoint a, QPoint b); //计算两个点的距离的方法

private:
    Ui::Curve *ui; //自身ui界面类
    GLfloat tra, xRot, yRot, zRot; //用于旋转和放大缩小整个视景体的几个参数
    QPoint oldPoint; //鼠标单击用来记录当前点的一个全局QPoint对象
    QVector<QPoint> pointVector; // 指定类型的容器
    bool isInputting, finishInputting, editBool; //判断是否仍然处于输入状态，是否输入完毕的，是否处于编辑状态的布尔数值
    Info *info; //存储信息的三方类全局指针
    int flag; //判断的一个全局整形变量
    QList<int> list;
    double tt; //用于迭代的步长变量
    int inWhich(double tt, double *t, int n); //判断是否处于那一个节点矢量之间的返回为整形的方法
};

#endif // CURVE_H
