#ifndef DETECTIONALGO_H
#define DETECTIONALGO_H

#include <QObject>
#include "includes.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

class DetectionAlgo : public QObject
{
    Q_OBJECT
private:

public:
    explicit DetectionAlgo(QObject *parent = 0);
    ~DetectionAlgo();

protected:
    virtual void detect(Mat &frame) = 0;

signals:
    void detectedObject(Point center, Size size);

public slots:
    void handleFrame(Mat frame);
};

#endif // DETECTIONALGO_H
