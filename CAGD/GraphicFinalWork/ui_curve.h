/********************************************************************************
** Form generated from reading UI file 'curve.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVE_H
#define UI_CURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Curve
{
public:

    void setupUi(QWidget *Curve)
    {
        if (Curve->objectName().isEmpty())
            Curve->setObjectName(QStringLiteral("Curve"));
        Curve->resize(738, 435);

        retranslateUi(Curve);

        QMetaObject::connectSlotsByName(Curve);
    } // setupUi

    void retranslateUi(QWidget *Curve)
    {
        Curve->setWindowTitle(QApplication::translate("Curve", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Curve: public Ui_Curve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVE_H
