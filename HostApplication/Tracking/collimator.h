#ifndef COLLIMATOR_H
#define COLLIMATOR_H

#include <QThread>
#include <Tracking/pmtrackingalgo.h>
#include <Tracking/detectiontrackingalgo.h>
#include <Detection/laserdetect.hpp>
#include "opencv2/opencv.hpp"
#include <queue>
#include "includes.h"

using namespace cv;

class Collimator: public QThread
{
    Q_OBJECT

public:
    explicit Collimator(QObject *parent = 0);
    ~Collimator();

    void init(Mat img, Point point, Size size, std::string detecAlgoName, std::string detectObjName);
    void run();
    void deinit();

    bool isAligned();
    void handleFrame(Mat frame);


private:
    bool m_running;
    bool m_finished;
    bool m_aligned;
    std::string m_algoname;
    TrackingAlgo *m_tracker;
    laserDetect m_laser_detector;
    queue<Mat> m_FIFO;


    void getLaserPosition(Mat frame, bool &visible, Point &point, Size &size);

signals:
    void detectedObject(Point center, Size size);
    void detectedLaser(Point center, Size size);
    void sigMessageToConsole(std::string message);
    void sigDirections(std::string messsage);

public slots:
    void changeAlgo(std::string algoname);

};

#endif // COLLIMATOR_H
