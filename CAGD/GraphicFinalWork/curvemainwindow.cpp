#include "curvemainwindow.h"
#include "ui_curvemainwindow.h"

//显示曲线绘制的主窗口类，从QMainWindows类继承，

CurveMainWindow::CurveMainWindow(QWidget *parent) : //构造函数
    QMainWindow(parent),
    ui(new Ui::CurveMainWindow)
{
    ui->setupUi(this);
    setWindowTitle("曲线绘制窗口"); //设置窗口标题
    this->setMaximumSize(1200, 800); //设置窗口大小固定
    this->setMinimumSize(1200, 800);
    setCentralWidget(ui->mainWidget);

    QDesktopWidget *pDesk = QApplication::desktop();
    move((pDesk->width() - this->width()) / 2, 0); //让窗口居中

    connect(ui->cutBtn, SIGNAL(clicked()), this, SLOT(screen()));


    QVBoxLayout *layout1 = new QVBoxLayout;
    QHBoxLayout *layout2 = new QHBoxLayout;
    layout1->addWidget(ui->upWidget); //加入显示绘制曲线的窗口
    layout1->addWidget(ui->downWidget); //加入显示基函数的窗口
    layout1->setStretchFactor(ui->upWidget, 4);
    layout1->setStretchFactor(ui->downWidget, 1);//设置上下比例

    ui->curveWidget->setLayout(layout1);
    layout2->addWidget(ui->curveWidget);
    layout2->addWidget(ui->buttonWidget);
    layout2->setStretchFactor(ui->curveWidget, 5);
    layout2->setStretchFactor(ui->buttonWidget, 1);
    ui->mainWidget->setLayout(layout2);

    Curve *curveWindow = new Curve; //新创建一个显示曲线窗口的指针对象
    QHBoxLayout *layout3 = new QHBoxLayout;
    layout3->addWidget(curveWindow);
    ui->upWidget->setLayout(layout3);

    connect(curveWindow, SIGNAL(rightBtnClicked()), this, SLOT(setInfo())); //曲线绘制窗口邮件点击触发主窗口获取当前信息的槽函数

    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(backToMain())); //返回槽函数
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(shutDown())); //退出槽函数
    connect(this, SIGNAL(info(Info*)), curveWindow, SLOT(getInfo(Info*))); //传递信息的槽函数
    connect(ui->drawBtn, SIGNAL(clicked()), this, SLOT(setInfo())); //获取信息的槽函数
    connect(ui->cb1, SIGNAL(currentIndexChanged(int)), this, SLOT(setBox(int))); //当前comobox栏目更改时候的槽函数
    connect(ui->clcBtn, SIGNAL(clicked()), curveWindow, SLOT(clearAll())); //清屏的槽函数
    connect(ui->editBtn, SIGNAL(clicked(bool)), curveWindow, SLOT(editSlot())); //编辑的槽函数

    basicFuncWindows *bw = new basicFuncWindows; //创建基函数显示窗口并载入
    QHBoxLayout *layout4 = new QHBoxLayout;
    layout4->addWidget(bw);
    ui->downWidget->setLayout(layout4);

    connect(curveWindow, SIGNAL(messagesToBasic(Info*)), bw, SLOT(getInfo(Info*)));
    connect(ui->clcBtn, SIGNAL(clicked()), bw, SLOT(clc()));
    connect(ui->cutBtn, SIGNAL(clicked(bool)), curveWindow, SLOT(up()));
}

CurveMainWindow::~CurveMainWindow()
{
    delete ui;
}

//截屏方法
void CurveMainWindow::screen() {
    map = QPixmap::grabWindow(QApplication::desktop()->winId());
    QString FileName = QFileDialog::getSaveFileName(this, "Save File", "/home/jana/screenShot.png",
                                                    tr("Images (*.png *.xpm *.jpg)"));
    map.save(FileName);
}

//返回主窗口的方法实现
void CurveMainWindow::backToMain() {
    Dialog *d = new Dialog;
    d->show();
    this->close();
}

//关闭窗口的方法实现
void CurveMainWindow::shutDown() {
    this->close();
}

//获取当前主窗口的各个信息栏的方法实现
void CurveMainWindow::setInfo()
{
    Info *i = new Info; //由于有多个变量，为了减少槽函数的数目，这里选用第三方类来传递内容
    int readyEmit = 1;
    i->cb = ui->cb1->currentIndex();
    if(ui->le1->text().isEmpty() && i->cb == 0) {
        readyEmit = 0;
        QMessageBox message(QMessageBox::Warning,"警告","请填写曲线次数！",QMessageBox::Yes,NULL);
        message.exec();
    }
    i->le = ui->le1->text().toInt(); //将字符串类型转化为整型
    i->type = ui->cb2->currentIndex();
    if(readyEmit == 1)
        emit info(i);
}

//只要当前选中是贝齐尔曲线类型，那么就主动让后面B样条的类型选项栏目失效
void CurveMainWindow::setBox(int) {
    if(ui->cb1->currentIndex() == 1) {
        ui->cb2->setDisabled(true);
        ui->le1->setDisabled(true);
    } else {
        ui->cb2->setDisabled(false);
        ui->le1->setDisabled(false);
    }
}
