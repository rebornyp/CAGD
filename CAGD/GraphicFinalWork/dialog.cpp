#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setMaximumSize(626, 318);
    this->setMinimumSize(626, 318);
    connect(ui->curveButton, SIGNAL(clicked()), this, SLOT(drawCurve()));
    connect(ui->surfaceButton, SIGNAL(clicked()), this, SLOT(drawSurface()));
    this->setWindowTitle("计算机辅助几何设计大作业-SY1607307-易品");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::drawCurve() {
    CurveMainWindow *cm = new CurveMainWindow;
    cm->show();
    this->close();
}

void Dialog::drawSurface() {
//    SurfaceMainWindow *s = new SurfaceMainWindow;
    SfMainWindow *s = new SfMainWindow;
    s->show();
    this->close();
}
