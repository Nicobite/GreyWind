/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "videoview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    VideoView *theFrame;
    QComboBox *srcSelect;
    QLabel *label_src;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuGreyWind_Host_Application;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 16777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        theFrame = new VideoView(centralWidget);
        theFrame->setObjectName(QStringLiteral("theFrame"));
        theFrame->setGeometry(QRect(10, 60, 640, 360));
        theFrame->setMinimumSize(QSize(640, 360));
        theFrame->setMaximumSize(QSize(1280, 720));
        srcSelect = new QComboBox(centralWidget);
        srcSelect->setObjectName(QStringLiteral("srcSelect"));
        srcSelect->setGeometry(QRect(10, 20, 61, 27));
        label_src = new QLabel(centralWidget);
        label_src->setObjectName(QStringLiteral("label_src"));
        label_src->setGeometry(QRect(10, 0, 31, 21));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        menuGreyWind_Host_Application = new QMenu(menuBar);
        menuGreyWind_Host_Application->setObjectName(QStringLiteral("menuGreyWind_Host_Application"));
        MainWindow->setMenuBar(menuBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menuBar->addAction(menuGreyWind_Host_Application->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        srcSelect->clear();
        srcSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Local", 0)
         << QApplication::translate("MainWindow", "TCP", 0)
        );
        label_src->setText(QApplication::translate("MainWindow", "SRC", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        menuGreyWind_Host_Application->setTitle(QApplication::translate("MainWindow", "GreyWind Host Application", 0));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
