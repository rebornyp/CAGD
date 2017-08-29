/********************************************************************************
** Form generated from reading UI file 'surfacepart.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACEPART_H
#define UI_SURFACEPART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SurfacePart
{
public:

    void setupUi(QWidget *SurfacePart)
    {
        if (SurfacePart->objectName().isEmpty())
            SurfacePart->setObjectName(QStringLiteral("SurfacePart"));
        SurfacePart->resize(800, 600);

        retranslateUi(SurfacePart);

        QMetaObject::connectSlotsByName(SurfacePart);
    } // setupUi

    void retranslateUi(QWidget *SurfacePart)
    {
        SurfacePart->setWindowTitle(QApplication::translate("SurfacePart", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SurfacePart: public Ui_SurfacePart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACEPART_H
