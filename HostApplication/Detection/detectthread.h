#ifndef DETECTTHREAD_H
#define DETECTTHREAD_H

#include <QThread>
#include <queue>
#include "opencv2/opencv.hpp"
#include "includes.h"
#include "haarfacedetectionalgo.h"

using namespace cv;

class DetectThread : public QThread
{
    Q_OBJECT
public:
    explicit DetectThread(QObject *parent = 0);
    ~DetectThread();

    void pushMatToFIFO(Mat mat);

private:
    DetectionAlgo   *m_algo;
    std::queue<Mat> m_FIFO;

    void run();

signals:
    void sigFrameToObject(Mat mat);
    void sigDetectedToControl(Point center, Size size);

public slots:
    void handleDetectedObject(Point center, Size size);

};

#endif // DETECTTHREAD_H
