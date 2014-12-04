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
    VideoView *theFrame;
    QTabWidget *mainTabWidget;
    QWidget *tab;
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
    QFrame *line_3;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QCheckBox *laserOn;
    QLCDNumber *distanceDisplay;
    QPushButton *getDistance;
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
        gridLayoutWidget->setGeometry(QRect(10, 120, 231, 203));
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
        line_6->setGeometry(QRect(0, 330, 250, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        helpButton = new QPushButton(groupBox_3);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        helpButton->setGeometry(QRect(150, 50, 45, 30));
        helpButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/HostApplication/ressources/Help-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpButton->setIcon(icon);
        helpButton->setIconSize(QSize(24, 24));
        verticalLayoutWidget = new QWidget(groupBox_3);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 370, 231, 227));
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
        label_12->setGeometry(QRect(0, 340, 120, 25));
        label_12->setFont(font1);
        line_7 = new QFrame(groupBox_3);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(0, 600, 250, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(0, 610, 150, 25));
        label_15->setFont(font1);
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(9, 630, 231, 96));
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

        theFrame = new VideoView(centralWidget);
        theFrame->setObjectName(QStringLiteral("theFrame"));
        theFrame->setGeometry(QRect(270, 10, 640, 360));
        theFrame->setMinimumSize(QSize(640, 360));
        theFrame->setMaximumSize(QSize(1280, 720));
        mainTabWidget = new QTabWidget(centralWidget);
        mainTabWidget->setObjectName(QStringLiteral("mainTabWidget"));
        mainTabWidget->setGeometry(QRect(460, 380, 451, 291));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 181, 261));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 67, 17));
        srcSelect = new QComboBox(groupBox);
        srcSelect->setObjectName(QStringLiteral("srcSelect"));
        srcSelect->setGeometry(QRect(40, 40, 70, 27));
        srcSelect->setFocusPolicy(Qt::NoFocus);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 170, 51, 17));
        algSelect = new QComboBox(groupBox);
        algSelect->setObjectName(QStringLiteral("algSelect"));
        algSelect->setGeometry(QRect(40, 90, 91, 27));
        algSelect->setFocusPolicy(Qt::NoFocus);
        framesB4Detect = new QDoubleSpinBox(groupBox);
        framesB4Detect->setObjectName(QStringLiteral("framesB4Detect"));
        framesB4Detect->setGeometry(QRect(40, 140, 71, 27));
        framesB4Detect->setFocusPolicy(Qt::ClickFocus);
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
        face->setFocusPolicy(Qt::NoFocus);
        banana = new QCheckBox(tasksCheckboxes);
        banana->setObjectName(QStringLiteral("banana"));
        banana->setGeometry(QRect(10, 50, 97, 22));
        banana->setFocusPolicy(Qt::NoFocus);
        pyramid = new QCheckBox(tasksCheckboxes);
        pyramid->setObjectName(QStringLiteral("pyramid"));
        pyramid->setGeometry(QRect(10, 30, 97, 22));
        pyramid->setFocusPolicy(Qt::NoFocus);
        line_3 = new QFrame(tab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(220, 10, 20, 241));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        mainTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        mainTabWidget->addTab(tab_2, QString());
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(270, 380, 181, 261));
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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/HostApplication/ressources/system-software-update.png"), QSize(), QIcon::Normal, QIcon::Off);
        getDistance->setIcon(icon1);
        getDistance->setIconSize(QSize(24, 24));
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

        mainTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        cuteConsole->setPlainText(QApplication::translate("MainWindow", "Welcome to GreyWind's host application!", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Drone Communication", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_5->setText(QApplication::translate("MainWindow", "Connection Status :", 0));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "Video settings", 0));
        label->setText(QApplication::translate("MainWindow", "Source:", 0));
        srcSelect->clear();
        srcSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", 0)
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
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Main", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tests", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Commands", 0));
        label_6->setText(QApplication::translate("MainWindow", "Measure distance:", 0));
        laserOn->setText(QApplication::translate("MainWindow", "Laser aim", 0));
#ifndef QT_NO_TOOLTIP
        distanceDisplay->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>(centimeters)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        getDistance->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
