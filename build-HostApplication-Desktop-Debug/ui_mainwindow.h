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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "videoview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    VideoView *theFrame;
    QLabel *navDataLabel;
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *srcSelect;
    QLabel *label_4;
    QComboBox *algSelect;
    QDoubleSpinBox *framesB4Detect;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *tasksCheckboxes;
    QCheckBox *face;
    QCheckBox *banana;
    QCheckBox *pyramid;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QCheckBox *laserOn;
    QLCDNumber *distanceDisplay;
    QPushButton *getDistance;
    QFrame *line;
    QLCDNumber *lcdNumber;
    QPlainTextEdit *cuteConsole;
    QFrame *line_2;
    QPushButton *helpButton;
    QFrame *line_3;
    QFrame *line_4;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1400, 800);
        MainWindow->setMinimumSize(QSize(1400, 800));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        theFrame = new VideoView(centralWidget);
        theFrame->setObjectName(QStringLiteral("theFrame"));
        theFrame->setGeometry(QRect(270, 10, 640, 360));
        theFrame->setMinimumSize(QSize(640, 360));
        theFrame->setMaximumSize(QSize(1280, 720));
        navDataLabel = new QLabel(centralWidget);
        navDataLabel->setObjectName(QStringLiteral("navDataLabel"));
        navDataLabel->setGeometry(QRect(10, 10, 250, 731));
        navDataLabel->setMinimumSize(QSize(250, 700));
        navDataLabel->setMaximumSize(QSize(16777215, 16777215));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(290, 380, 181, 271));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 67, 17));
        srcSelect = new QComboBox(groupBox);
        srcSelect->setObjectName(QStringLiteral("srcSelect"));
        srcSelect->setGeometry(QRect(40, 40, 61, 27));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 170, 51, 17));
        algSelect = new QComboBox(groupBox);
        algSelect->setObjectName(QStringLiteral("algSelect"));
        algSelect->setGeometry(QRect(40, 90, 91, 27));
        framesB4Detect = new QDoubleSpinBox(groupBox);
        framesB4Detect->setObjectName(QStringLiteral("framesB4Detect"));
        framesB4Detect->setGeometry(QRect(40, 140, 69, 27));
#ifndef QT_NO_TOOLTIP
        framesB4Detect->setToolTip(QStringLiteral("<html><head/><body><p>WARNING: The lower the number, the heavier the LAAAG</p></body></html>"));
#endif // QT_NO_TOOLTIP
        framesB4Detect->setLayoutDirection(Qt::RightToLeft);
        framesB4Detect->setKeyboardTracking(false);
        framesB4Detect->setDecimals(0);
        framesB4Detect->setMaximum(200);
        framesB4Detect->setValue(40);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 91, 17));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 161, 17));
        tasksCheckboxes = new QWidget(groupBox);
        tasksCheckboxes->setObjectName(QStringLiteral("tasksCheckboxes"));
        tasksCheckboxes->setGeometry(QRect(30, 180, 120, 80));
        face = new QCheckBox(tasksCheckboxes);
        face->setObjectName(QStringLiteral("face"));
        face->setGeometry(QRect(10, 10, 97, 22));
        banana = new QCheckBox(tasksCheckboxes);
        banana->setObjectName(QStringLiteral("banana"));
        banana->setGeometry(QRect(10, 50, 97, 22));
        pyramid = new QCheckBox(tasksCheckboxes);
        pyramid->setObjectName(QStringLiteral("pyramid"));
        pyramid->setGeometry(QRect(10, 30, 97, 22));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(490, 380, 181, 271));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 50, 131, 17));
        laserOn = new QCheckBox(groupBox_2);
        laserOn->setObjectName(QStringLiteral("laserOn"));
        laserOn->setGeometry(QRect(20, 20, 97, 22));
        distanceDisplay = new QLCDNumber(groupBox_2);
        distanceDisplay->setObjectName(QStringLiteral("distanceDisplay"));
        distanceDisplay->setGeometry(QRect(20, 70, 101, 31));
        distanceDisplay->setFrameShape(QFrame::StyledPanel);
        distanceDisplay->setSegmentStyle(QLCDNumber::Flat);
        getDistance = new QPushButton(groupBox_2);
        getDistance->setObjectName(QStringLiteral("getDistance"));
        getDistance->setGeometry(QRect(130, 70, 41, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/HostApplication/ressources/system-software-update.png"), QSize(), QIcon::Normal, QIcon::Off);
        getDistance->setIcon(icon);
        getDistance->setIconSize(QSize(24, 24));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(463, 380, 20, 261));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(30, 410, 191, 121));
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(80085));
        cuteConsole = new QPlainTextEdit(centralWidget);
        cuteConsole->setObjectName(QStringLiteral("cuteConsole"));
        cuteConsole->setGeometry(QRect(270, 650, 641, 91));
        QFont font;
        font.setFamily(QStringLiteral("Courier 10 Pitch"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        cuteConsole->setFont(font);
        cuteConsole->setAutoFillBackground(true);
        cuteConsole->setFrameShape(QFrame::StyledPanel);
        cuteConsole->setFrameShadow(QFrame::Sunken);
        cuteConsole->setReadOnly(true);
        cuteConsole->setBackgroundVisible(false);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(670, 380, 20, 261));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        helpButton = new QPushButton(centralWidget);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        helpButton->setGeometry(QRect(880, 380, 31, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/HostApplication/ressources/Help-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpButton->setIcon(icon1);
        helpButton->setIconSize(QSize(24, 24));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(860, 380, 20, 261));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(260, 380, 20, 261));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1400, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        navDataLabel->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>NabData Widgets</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        navDataLabel->setText(QApplication::translate("MainWindow", "NavData widgets", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Video settings", 0));
        label->setText(QApplication::translate("MainWindow", "Source:", 0));
        srcSelect->clear();
        srcSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Local", 0)
         << QApplication::translate("MainWindow", "TCP", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "Detect:", 0));
        algSelect->clear();
        algSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "<none>", 0)
         << QApplication::translate("MainWindow", "Haar", 0)
         << QApplication::translate("MainWindow", "...", 0)
        );
#ifndef QT_NO_WHATSTHIS
        framesB4Detect->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>rqsdfsfd</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("MainWindow", "Algorithm:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Frames before recog:", 0));
        face->setText(QApplication::translate("MainWindow", "face", 0));
        banana->setText(QApplication::translate("MainWindow", "banana", 0));
        pyramid->setText(QApplication::translate("MainWindow", "pyramid", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Commands", 0));
        label_6->setText(QApplication::translate("MainWindow", "Measure distance:", 0));
        laserOn->setText(QApplication::translate("MainWindow", "Laser aim", 0));
#ifndef QT_NO_TOOLTIP
        distanceDisplay->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>(centimeters)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        getDistance->setText(QString());
        cuteConsole->setPlainText(QApplication::translate("MainWindow", "Welcome to GreyWind's host application!", 0));
#ifndef QT_NO_TOOLTIP
        helpButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Click for help</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        helpButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
