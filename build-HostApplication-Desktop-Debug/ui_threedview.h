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
#include <QtOpenGL/QGLWidget>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ThreeDView
{
public:
    QGLWidget *glWidget;

    void setupUi(QDialog *ThreeDView)
    {
        if (ThreeDView->objectName().isEmpty())
            ThreeDView->setObjectName(QStringLiteral("ThreeDView"));
        ThreeDView->resize(1280, 960);
        glWidget = new QGLWidget(ThreeDView);
        glWidget->setObjectName(QStringLiteral("glWidget"));
        glWidget->setGeometry(QRect(0, 0, 1280, 720));

        retranslateUi(ThreeDView);

        QMetaObject::connectSlotsByName(ThreeDView);
    } // setupUi

    void retranslateUi(QDialog *ThreeDView)
    {
        ThreeDView->setWindowTitle(QApplication::translate("ThreeDView", "3D view", 0));
    } // retranslateUi

};

namespace Ui {
    class ThreeDView: public Ui_ThreeDView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREEDVIEW_H
