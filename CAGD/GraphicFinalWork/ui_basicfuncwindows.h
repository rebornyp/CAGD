/********************************************************************************
** Form generated from reading UI file 'basicfuncwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASICFUNCWINDOWS_H
#define UI_BASICFUNCWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_basicFuncWindows
{
public:

    void setupUi(QWidget *basicFuncWindows)
    {
        if (basicFuncWindows->objectName().isEmpty())
            basicFuncWindows->setObjectName(QStringLiteral("basicFuncWindows"));
        basicFuncWindows->resize(400, 300);

        retranslateUi(basicFuncWindows);

        QMetaObject::connectSlotsByName(basicFuncWindows);
    } // setupUi

    void retranslateUi(QWidget *basicFuncWindows)
    {
        basicFuncWindows->setWindowTitle(QApplication::translate("basicFuncWindows", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class basicFuncWindows: public Ui_basicFuncWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICFUNCWINDOWS_H
