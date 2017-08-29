#include "sfmainwindow.h"
#include "ui_sfmainwindow.h"

SfMainWindow::SfMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SfMainWindow)
{
    ui->setupUi(this);
    setWindowTitle("曲面绘制窗口"); //设置标题栏目大小
    this->setMaximumSize(1200, 800); //实现窗口固定大小
    this->setMinimumSize(1200, 800);

    QDesktopWidget *pDesk = QApplication::desktop();
    move((pDesk->width() - this->width()) / 2, 0);

    QVBoxLayout *layout3 = new QVBoxLayout;
    layout3->addWidget(ui->MF);
    QHBoxLayout *layout4 = new QHBoxLayout;
    layout4->addLayout(layout3);
    layout4->addWidget(ui->TF);
    layout4->setStretchFactor(layout3, 4);
    layout4->setStretchFactor(ui->TF, 1);
    ui->centralwidget->setLayout(layout4);

    SurfacePart *sp = new SurfacePart; //将绘制曲面的类新创建一个对象
    QHBoxLayout *layout5 = new QHBoxLayout; //实现其于主窗口的添加
    layout5->addWidget(sp);
    ui->MF->setLayout(layout5);

    connect(ui->backBtn, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->exitBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->readBtn, SIGNAL(clicked(bool)), sp, SLOT(applyRead()));
    connect(ui->drawBtn, SIGNAL(clicked()), this, SLOT(selectInfo()));
    connect(this, SIGNAL(info(surfaceInfo*)), sp, SLOT(draw(surfaceInfo*)));
    connect(ui->clcBtn, SIGNAL(clicked()), sp, SLOT(clc()));
    connect(ui->picBtn, SIGNAL(clicked()), this, SLOT(screen()));
}

SfMainWindow::~SfMainWindow()
{
    delete ui;
}

//返回到主窗口函数
void SfMainWindow::back() {
    Dialog *d = new Dialog;
    d->show();
    this->close();
}

//截屏的函数
void SfMainWindow::screen() {
    map = QPixmap::grabWindow(QApplication::desktop()->winId());
    QString FileName = QFileDialog::getSaveFileName(this, "Save File", "/home/jana/screenShot.png",
                                                    tr("Images (*.png *.xpm *.jpg)"));
    map.save(FileName);
}

//获取当前面板里的信息函数
void SfMainWindow::selectInfo()
{
    surfaceInfo *sf = new surfaceInfo;
    int readyEmit = 1;
    sf->uIndex = ui->cb1->currentIndex();
    sf->vIndex = ui->cb2->currentIndex();
    sf->uk = ui->le1->text().toInt();
    sf->vk = ui->le2->text().toInt();
    if(ui->le1->text().isEmpty() | ui->le2->text().isEmpty()) {
        readyEmit = 0;
        QMessageBox message(QMessageBox::Warning,"警告","请填写曲线次数！",QMessageBox::Yes,NULL);
        message.exec();
        return;
    }
    int k1 = sf->uk;
    int k2 = sf->vk;
    if((k1<=0) | (k1>=5) | (k2<=0) | (k2>=5)) {
        readyEmit = 0;
        QMessageBox message(QMessageBox::Warning,"警告","请填写适当的曲线次数！",QMessageBox::Yes,NULL);
        message.exec();
        return;
    }
    emit info(sf);
}
