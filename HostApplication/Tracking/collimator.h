#ifndef COLLIMATOR_H
#define COLLIMATOR_H

#include <QThread>
#include <Tracking/pmtrackingalgo.h>
#include <Detection/laserdetect.hpp>
#include "opencv2/opencv.hpp"
#include <queue>

using namespace cv;

class Collimator: public QThread
{
    Q_OBJECT

public:
    explicit Collimator(QObject *parent = 0);
    ~Collimator();

    void init(Mat img, Point point, Size size);
    void run();

    bool isAligned();

private:
    bool m_running;

    std::string m_algoname;

    TrackingAlgo *m_tracker;
    laserDetect m_laser_detector;
    queue<Mat> m_FIFO;

    bool m_aligned;

    void getLaserPosition(Mat frame, bool &visible, Point &point, Size &size);

signals:
    void detectedObject(Point center, Size size);
    void sigMessageToConsole(std::string message);
    void sigDirections(std::string messsage);

public slots:
    void handleFrame(Mat frame);
    void changeAlgo(std::string algoname);

};

#endif // COLLIMATOR_H
