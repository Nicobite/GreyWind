#ifndef DETECTTHREAD_H
#define DETECTTHREAD_H

#include <QThread>
#include <queue>
#include "opencv2/opencv.hpp"
#include "includes.h"
#include "haarfacedetectionalgo.h"
#include "pcmdetectionalgo.h"
#include "pmdetectionalgo.h"
#include <QDir>

using namespace cv;

class DetectThread : public QThread
{
    Q_OBJECT
public:
    explicit DetectThread(QObject *parent = 0);
    ~DetectThread();

    void pushMatToFIFO(Mat mat);

private:
    std::string m_algoname;
    std::string m_object2detect;
    DetectionAlgo   *m_algo;
    std::queue<Mat> m_FIFO;
    bool m_running;

    void run();

signals:
    void sigFrameToObject(Mat mat);
    void sigDetectedToControl(Point center, Size size);
    void sigMessageToConsole(std::string message);

public slots:
    void handleDetectedObject(Point center, Size size);
    void changeDetectionAlgo(std::string algoname);
    void changeObject2Detect(std::string objectname);

};

#endif // DETECTTHREAD_H
