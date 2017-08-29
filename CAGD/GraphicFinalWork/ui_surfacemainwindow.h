/********************************************************************************
** Form generated from reading UI file 'surfacemainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACEMAINWINDOW_H
#define UI_SURFACEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SurfaceMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *mainWidget;
    QWidget *leftWidget;
    QWidget *rightWidget;
    QLabel *label;
    QPushButton *readBtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *backBtn;
    QPushButton *exitBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SurfaceMainWindow)
    {
        if (SurfaceMainWindow->objectName().isEmpty())
            SurfaceMainWindow->setObjectName(QStringLiteral("SurfaceMainWindow"));
        SurfaceMainWindow->resize(1200, 800);
        centralwidget = new QWidget(SurfaceMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        mainWidget = new QWidget(centralwidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setGeometry(QRect(30, 30, 1171, 761));
        leftWidget = new QWidget(mainWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setGeometry(QRect(70, 10, 901, 701));
        leftWidget->setStyleSheet(QStringLiteral(""));
        rightWidget = new QWidget(mainWidget);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        rightWidget->setGeometry(QRect(970, 0, 200, 800));
        rightWidget->setStyleSheet(QStringLiteral(""));
        label = new QLabel(rightWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 70, 71, 31));
        readBtn = new QPushButton(rightWidget);
        readBtn->setObjectName(QStringLiteral("readBtn"));
        readBtn->setGeometry(QRect(40, 310, 121, 31));
        widget = new QWidget(rightWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 680, 161, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        backBtn = new QPushButton(widget);
        backBtn->setObjectName(QStringLiteral("backBtn"));

        horizontalLayout->addWidget(backBtn);

        exitBtn = new QPushButton(widget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        horizontalLayout->addWidget(exitBtn);

        SurfaceMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SurfaceMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 23));
        SurfaceMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SurfaceMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SurfaceMainWindow->setStatusBar(statusbar);

        retranslateUi(SurfaceMainWindow);

        QMetaObject::connectSlotsByName(SurfaceMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SurfaceMainWindow)
    {
        SurfaceMainWindow->setWindowTitle(QApplication::translate("SurfaceMainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("SurfaceMainWindow", "\346\233\262\347\272\277\347\273\230\345\210\266\346\250\241\345\235\227", Q_NULLPTR));
        readBtn->setText(QApplication::translate("SurfaceMainWindow", "\350\257\273\345\205\245", Q_NULLPTR));
        backBtn->setText(QApplication::translate("SurfaceMainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("SurfaceMainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SurfaceMainWindow: public Ui_SurfaceMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACEMAINWINDOW_H
