#ifndef VIDEOTHREAD_HPP
#define VIDEOTHREAD_HPP

#include <QThread>
#include <QColor>
#include <QPainter>
#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

class VideoThread : public QThread
{
    Q_OBJECT
public:
    explicit VideoThread(QObject *parent = 0);
    ~VideoThread();

protected:
     void run();

private:
     bool m_running;
     int m_nbFramesBeforeDetect;
     std::string m_source;
     int openVideo(VideoCapture * capture);

public slots:
    void setSource(std::string src);
    void setDetectionPeriod(int nbFramesBeforeDetect);

signals:
    void sendDetectionFrame(Mat frame);
    void sendVideoFrame(QImage frame);

    void cannotChangeSource(std::string src, int err);
};

#endif // VIDEOTHREAD_HPP
