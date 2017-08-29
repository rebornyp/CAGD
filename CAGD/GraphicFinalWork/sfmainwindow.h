#ifndef SFMAINWINDOW_H
#define SFMAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <dialog.h>
#include <surfacepart.h>
#include <surfaceinfo.h>
#include <QPixmap>
#include <QFileDialog>


namespace Ui {
class SfMainWindow;
}

class SfMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SfMainWindow(QWidget *parent = 0);
    ~SfMainWindow();

private slots:
    void back(); //返回到主对话框的槽函数
    void selectInfo();     //收集信息的cao槽函数
    void screen(); //截屏的槽函数

signals:
    void info(surfaceInfo *i); //信号，用于提示内部绘制曲面的窗口绘图

private:
    Ui::SfMainWindow *ui; //主界面ui类
    QPixmap map; //保存截图的指针
};

#endif // SFMAINWINDOW_H

