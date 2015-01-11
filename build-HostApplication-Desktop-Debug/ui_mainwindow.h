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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "./GUI/videoview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *cuteConsole;
    QGroupBox *groupBox_3;
    QPushButton *connectButton;
    QLabel *label_5;
    QFrame *line_5;
    QLabel *label_7;
    QWidget *gridLayoutWidget;
    QGridLayout *navdataLayout;
    QLabel *rollLabel;
    QLabel *label_16;
    QLabel *label_19;
    QLabel *altitudeLabel;
    QLabel *batteryLabel;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *pitchLabel;
    QLabel *label_14;
    QLabel *vyLabel;
    QLabel *controlStateLabel;
    QLabel *label_8;
    QLabel *yawLabel;
    QLabel *label_21;
    QLabel *label_23;
    QLabel *vxLabel;
    QLabel *connectLabel;
    QFrame *line_6;
    QPushButton *helpButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *controlGraphicLabel;
    QLabel *controlTextLabel;
    QLabel *label_12;
    QFrame *line_7;
    QLabel *label_15;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *pzLabel;
    QLabel *pxLabel;
    QLabel *label_10;
    QLabel *label_17;
    QLabel *label_20;
    QLabel *pyLabel;
    QLabel *label_24;
    QLabel *ppsiLabel;
    QPushButton *resetPosition;
    QLabel *label_18;
    QPushButton *threeDButton;
    VideoView *theFrame;
    QTabWidget *mainTabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *srcSelect;
    QDoubleSpinBox *framesB4Detect;
    QLabel *label_3;
    QFrame *line_3;
    QFrame *line_4;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QCheckBox *laserOn;
    QLCDNumber *distanceDisplay;
    QPushButton *getDistance;
    QGroupBox *groupBox_4;
    QGroupBox *objectDetectedLocationgroupBox;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *xCenterlabel;
    QLabel *yCenterlabel;
    QLabel *radiuslabel;
    QLabel *label_22;
    QLabel *objectDetectedIconlabel;
    QLabel *label_11;
    QPushButton *detectButton;
    QLabel *sizeBlackListlabel;
    QPushButton *clearButton;
    QGroupBox *groupBox_5;
    QComboBox *algSelect;
    QLabel *label_2;
    QLineEdit *objSource;
    QLabel *label_4;
    QPushButton *helpButton_2;
    QPushButton *objOkButton;
    QGroupBox *groupBox_6;
    QLabel *label_25;
    QComboBox *trackAlgSelect;
    QPushButton *trackButton;
    QLabel *label_34;
    QLabel *trackState;
    QWidget *tab_2;
    QGroupBox *groupBox_7;
    QComboBox *algDetectSelect;
    QLabel *label_26;
    QLineEdit *objSource_2;
    QLabel *label_32;
    QPushButton *addAlgoObject;
    QPushButton *subAlgoObject;
    QLabel *label_35;
    QComboBox *algTrackingSelect;
    QGroupBox *groupBox_8;
    QLabel *label_33;
    QPushButton *abortMission;
    QLineEdit *stateMission;
    QPushButton *startMission;
    QListWidget *listWidget;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(950, 800);
        MainWindow->setMinimumSize(QSize(950, 800));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cuteConsole = new QPlainTextEdit(centralWidget);
        cuteConsole->setObjectName(QStringLiteral("cuteConsole"));
        cuteConsole->setGeometry(QRect(270, 680, 641, 61));
        QFont font;
        font.setFamily(QStringLiteral("Courier 10 Pitch"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        cuteConsole->setFont(font);
        cuteConsole->setFocusPolicy(Qt::NoFocus);
        cuteConsole->setAutoFillBackground(true);
        cuteConsole->setFrameShape(QFrame::StyledPanel);
        cuteConsole->setFrameShadow(QFrame::Sunken);
        cuteConsole->setReadOnly(true);
        cuteConsole->setBackgroundVisible(false);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 250, 731));
        connectButton = new QPushButton(groupBox_3);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(10, 50, 100, 30));
        connectButton->setFocusPolicy(Qt::NoFocus);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 25, 140, 23));
        line_5 = new QFrame(groupBox_3);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(0, 80, 250, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 90, 120, 25));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);
        gridLayoutWidget = new QWidget(groupBox_3);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 120, 231, 181));
        navdataLayout = new QGridLayout(gridLayoutWidget);
        navdataLayout->setSpacing(6);
        navdataLayout->setContentsMargins(11, 11, 11, 11);
        navdataLayout->setObjectName(QStringLiteral("navdataLayout"));
        navdataLayout->setHorizontalSpacing(6);
        navdataLayout->setContentsMargins(0, 0, 0, 0);
        rollLabel = new QLabel(gridLayoutWidget);
        rollLabel->setObjectName(QStringLiteral("rollLabel"));

        navdataLayout->addWidget(rollLabel, 4, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        navdataLayout->addWidget(label_16, 4, 0, 1, 1);

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

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        navdataLayout->addWidget(label_14, 3, 0, 1, 1);

        vyLabel = new QLabel(gridLayoutWidget);
        vyLabel->setObjectName(QStringLiteral("vyLabel"));

        navdataLayout->addWidget(vyLabel, 7, 1, 1, 1);

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

        connectLabel = new QLabel(groupBox_3);
        connectLabel->setObjectName(QStringLiteral("connectLabel"));
        connectLabel->setGeometry(QRect(150, 25, 65, 23));
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
        line_6->setGeometry(QRect(0, 300, 250, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        helpButton = new QPushButton(groupBox_3);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        helpButton->setGeometry(QRect(180, 50, 45, 30));
        helpButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/HostApplication/ressources/Help-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpButton->setIcon(icon);
        helpButton->setIconSize(QSize(24, 24));
        verticalLayoutWidget = new QWidget(groupBox_3);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 340, 231, 227));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        controlGraphicLabel = new QLabel(verticalLayoutWidget);
        controlGraphicLabel->setObjectName(QStringLiteral("controlGraphicLabel"));
        controlGraphicLabel->setMouseTracking(true);
        controlGraphicLabel->setFocusPolicy(Qt::NoFocus);
        controlGraphicLabel->setLayoutDirection(Qt::LeftToRight);
        controlGraphicLabel->setAutoFillBackground(true);
        controlGraphicLabel->setFrameShape(QFrame::NoFrame);
        controlGraphicLabel->setPixmap(QPixmap(QString::fromUtf8(":/HostApplication/ressources/joystick_inactive.png")));
        controlGraphicLabel->setAlignment(Qt::AlignCenter);
        controlGraphicLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(controlGraphicLabel);

        controlTextLabel = new QLabel(verticalLayoutWidget);
        controlTextLabel->setObjectName(QStringLiteral("controlTextLabel"));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        controlTextLabel->setFont(font2);
        controlTextLabel->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(controlTextLabel);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 310, 120, 25));
        label_12->setFont(font1);
        line_7 = new QFrame(groupBox_3);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(0, 570, 250, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(0, 580, 150, 25));
        label_15->setFont(font1);
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(9, 600, 231, 88));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pzLabel = new QLabel(gridLayoutWidget_2);
        pzLabel->setObjectName(QStringLiteral("pzLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pzLabel->sizePolicy().hasHeightForWidth());
        pzLabel->setSizePolicy(sizePolicy);
        pzLabel->setFrameShape(QFrame::NoFrame);
        pzLabel->setLineWidth(0);
        pzLabel->setMidLineWidth(0);

        gridLayout->addWidget(pzLabel, 2, 1, 1, 1);

        pxLabel = new QLabel(gridLayoutWidget_2);
        pxLabel->setObjectName(QStringLiteral("pxLabel"));
        sizePolicy.setHeightForWidth(pxLabel->sizePolicy().hasHeightForWidth());
        pxLabel->setSizePolicy(sizePolicy);
        pxLabel->setFrameShape(QFrame::NoFrame);
        pxLabel->setLineWidth(0);
        pxLabel->setMidLineWidth(0);

        gridLayout->addWidget(pxLabel, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(50, 0));
        label_10->setFrameShape(QFrame::NoFrame);
        label_10->setLineWidth(0);
        label_10->setMidLineWidth(0);

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setMinimumSize(QSize(50, 0));
        label_17->setFrameShape(QFrame::NoFrame);
        label_17->setLineWidth(0);
        label_17->setMidLineWidth(0);

        gridLayout->addWidget(label_17, 1, 0, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        sizePolicy1.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy1);
        label_20->setMinimumSize(QSize(50, 0));
        label_20->setFrameShape(QFrame::NoFrame);
        label_20->setLineWidth(0);
        label_20->setMidLineWidth(0);

        gridLayout->addWidget(label_20, 2, 0, 1, 1);

        pyLabel = new QLabel(gridLayoutWidget_2);
        pyLabel->setObjectName(QStringLiteral("pyLabel"));
        sizePolicy.setHeightForWidth(pyLabel->sizePolicy().hasHeightForWidth());
        pyLabel->setSizePolicy(sizePolicy);
        pyLabel->setFrameShape(QFrame::NoFrame);
        pyLabel->setLineWidth(0);
        pyLabel->setMidLineWidth(0);

        gridLayout->addWidget(pyLabel, 1, 1, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        sizePolicy1.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy1);
        label_24->setMinimumSize(QSize(50, 0));
        label_24->setFrameShape(QFrame::NoFrame);
        label_24->setLineWidth(0);
        label_24->setMidLineWidth(0);

        gridLayout->addWidget(label_24, 3, 0, 1, 1);

        ppsiLabel = new QLabel(gridLayoutWidget_2);
        ppsiLabel->setObjectName(QStringLiteral("ppsiLabel"));
        sizePolicy.setHeightForWidth(ppsiLabel->sizePolicy().hasHeightForWidth());
        ppsiLabel->setSizePolicy(sizePolicy);
        ppsiLabel->setFrameShape(QFrame::NoFrame);
        ppsiLabel->setLineWidth(0);
        ppsiLabel->setMidLineWidth(0);

        gridLayout->addWidget(ppsiLabel, 3, 1, 1, 1);

        resetPosition = new QPushButton(groupBox_3);
        resetPosition->setObjectName(QStringLiteral("resetPosition"));
        resetPosition->setGeometry(QRect(130, 695, 40, 25));
        resetPosition->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/HostApplication/ressources/system-software-update.png"), QSize(), QIcon::Normal, QIcon::Off);
        resetPosition->setIcon(icon1);
        resetPosition->setIconSize(QSize(24, 24));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 700, 131, 17));
        threeDButton = new QPushButton(groupBox_3);
        threeDButton->setObjectName(QStringLiteral("threeDButton"));
        threeDButton->setGeometry(QRect(120, 50, 51, 30));
        threeDButton->setFocusPolicy(Qt::NoFocus);
        theFrame = new VideoView(centralWidget);
        theFrame->setObjectName(QStringLiteral("theFrame"));
        theFrame->setGeometry(QRect(270, 10, 640, 360));
        theFrame->setMinimumSize(QSize(640, 360));
        theFrame->setMaximumSize(QSize(1280, 720));
        mainTabWidget = new QTabWidget(centralWidget);
        mainTabWidget->setObjectName(QStringLiteral("mainTabWidget"));
        mainTabWidget->setEnabled(true);
        mainTabWidget->setGeometry(QRect(280, 380, 631, 291));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 181, 131));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 67, 17));
        srcSelect = new QComboBox(groupBox);
        srcSelect->setObjectName(QStringLiteral("srcSelect"));
        srcSelect->setGeometry(QRect(40, 40, 70, 27));
        srcSelect->setFocusPolicy(Qt::NoFocus);
        framesB4Detect = new QDoubleSpinBox(groupBox);
        framesB4Detect->setObjectName(QStringLiteral("framesB4Detect"));
        framesB4Detect->setGeometry(QRect(40, 90, 71, 27));
        framesB4Detect->setFocusPolicy(Qt::ClickFocus);
#ifndef QT_NO_TOOLTIP
        framesB4Detect->setToolTip(QStringLiteral("<html><head/><body><p>WARNING: The lower the number, the heavier the LAAAG</p></body></html>"));
#endif // QT_NO_TOOLTIP
        framesB4Detect->setLayoutDirection(Qt::RightToLeft);
        framesB4Detect->setKeyboardTracking(false);
        framesB4Detect->setDecimals(0);
        framesB4Detect->setMaximum(200);
        framesB4Detect->setValue(40);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 161, 17));
        line_3 = new QFrame(tab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(410, 10, 20, 241));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(tab);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(200, 10, 20, 241));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setEnabled(true);
        groupBox_2->setGeometry(QRect(430, 0, 181, 121));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 50, 131, 17));
        laserOn = new QCheckBox(groupBox_2);
        laserOn->setObjectName(QStringLiteral("laserOn"));
        laserOn->setGeometry(QRect(20, 20, 97, 22));
        laserOn->setFocusPolicy(Qt::NoFocus);
        distanceDisplay = new QLCDNumber(groupBox_2);
        distanceDisplay->setObjectName(QStringLiteral("distanceDisplay"));
        distanceDisplay->setGeometry(QRect(20, 70, 101, 31));
        distanceDisplay->setFrameShape(QFrame::StyledPanel);
        distanceDisplay->setSegmentStyle(QLCDNumber::Flat);
        getDistance = new QPushButton(groupBox_2);
        getDistance->setObjectName(QStringLiteral("getDistance"));
        getDistance->setGeometry(QRect(130, 70, 41, 31));
        getDistance->setFocusPolicy(Qt::NoFocus);
        getDistance->setIcon(icon1);
        getDistance->setIconSize(QSize(24, 24));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(220, 0, 201, 251));
        objectDetectedLocationgroupBox = new QGroupBox(groupBox_4);
        objectDetectedLocationgroupBox->setObjectName(QStringLiteral("objectDetectedLocationgroupBox"));
        objectDetectedLocationgroupBox->setEnabled(false);
        objectDetectedLocationgroupBox->setGeometry(QRect(10, 130, 171, 121));
        objectDetectedLocationgroupBox->setFlat(false);
        label_27 = new QLabel(objectDetectedLocationgroupBox);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(0, 20, 67, 17));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        label_27->setFont(font3);
        label_28 = new QLabel(objectDetectedLocationgroupBox);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(0, 80, 67, 17));
        label_28->setFont(font3);
        label_29 = new QLabel(objectDetectedLocationgroupBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(40, 40, 67, 17));
        label_30 = new QLabel(objectDetectedLocationgroupBox);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(40, 60, 67, 17));
        label_31 = new QLabel(objectDetectedLocationgroupBox);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(40, 100, 67, 17));
        xCenterlabel = new QLabel(objectDetectedLocationgroupBox);
        xCenterlabel->setObjectName(QStringLiteral("xCenterlabel"));
        xCenterlabel->setGeometry(QRect(60, 40, 67, 17));
        yCenterlabel = new QLabel(objectDetectedLocationgroupBox);
        yCenterlabel->setObjectName(QStringLiteral("yCenterlabel"));
        yCenterlabel->setGeometry(QRect(60, 60, 67, 17));
        radiuslabel = new QLabel(objectDetectedLocationgroupBox);
        radiuslabel->setObjectName(QStringLiteral("radiuslabel"));
        radiuslabel->setGeometry(QRect(60, 100, 67, 17));
        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 100, 121, 17));
        objectDetectedIconlabel = new QLabel(groupBox_4);
        objectDetectedIconlabel->setObjectName(QStringLiteral("objectDetectedIconlabel"));
        objectDetectedIconlabel->setGeometry(QRect(130, 100, 21, 16));
        objectDetectedIconlabel->setFrameShape(QFrame::NoFrame);
        objectDetectedIconlabel->setFrameShadow(QFrame::Plain);
        objectDetectedIconlabel->setTextFormat(Qt::AutoText);
        objectDetectedIconlabel->setPixmap(QPixmap(QString::fromUtf8(":/HostApplication/ressources/Icon-16x16-not_ok.png")));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 70, 141, 17));
        detectButton = new QPushButton(groupBox_4);
        detectButton->setObjectName(QStringLiteral("detectButton"));
        detectButton->setGeometry(QRect(0, 30, 99, 27));
        sizeBlackListlabel = new QLabel(groupBox_4);
        sizeBlackListlabel->setObjectName(QStringLiteral("sizeBlackListlabel"));
        sizeBlackListlabel->setGeometry(QRect(160, 70, 41, 17));
        clearButton = new QPushButton(groupBox_4);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(120, 30, 61, 27));
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 130, 211, 121));
        algSelect = new QComboBox(groupBox_5);
        algSelect->setObjectName(QStringLiteral("algSelect"));
        algSelect->setGeometry(QRect(30, 40, 91, 27));
        algSelect->setFocusPolicy(Qt::NoFocus);
        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 91, 17));
        objSource = new QLineEdit(groupBox_5);
        objSource->setObjectName(QStringLiteral("objSource"));
        objSource->setGeometry(QRect(30, 90, 113, 30));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 51, 17));
        helpButton_2 = new QPushButton(groupBox_5);
        helpButton_2->setObjectName(QStringLiteral("helpButton_2"));
        helpButton_2->setGeometry(QRect(150, 40, 45, 30));
        helpButton_2->setFocusPolicy(Qt::NoFocus);
        helpButton_2->setIcon(icon);
        helpButton_2->setIconSize(QSize(24, 24));
        objOkButton = new QPushButton(groupBox_5);
        objOkButton->setObjectName(QStringLiteral("objOkButton"));
        objOkButton->setGeometry(QRect(150, 90, 40, 30));
        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setEnabled(true);
        groupBox_6->setGeometry(QRect(430, 110, 181, 141));
        label_25 = new QLabel(groupBox_6);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(10, 30, 91, 17));
        trackAlgSelect = new QComboBox(groupBox_6);
        trackAlgSelect->setObjectName(QStringLiteral("trackAlgSelect"));
        trackAlgSelect->setGeometry(QRect(30, 50, 91, 27));
        trackAlgSelect->setFocusPolicy(Qt::NoFocus);
        trackButton = new QPushButton(groupBox_6);
        trackButton->setObjectName(QStringLiteral("trackButton"));
        trackButton->setEnabled(false);
        trackButton->setGeometry(QRect(40, 80, 99, 27));
        label_34 = new QLabel(groupBox_6);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(10, 110, 51, 20));
        trackState = new QLabel(groupBox_6);
        trackState->setObjectName(QStringLiteral("trackState"));
        trackState->setGeometry(QRect(70, 110, 131, 20));
        mainTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 0, 311, 141));
        groupBox_7->setFlat(false);
        algDetectSelect = new QComboBox(groupBox_7);
        algDetectSelect->setObjectName(QStringLiteral("algDetectSelect"));
        algDetectSelect->setGeometry(QRect(10, 40, 91, 27));
        algDetectSelect->setFocusPolicy(Qt::NoFocus);
        label_26 = new QLabel(groupBox_7);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(0, 10, 151, 31));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        label_26->setFont(font4);
        objSource_2 = new QLineEdit(groupBox_7);
        objSource_2->setObjectName(QStringLiteral("objSource_2"));
        objSource_2->setGeometry(QRect(90, 100, 113, 30));
        label_32 = new QLabel(groupBox_7);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(120, 80, 51, 17));
        addAlgoObject = new QPushButton(groupBox_7);
        addAlgoObject->setObjectName(QStringLiteral("addAlgoObject"));
        addAlgoObject->setGeometry(QRect(210, 80, 40, 30));
        subAlgoObject = new QPushButton(groupBox_7);
        subAlgoObject->setObjectName(QStringLiteral("subAlgoObject"));
        subAlgoObject->setGeometry(QRect(210, 110, 40, 30));
        label_35 = new QLabel(groupBox_7);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(180, 10, 121, 31));
        label_35->setFont(font4);
        algTrackingSelect = new QComboBox(groupBox_7);
        algTrackingSelect->setObjectName(QStringLiteral("algTrackingSelect"));
        algTrackingSelect->setGeometry(QRect(190, 40, 91, 27));
        algTrackingSelect->setFocusPolicy(Qt::NoFocus);
        groupBox_8 = new QGroupBox(tab_2);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 140, 291, 81));
        groupBox_8->setFlat(false);
        label_33 = new QLabel(groupBox_8);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(10, 20, 91, 17));
        abortMission = new QPushButton(groupBox_8);
        abortMission->setObjectName(QStringLiteral("abortMission"));
        abortMission->setGeometry(QRect(200, 40, 71, 30));
        stateMission = new QLineEdit(groupBox_8);
        stateMission->setObjectName(QStringLiteral("stateMission"));
        stateMission->setGeometry(QRect(0, 40, 161, 30));
        startMission = new QPushButton(tab_2);
        startMission->setObjectName(QStringLiteral("startMission"));
        startMission->setGeometry(QRect(10, 220, 99, 27));
        listWidget = new QListWidget(tab_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(310, 10, 301, 221));
        mainTabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 950, 25));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        mainTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GreyWind Host Application", 0));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        cuteConsole->setPlainText(QApplication::translate("MainWindow", "Welcome to GreyWind's host application!", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Drone Communication", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_5->setText(QApplication::translate("MainWindow", "Connection Status :", 0));
        label_7->setText(QApplication::translate("MainWindow", "Navigation Data", 0));
        rollLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_16->setText(QApplication::translate("MainWindow", "Roll :", 0));
        label_19->setText(QApplication::translate("MainWindow", "Yaw :", 0));
        altitudeLabel->setText(QApplication::translate("MainWindow", "-", 0));
        batteryLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_9->setText(QApplication::translate("MainWindow", "Battery :", 0));
        label_13->setText(QApplication::translate("MainWindow", "Altitude :", 0));
        pitchLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_14->setText(QApplication::translate("MainWindow", "Pitch :", 0));
        vyLabel->setText(QApplication::translate("MainWindow", "-", 0));
        controlStateLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_8->setText(QApplication::translate("MainWindow", "Control State:", 0));
        yawLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_21->setText(QApplication::translate("MainWindow", "Vx :", 0));
        label_23->setText(QApplication::translate("MainWindow", "Vy :", 0));
        vxLabel->setText(QApplication::translate("MainWindow", "-", 0));
        connectLabel->setText(QApplication::translate("MainWindow", "NOT OK", 0));
#ifndef QT_NO_TOOLTIP
        helpButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Click for help</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        helpButton->setText(QString());
        controlGraphicLabel->setText(QString());
        controlTextLabel->setText(QApplication::translate("MainWindow", "Not connected...", 0));
        label_12->setText(QApplication::translate("MainWindow", "Drone Control", 0));
        label_15->setText(QApplication::translate("MainWindow", "Position Estimation", 0));
        pzLabel->setText(QApplication::translate("MainWindow", "-", 0));
        pxLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_10->setText(QApplication::translate("MainWindow", "x :", 0));
        label_17->setText(QApplication::translate("MainWindow", "y :", 0));
        label_20->setText(QApplication::translate("MainWindow", "z :", 0));
        pyLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_24->setText(QApplication::translate("MainWindow", "psi :", 0));
        ppsiLabel->setText(QApplication::translate("MainWindow", "-", 0));
        resetPosition->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "Reset position:", 0));
        threeDButton->setText(QApplication::translate("MainWindow", "3D", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Video settings", 0));
        label->setText(QApplication::translate("MainWindow", "Source:", 0));
        srcSelect->clear();
        srcSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", 0)
         << QApplication::translate("MainWindow", "Local", 0)
         << QApplication::translate("MainWindow", "TCP", 0)
        );
#ifndef QT_NO_WHATSTHIS
        framesB4Detect->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>rqsdfsfd</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("MainWindow", "Frames before recog:", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Sensor Commands", 0));
        label_6->setText(QApplication::translate("MainWindow", "Measure distance:", 0));
        laserOn->setText(QApplication::translate("MainWindow", "Laser aim", 0));
#ifndef QT_NO_TOOLTIP
        distanceDisplay->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>(centimeters)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        getDistance->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Detection && Confirmation", 0));
        objectDetectedLocationgroupBox->setTitle(QApplication::translate("MainWindow", "Location:", 0));
        label_27->setText(QApplication::translate("MainWindow", "Center:", 0));
        label_28->setText(QApplication::translate("MainWindow", "Radius:", 0));
        label_29->setText(QApplication::translate("MainWindow", "x:", 0));
        label_30->setText(QApplication::translate("MainWindow", "y:", 0));
        label_31->setText(QApplication::translate("MainWindow", "r:", 0));
        xCenterlabel->setText(QApplication::translate("MainWindow", "...", 0));
        yCenterlabel->setText(QApplication::translate("MainWindow", "...", 0));
        radiuslabel->setText(QApplication::translate("MainWindow", "...", 0));
        label_22->setText(QApplication::translate("MainWindow", "Object detected", 0));
        objectDetectedIconlabel->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "Size of the BlackList:", 0));
        detectButton->setText(QApplication::translate("MainWindow", "Detection", 0));
        sizeBlackListlabel->setText(QApplication::translate("MainWindow", "0", 0));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Detection Settings", 0));
        algSelect->clear();
        algSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "<none>", 0)
         << QApplication::translate("MainWindow", "Haar", 0)
         << QApplication::translate("MainWindow", "PCM", 0)
         << QApplication::translate("MainWindow", "SURF", 0)
        );
        label_2->setText(QApplication::translate("MainWindow", "Algorithm:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Object:", 0));
#ifndef QT_NO_TOOLTIP
        helpButton_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Click for help</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        helpButton_2->setText(QString());
        objOkButton->setText(QApplication::translate("MainWindow", "Ok", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Tracker", 0));
        label_25->setText(QApplication::translate("MainWindow", "Algorithm:", 0));
        trackAlgSelect->clear();
        trackAlgSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "<none>", 0)
         << QApplication::translate("MainWindow", "PatternMatching", 0)
         << QApplication::translate("MainWindow", "LucasKannade", 0)
        );
        trackButton->setText(QApplication::translate("MainWindow", "Track", 0));
        label_34->setText(QApplication::translate("MainWindow", "State :", 0));
        trackState->setText(QApplication::translate("MainWindow", "-", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tests", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Add/Remove Objects", 0));
        algDetectSelect->clear();
        algDetectSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "<none>", 0)
         << QApplication::translate("MainWindow", "Haar", 0)
         << QApplication::translate("MainWindow", "PCM", 0)
         << QApplication::translate("MainWindow", "SURF", 0)
        );
        label_26->setText(QApplication::translate("MainWindow", "Detection  Algorithm:", 0));
        label_32->setText(QApplication::translate("MainWindow", "Object:", 0));
        addAlgoObject->setText(QApplication::translate("MainWindow", "+", 0));
        subAlgoObject->setText(QApplication::translate("MainWindow", "-", 0));
        label_35->setText(QApplication::translate("MainWindow", "Tracking Algorithm:", 0));
        algTrackingSelect->clear();
        algTrackingSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "<none>", 0)
         << QApplication::translate("MainWindow", "PCM", 0)
         << QApplication::translate("MainWindow", "SURF", 0)
         << QApplication::translate("MainWindow", "LUCAS KANADE", 0)
        );
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Current State", 0));
        label_33->setText(QApplication::translate("MainWindow", "Info:", 0));
        abortMission->setText(QApplication::translate("MainWindow", "Abort", 0));
        startMission->setText(QApplication::translate("MainWindow", "Start Mission", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Mission", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
