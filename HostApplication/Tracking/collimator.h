#ifndef COLLIMATOR_H
#define COLLIMATOR_H

#include <QThread>
#include <Tracking/pmtrackingalgo.h>
#include <Detection/laserdetect.hpp>
#include "opencv2/opencv.hpp"

using namespace cv;

class Collimator: public QThread
{
    Q_OBJECT

public:
    explicit Collimator(Mat img, Point point, Size size, QObject *parent = 0);
    ~Collimator();

    bool isAligned();

private:
    bool m_running;
    std::string m_algoname;

    TrackingAlgo *m_tracker;
    laserDetect m_laser_detector;

    bool m_aligned;

    void run();

signals:
    void detectedObject(Point center, Size size);

public slots:
    void handleFrame(Mat frame);
};

#endif // COLLIMATOR_H
