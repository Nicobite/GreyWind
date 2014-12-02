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
    QLabel *a;
    QLabel *s;
    QLabel *q;
    QLabel *d;
    QLabel *z;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QLabel *f;
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
        a = new QLabel(groupBox);
        a->setObjectName(QStringLiteral("a"));
        a->setGeometry(QRect(20, 160, 221, 40));
        a->setPixmap(QPixmap(QString::fromUtf8(":/HostApplication/ressources/keys/arrows.png")));
        a->setScaledContents(true);
        s = new QLabel(groupBox);
        s->setObjectName(QStringLiteral("s"));
        s->setGeometry(QRect(70, 40, 44, 40));
        s->setPixmap(QPixmap(QString::fromUtf8(":/HostApplication/ressources/keys/s.png")));
        s->setScaledContents(true);
        q = new QLabel(groupBox);
        q->setObjectName(QStringLiteral("q"));
        q->setGeometry(QRect(20, 100, 44, 40));
        q->setPixmap(QPixmap(QString::fromUtf8(":/HostApplication/ressources/keys/q.png")));
        q->setScaledContents(true);
        d = new QLabel(groupBox);
        d->setObjectName(QStringLiteral("d"));
        d->setGeometry(QRect(70, 100, 44, 40));
        d->setPixmap(QPixmap(QString::fromUtf8(":/HostApplication/ressources/keys/d.png")));
        d->setScaledContents(true);
        z = new QLabel(groupBox);
        z->setObjectName(QStringLiteral("z"));
        z->setGeometry(QRect(20, 40, 44, 40));
        z->setPixmap(QPixmap(QString::fromUtf8(":/HostApplication/ressources/keys/z.png")));
        z->setScaledContents(true);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 50, 101, 17));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(130, 110, 121, 17));
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 230, 281, 141));
        f = new QLabel(groupBox_2);
        f->setObjectName(QStringLiteral("f"));
        f->setGeometry(QRect(20, 40, 44, 40));
        f->setPixmap(QPixmap(QString::fromUtf8(":/HostApplication/ressources/keys/f.png")));
        f->setScaledContents(true);
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
        a->setText(QString());
        s->setText(QString());
        q->setText(QString());
        d->setText(QString());
        z->setText(QString());
        label_7->setText(QApplication::translate("Help", "go Up/Down", 0));
        label_8->setText(QApplication::translate("Help", "spin Left/Right", 0));
        groupBox_2->setTitle(QApplication::translate("Help", "Macros", 0));
        f->setText(QString());
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
