/********************************************************************************
** Form generated from reading UI file 'curvemainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVEMAINWINDOW_H
#define UI_CURVEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurveMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *mainWidget;
    QWidget *buttonWidget;
    QPushButton *drawBtn;
    QPushButton *clcBtn;
    QPushButton *cutBtn;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *le1;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cb1;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QComboBox *cb2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *backButton;
    QPushButton *exitButton;
    QLabel *label_4;
    QPushButton *editBtn;
    QWidget *curveWidget;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_2;
    QWidget *upWidget;
    QWidget *downWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CurveMainWindow)
    {
        if (CurveMainWindow->objectName().isEmpty())
            CurveMainWindow->setObjectName(QStringLiteral("CurveMainWindow"));
        CurveMainWindow->resize(1200, 800);
        centralwidget = new QWidget(CurveMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        mainWidget = new QWidget(centralwidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setGeometry(QRect(10, 0, 1181, 751));
        mainWidget->setStyleSheet(QStringLiteral(""));
        buttonWidget = new QWidget(mainWidget);
        buttonWidget->setObjectName(QStringLiteral("buttonWidget"));
        buttonWidget->setGeometry(QRect(980, 0, 200, 751));
        buttonWidget->setStyleSheet(QStringLiteral(""));
        drawBtn = new QPushButton(buttonWidget);
        drawBtn->setObjectName(QStringLiteral("drawBtn"));
        drawBtn->setGeometry(QRect(10, 330, 81, 41));
        drawBtn->setStyleSheet(QStringLiteral("font: 12pt \"Adobe Arabic\";"));
        clcBtn = new QPushButton(buttonWidget);
        clcBtn->setObjectName(QStringLiteral("clcBtn"));
        clcBtn->setGeometry(QRect(110, 330, 81, 41));
        clcBtn->setStyleSheet(QStringLiteral("font: 12pt \"Adobe Arabic\";"));
        cutBtn = new QPushButton(buttonWidget);
        cutBtn->setObjectName(QStringLiteral("cutBtn"));
        cutBtn->setGeometry(QRect(10, 400, 81, 41));
        cutBtn->setStyleSheet(QStringLiteral("font: 12pt \"Adobe Arabic\";"));
        layoutWidget = new QWidget(buttonWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 130, 161, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        le1 = new QLineEdit(layoutWidget);
        le1->setObjectName(QStringLiteral("le1"));

        horizontalLayout_2->addWidget(le1);

        layoutWidget1 = new QWidget(buttonWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 80, 161, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        cb1 = new QComboBox(layoutWidget1);
        cb1->setObjectName(QStringLiteral("cb1"));

        horizontalLayout->addWidget(cb1);

        layoutWidget2 = new QWidget(buttonWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 210, 202, 40));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        cb2 = new QComboBox(layoutWidget2);
        cb2->setObjectName(QStringLiteral("cb2"));

        verticalLayout->addWidget(cb2);

        layoutWidget3 = new QWidget(buttonWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 710, 158, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        backButton = new QPushButton(layoutWidget3);
        backButton->setObjectName(QStringLiteral("backButton"));

        horizontalLayout_3->addWidget(backButton);

        exitButton = new QPushButton(layoutWidget3);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout_3->addWidget(exitButton);

        label_4 = new QLabel(buttonWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 160, 161, 16));
        editBtn = new QPushButton(buttonWidget);
        editBtn->setObjectName(QStringLiteral("editBtn"));
        editBtn->setGeometry(QRect(110, 400, 81, 41));
        editBtn->setStyleSheet(QStringLiteral("font: 12pt \"Adobe Arabic\";"));
        curveWidget = new QWidget(mainWidget);
        curveWidget->setObjectName(QStringLiteral("curveWidget"));
        curveWidget->setGeometry(QRect(-30, 0, 1011, 751));
        curveWidget->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 100);"));
        layoutWidget4 = new QWidget(curveWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(50, 300, 751, 391));
        verticalLayout_2 = new QVBoxLayout(layoutWidget4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        upWidget = new QWidget(layoutWidget4);
        upWidget->setObjectName(QStringLiteral("upWidget"));
        upWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(upWidget);

        downWidget = new QWidget(layoutWidget4);
        downWidget->setObjectName(QStringLiteral("downWidget"));
        downWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(downWidget);

        CurveMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CurveMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        CurveMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CurveMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CurveMainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(CurveMainWindow);

        QMetaObject::connectSlotsByName(CurveMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CurveMainWindow)
    {
        CurveMainWindow->setWindowTitle(QApplication::translate("CurveMainWindow", "MainWindow", Q_NULLPTR));
        drawBtn->setText(QApplication::translate("CurveMainWindow", "\347\273\230\345\210\266", Q_NULLPTR));
        clcBtn->setText(QApplication::translate("CurveMainWindow", "\346\270\205\345\261\217", Q_NULLPTR));
        cutBtn->setText(QApplication::translate("CurveMainWindow", "\346\210\252\345\261\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("CurveMainWindow", "\346\233\262\347\272\277\346\254\241\346\225\260\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("CurveMainWindow", "\346\233\262\347\272\277\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        cb1->clear();
        cb1->insertItems(0, QStringList()
         << QApplication::translate("CurveMainWindow", "B\346\240\267\346\235\241\346\233\262\347\272\277", Q_NULLPTR)
         << QApplication::translate("CurveMainWindow", "\350\264\235\351\275\220\345\260\224\346\233\262\347\272\277", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("CurveMainWindow", "B\346\240\267\346\235\241\346\233\262\347\272\277\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        cb2->clear();
        cb2->insertItems(0, QStringList()
         << QApplication::translate("CurveMainWindow", "\345\207\206\345\235\207\345\214\200B\346\240\267\346\235\241\346\233\262\347\272\277", Q_NULLPTR)
         << QApplication::translate("CurveMainWindow", "\345\235\207\345\214\200B\346\240\267\346\235\241\346\233\262\347\272\277", Q_NULLPTR)
         << QApplication::translate("CurveMainWindow", "Riensenfeld\345\217\202\346\225\260\345\214\226\351\235\236\345\235\207\345\214\200B\346\240\267\346\235\241", Q_NULLPTR)
         << QApplication::translate("CurveMainWindow", "Hartley-Judd\345\217\202\346\225\260\345\214\226\351\235\236\345\235\207\345\214\200B\346\240\267\346\235\241", Q_NULLPTR)
         << QApplication::translate("CurveMainWindow", "\345\210\206\346\256\265\350\264\235\351\275\220\345\260\224\346\233\262\347\272\277", Q_NULLPTR)
        );
        backButton->setText(QApplication::translate("CurveMainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        exitButton->setText(QApplication::translate("CurveMainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        label_4->setText(QApplication::translate("CurveMainWindow", "\350\257\267\345\241\253\345\206\231\345\244\247\344\272\216\347\255\211\344\272\2161\347\232\204\346\225\264\346\225\260", Q_NULLPTR));
        editBtn->setText(QApplication::translate("CurveMainWindow", "\347\274\226\350\276\221", Q_NULLPTR));
        menu->setTitle(QApplication::translate("CurveMainWindow", "\346\233\262\347\272\277\347\273\230\345\210\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurveMainWindow: public Ui_CurveMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVEMAINWINDOW_H
