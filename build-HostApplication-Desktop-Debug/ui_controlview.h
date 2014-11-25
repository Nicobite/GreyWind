/********************************************************************************
** Form generated from reading UI file 'controlview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLVIEW_H
#define UI_CONTROLVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlView
{
public:
    QLabel *label;
    QPushButton *helpButton;

    void setupUi(QWidget *ControlView)
    {
        if (ControlView->objectName().isEmpty())
            ControlView->setObjectName(QStringLiteral("ControlView"));
        ControlView->resize(240, 275);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ControlView->setPalette(palette);
        ControlView->setAutoFillBackground(true);
        label = new QLabel(ControlView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 240, 275));
        label->setFocusPolicy(Qt::StrongFocus);
        label->setPixmap(QPixmap(QString::fromUtf8(":/HostApplication/ressources/joystick.png")));
        helpButton = new QPushButton(ControlView);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        helpButton->setGeometry(QRect(200, 10, 31, 31));
        helpButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/HostApplication/ressources/Help-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpButton->setIcon(icon);
        helpButton->setIconSize(QSize(24, 24));

        retranslateUi(ControlView);

        QMetaObject::connectSlotsByName(ControlView);
    } // setupUi

    void retranslateUi(QWidget *ControlView)
    {
        ControlView->setWindowTitle(QApplication::translate("ControlView", "Drone Control Panel", 0));
        label->setText(QString());
#ifndef QT_NO_TOOLTIP
        helpButton->setToolTip(QApplication::translate("ControlView", "<html><head/><body><p>Click for help</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        helpButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ControlView: public Ui_ControlView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLVIEW_H
