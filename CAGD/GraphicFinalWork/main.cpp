#include "dialog.h"
#include <QApplication>

//main主函数，这里开启了一个QApplication主线程

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog w; //定义一个对话框并显示
    w.show();

    return a.exec();
}
