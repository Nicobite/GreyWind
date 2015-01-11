/********************************************************************************
** Form generated from reading UI file 'threedview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREEDVIEW_H
#define UI_THREEDVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <GUI/glwidget.h>

QT_BEGIN_NAMESPACE

class Ui_ThreeDView
{
public:
    glWidget *myGlWidget;
    QSlider *xRotSlider;
    QSlider *yRotSlider;
    QSlider *zRotSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *ThreeDView)
    {
        if (ThreeDView->objectName().isEmpty())
            ThreeDView->setObjectName(QStringLiteral("ThreeDView"));
        ThreeDView->resize(1280, 960);
        myGlWidget = new glWidget(ThreeDView);
        myGlWidget->setObjectName(QStringLiteral("myGlWidget"));
        myGlWidget->setGeometry(QRect(0, 0, 1280, 720));
        xRotSlider = new QSlider(ThreeDView);
        xRotSlider->setObjectName(QStringLiteral("xRotSlider"));
        xRotSlider->setGeometry(QRect(30, 730, 201, 29));
        xRotSlider->setMaximum(360);
        xRotSlider->setSingleStep(16);
        xRotSlider->setPageStep(15);
        xRotSlider->setOrientation(Qt::Horizontal);
        xRotSlider->setTickPosition(QSlider::TicksAbove);
        xRotSlider->setTickInterval(15);
        yRotSlider = new QSlider(ThreeDView);
        yRotSlider->setObjectName(QStringLiteral("yRotSlider"));
        yRotSlider->setGeometry(QRect(30, 760, 201, 29));
        yRotSlider->setMaximum(360);
        yRotSlider->setSingleStep(16);
        yRotSlider->setPageStep(15);
        yRotSlider->setOrientation(Qt::Horizontal);
        yRotSlider->setTickPosition(QSlider::TicksAbove);
        yRotSlider->setTickInterval(15);
        zRotSlider = new QSlider(ThreeDView);
        zRotSlider->setObjectName(QStringLiteral("zRotSlider"));
        zRotSlider->setGeometry(QRect(30, 790, 201, 29));
        zRotSlider->setMaximum(360);
        zRotSlider->setSingleStep(16);
        zRotSlider->setPageStep(15);
        zRotSlider->setOrientation(Qt::Horizontal);
        zRotSlider->setTickPosition(QSlider::TicksAbove);
        zRotSlider->setTickInterval(15);
        label = new QLabel(ThreeDView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 730, 16, 17));
        label_2 = new QLabel(ThreeDView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 760, 16, 17));
        label_3 = new QLabel(ThreeDView);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 790, 16, 17));

        retranslateUi(ThreeDView);
        QObject::connect(xRotSlider, SIGNAL(valueChanged(int)), myGlWidget, SLOT(setXRotation(int)));
        QObject::connect(yRotSlider, SIGNAL(valueChanged(int)), myGlWidget, SLOT(setYRotation(int)));
        QObject::connect(zRotSlider, SIGNAL(valueChanged(int)), myGlWidget, SLOT(setZRotation(int)));

        QMetaObject::connectSlotsByName(ThreeDView);
    } // setupUi

    void retranslateUi(QDialog *ThreeDView)
    {
        ThreeDView->setWindowTitle(QApplication::translate("ThreeDView", "3D view", 0));
        label->setText(QApplication::translate("ThreeDView", "x", 0));
        label_2->setText(QApplication::translate("ThreeDView", "y", 0));
        label_3->setText(QApplication::translate("ThreeDView", "z", 0));
    } // retranslateUi

};

namespace Ui {
    class ThreeDView: public Ui_ThreeDView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREEDVIEW_H
