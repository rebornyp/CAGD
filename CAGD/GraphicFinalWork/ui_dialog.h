/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *curveButton;
    QPushButton *surfaceButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(626, 318);
        curveButton = new QPushButton(Dialog);
        curveButton->setObjectName(QStringLiteral("curveButton"));
        curveButton->setGeometry(QRect(80, 230, 181, 61));
        curveButton->setStyleSheet(QLatin1String("\n"
"font: 75 22pt \"Consolas\";"));
        surfaceButton = new QPushButton(Dialog);
        surfaceButton->setObjectName(QStringLiteral("surfaceButton"));
        surfaceButton->setGeometry(QRect(350, 230, 181, 61));
        surfaceButton->setStyleSheet(QLatin1String("\n"
"font: 75 22pt \"Consolas\";"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 110, 181, 111));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/images/curve.png);"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 110, 181, 111));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/images/surface.png);"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 0, 421, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 40, 261, 31));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"font: 16pt \"Adobe \351\273\221\344\275\223 Std R\";"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        curveButton->setText(QApplication::translate("Dialog", "\346\233\262\347\272\277\347\273\230\345\210\266", Q_NULLPTR));
        surfaceButton->setText(QApplication::translate("Dialog", "\346\233\262\351\235\242\347\273\230\345\210\266", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("Dialog", "\350\256\241\347\256\227\346\234\272\350\276\205\345\212\251\345\207\240\344\275\225\350\256\276\350\256\241\345\257\222\345\201\207\345\244\247\344\275\234\344\270\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "SY1607307-\346\230\223\345\223\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
