/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QToolBox *toolBox;
    QWidget *page;
    QGroupBox *groupBox;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_9;
    QWidget *page_2;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;

    void setupUi(QDialog *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QStringLiteral("Help"));
        Help->resize(640, 480);
        Help->setAutoFillBackground(false);
        toolBox = new QToolBox(Help);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(20, 10, 601, 441));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        toolBox->setPalette(palette);
        toolBox->setAutoFillBackground(false);
        toolBox->setFrameShape(QFrame::NoFrame);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 601, 379));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 251, 211));
        groupBox->setCheckable(false);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 160, 221, 40));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../../Desktop/Link to GreyWind/HostApplication/ressources/keys/arrows.png")));
        label_6->setScaledContents(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 40, 44, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../Desktop/Link to GreyWind/HostApplication/ressources/keys/s.png")));
        label_2->setScaledContents(true);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 44, 40));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../Desktop/Link to GreyWind/HostApplication/ressources/keys/q.png")));
        label_4->setScaledContents(true);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 100, 44, 40));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Desktop/Link to GreyWind/HostApplication/ressources/keys/d.png")));
        label_3->setScaledContents(true);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 44, 40));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../Desktop/Link to GreyWind/HostApplication/ressources/keys/z.png")));
        label->setScaledContents(true);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 50, 101, 17));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(130, 110, 121, 17));
        label_6->raise();
        label_2->raise();
        label_4->raise();
        label_3->raise();
        label->raise();
        label_7->raise();
        label_8->raise();
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 230, 281, 141));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 40, 44, 40));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../../Desktop/Link to GreyWind/HostApplication/ressources/keys/f.png")));
        label_5->setScaledContents(true);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(90, 50, 191, 17));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 90, 51, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_12->setFont(font);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(90, 90, 101, 17));
        label_9 = new QLabel(page);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(290, 180, 161, 17));
        toolBox->addItem(page, QStringLiteral("Keyboard"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 601, 379));
        plainTextEdit = new QPlainTextEdit(page_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 20, 601, 31));
        plainTextEdit->setFont(font);
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setBackgroundVisible(false);
        plainTextEdit_2 = new QPlainTextEdit(page_2);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(0, 50, 601, 31));
        plainTextEdit_2->setFrameShape(QFrame::NoFrame);
        plainTextEdit_2->setFrameShadow(QFrame::Sunken);
        plainTextEdit_2->setReadOnly(true);
        plainTextEdit_2->setBackgroundVisible(false);
        toolBox->addItem(page_2, QStringLiteral("Credits"));

        retranslateUi(Help);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QDialog *Help)
    {
        Help->setWindowTitle(QApplication::translate("Help", "Help", 0));
        groupBox->setTitle(QApplication::translate("Help", "Basic Controls", 0));
        label_6->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        label_3->setText(QString());
        label->setText(QString());
        label_7->setText(QApplication::translate("Help", "go Up/Down", 0));
        label_8->setText(QApplication::translate("Help", "spin Left/Right", 0));
        groupBox_2->setTitle(QApplication::translate("Help", "Macros", 0));
        label_5->setText(QString());
        label_10->setText(QApplication::translate("Help", "Initialize horizontal position", 0));
        label_12->setText(QApplication::translate("Help", "SPACE", 0));
        label_11->setText(QApplication::translate("Help", "Take off/Land", 0));
        label_9->setText(QApplication::translate("Help", "Translate horizontally", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Help", "Keyboard", 0));
        plainTextEdit->setPlainText(QApplication::translate("Help", "GreyWind's HostApplication - (C) 2014-2015 - INSA Toulouse", 0));
        plainTextEdit_2->setPlainText(QApplication::translate("Help", "by R\303\251mi Balp, Nicolas Combes,  Rami Kerbage, Duc Thanh Nguyen, Serdar Sahin", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Help", "Credits", 0));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
