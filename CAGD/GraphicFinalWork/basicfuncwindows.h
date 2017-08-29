#ifndef BASICFUNCWINDOWS_H
#define BASICFUNCWINDOWS_H

#include <QWidget>
#include <qgl.h>
#include <GL/glut.h>
#include <QPoint>
#include <info.h>
#include <QtMath>
#include <QDebug>
#include <QFont>

namespace Ui {
class basicFuncWindows;
}

class basicFuncWindows : public QGLWidget
{
    Q_OBJECT

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void drawPoint(QPoint a);
    void drawLine(QPoint a, QPoint b, double h);
    void drawPoint(double x, double y);
    double getDistance(QPoint a, QPoint b);
    void drawLine(double ax, double ay, double bx, double by, double h);

public:
    explicit basicFuncWindows(QGLWidget *parent = 0);
    ~basicFuncWindows();

private slots:
    void getInfo(Info *a);
    void clc();

private:
    Ui::basicFuncWindows *ui;
    double GetBaseFunVal(double u, int i, int k); //获取某一个u值对应基函数数值的方法
    bool draw;
    Info *info;
    double *t;
};

#endif // BASICFUNCWINDOWS_H
