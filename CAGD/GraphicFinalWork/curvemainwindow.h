#ifndef CURVEMAINWINDOW_H
#define CURVEMAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <dialog.h>
#include <curve.h>
#include <info.h>
#include <QDebug>
#include <QMessageBox>
#include <basicfuncwindows.h>
#include<QFileDialog>
#include <QPixmap>

namespace Ui {
class CurveMainWindow;
class Curve;
}

class CurveMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CurveMainWindow(QWidget *parent = 0);
    ~CurveMainWindow();


private slots:
    void backToMain();
    void shutDown();
    void setInfo();
    void setBox(int);
    void screen();

signals:
    void info(Info *i);



private:
    Ui::CurveMainWindow *ui; //自身ui界面类
    QPixmap map; //用来截屏的一个map指针
};

#endif // CURVEMAINWINDOW_H
