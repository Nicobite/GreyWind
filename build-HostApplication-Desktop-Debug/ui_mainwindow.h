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
#include <QtWidgets/QGridLayout>
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
    QPlainTextEdit *cuteConsole;
    QFrame *line_2;
    QPushButton *helpButton;
    QFrame *line_3;
    QFrame *line_4;
    QGroupBox *groupBox_3;
    QPushButton *connectButton;
    QLabel *label_5;
    QPushButton *controlButton;
    QFrame *line_5;
    QLabel *label_7;
    QWidget *gridLayoutWidget;
    QGridLayout *navdataLayout;
    QLabel *label_19;
    QLabel *altitudeLabel;
    QLabel *batteryLabel;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *pitchLabel;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *vyLabel;
    QLabel *rollLabel;
    QLabel *controlStateLabel;
    QLabel *label_8;
    QLabel *yawLabel;
    QLabel *label_21;
    QLabel *label_23;
    QLabel *vxLabel;
    QLabel *label_25;
    QLabel *vzLabel;
    QLabel *connectLabel;
    QFrame *line_6;
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
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 250, 731));
        connectButton = new QPushButton(groupBox_3);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(10, 60, 100, 25));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 25, 140, 25));
        controlButton = new QPushButton(groupBox_3);
        controlButton->setObjectName(QStringLiteral("controlButton"));
        controlButton->setEnabled(false);
        controlButton->setGeometry(QRect(120, 60, 125, 25));
        line_5 = new QFrame(groupBox_3);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(0, 90, 250, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 110, 120, 25));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);
        gridLayoutWidget = new QWidget(groupBox_3);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 140, 231, 203));
        navdataLayout = new QGridLayout(gridLayoutWidget);
        navdataLayout->setSpacing(6);
        navdataLayout->setContentsMargins(11, 11, 11, 11);
        navdataLayout->setObjectName(QStringLiteral("navdataLayout"));
        navdataLayout->setHorizontalSpacing(6);
        navdataLayout->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(gridLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        navdataLayout->addWidget(label_19, 5, 0, 1, 1);

        altitudeLabel = new QLabel(gridLayoutWidget);
        altitudeLabel->setObjectName(QStringLiteral("altitudeLabel"));

        navdataLayout->addWidget(altitudeLabel, 2, 1, 1, 1);

        batteryLabel = new QLabel(gridLayoutWidget);
        batteryLabel->setObjectName(QStringLiteral("batteryLabel"));

        navdataLayout->addWidget(batteryLabel, 1, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        navdataLayout->addWidget(label_9, 1, 0, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        navdataLayout->addWidget(label_13, 2, 0, 1, 1);

        pitchLabel = new QLabel(gridLayoutWidget);
        pitchLabel->setObjectName(QStringLiteral("pitchLabel"));

        navdataLayout->addWidget(pitchLabel, 3, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        navdataLayout->addWidget(label_16, 4, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        navdataLayout->addWidget(label_14, 3, 0, 1, 1);

        vyLabel = new QLabel(gridLayoutWidget);
        vyLabel->setObjectName(QStringLiteral("vyLabel"));

        navdataLayout->addWidget(vyLabel, 7, 1, 1, 1);

        rollLabel = new QLabel(gridLayoutWidget);
        rollLabel->setObjectName(QStringLiteral("rollLabel"));

        navdataLayout->addWidget(rollLabel, 4, 1, 1, 1);

        controlStateLabel = new QLabel(gridLayoutWidget);
        controlStateLabel->setObjectName(QStringLiteral("controlStateLabel"));

        navdataLayout->addWidget(controlStateLabel, 0, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        navdataLayout->addWidget(label_8, 0, 0, 1, 1);

        yawLabel = new QLabel(gridLayoutWidget);
        yawLabel->setObjectName(QStringLiteral("yawLabel"));

        navdataLayout->addWidget(yawLabel, 5, 1, 1, 1);

        label_21 = new QLabel(gridLayoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        navdataLayout->addWidget(label_21, 6, 0, 1, 1);

        label_23 = new QLabel(gridLayoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        navdataLayout->addWidget(label_23, 7, 0, 1, 1);

        vxLabel = new QLabel(gridLayoutWidget);
        vxLabel->setObjectName(QStringLiteral("vxLabel"));

        navdataLayout->addWidget(vxLabel, 6, 1, 1, 1);

        label_25 = new QLabel(gridLayoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));

        navdataLayout->addWidget(label_25, 8, 0, 1, 1);

        vzLabel = new QLabel(gridLayoutWidget);
        vzLabel->setObjectName(QStringLiteral("vzLabel"));

        navdataLayout->addWidget(vzLabel, 8, 1, 1, 1);

        connectLabel = new QLabel(groupBox_3);
        connectLabel->setObjectName(QStringLiteral("connectLabel"));
        connectLabel->setGeometry(QRect(150, 25, 65, 25));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 63, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        connectLabel->setPalette(palette);
        connectLabel->setAutoFillBackground(true);
        line_6 = new QFrame(groupBox_3);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(0, 350, 250, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
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
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Drone Communication", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_5->setText(QApplication::translate("MainWindow", "Connection Status :", 0));
        controlButton->setText(QApplication::translate("MainWindow", "Control Panel", 0));
        label_7->setText(QApplication::translate("MainWindow", "Navigation Data", 0));
        label_19->setText(QApplication::translate("MainWindow", "Yaw :", 0));
        altitudeLabel->setText(QApplication::translate("MainWindow", "-", 0));
        batteryLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_9->setText(QApplication::translate("MainWindow", "Battery :", 0));
        label_13->setText(QApplication::translate("MainWindow", "Altitude :", 0));
        pitchLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_16->setText(QApplication::translate("MainWindow", "Roll :", 0));
        label_14->setText(QApplication::translate("MainWindow", "Pitch :", 0));
        vyLabel->setText(QApplication::translate("MainWindow", "-", 0));
        rollLabel->setText(QApplication::translate("MainWindow", "-", 0));
        controlStateLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_8->setText(QApplication::translate("MainWindow", "Control State:", 0));
        yawLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_21->setText(QApplication::translate("MainWindow", "Vx :", 0));
        label_23->setText(QApplication::translate("MainWindow", "Vy :", 0));
        vxLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_25->setText(QApplication::translate("MainWindow", "Vz :", 0));
        vzLabel->setText(QApplication::translate("MainWindow", "-", 0));
        connectLabel->setText(QApplication::translate("MainWindow", "NOT OK", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
