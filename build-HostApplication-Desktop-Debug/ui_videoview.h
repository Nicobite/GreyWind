/********************************************************************************
** Form generated from reading UI file 'videoview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOVIEW_H
#define UI_VIDEOVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoView
{
public:
    QLabel *videoLabel;
    QLabel *drawLabel;

    void setupUi(QWidget *VideoView)
    {
        if (VideoView->objectName().isEmpty())
            VideoView->setObjectName(QStringLiteral("VideoView"));
        VideoView->resize(640, 360);
        VideoView->setMinimumSize(QSize(640, 360));
        VideoView->setMaximumSize(QSize(1280, 720));
        videoLabel = new QLabel(VideoView);
        videoLabel->setObjectName(QStringLiteral("videoLabel"));
        videoLabel->setGeometry(QRect(0, 0, 640, 360));
        videoLabel->setMinimumSize(QSize(640, 360));
        videoLabel->setMaximumSize(QSize(640, 360));
        drawLabel = new QLabel(VideoView);
        drawLabel->setObjectName(QStringLiteral("drawLabel"));
        drawLabel->setGeometry(QRect(0, 0, 640, 360));
        drawLabel->setMinimumSize(QSize(640, 360));
        drawLabel->setMaximumSize(QSize(640, 360));

        retranslateUi(VideoView);

        QMetaObject::connectSlotsByName(VideoView);
    } // setupUi

    void retranslateUi(QWidget *VideoView)
    {
        VideoView->setWindowTitle(QApplication::translate("VideoView", "Form", 0));
        videoLabel->setText(QApplication::translate("VideoView", "This is a slylish black background for the video frame", 0));
        drawLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoView: public Ui_VideoView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOVIEW_H
