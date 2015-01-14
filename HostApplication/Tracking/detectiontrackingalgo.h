#ifndef DETECTIONTRACKINGALGO_H
#define DETECTIONTRACKINGALGO_H

#include "Detection/detectionalgo.h"
#include "Tracking/trackingalgo.h"
#include <QDir>
#include "Detection/haarfacedetectionalgo.h"
#include "Detection/pcmdetectionalgo.h"

class DetectionTrackingAlgo : public TrackingAlgo
{
private:
    DetectionAlgo   *m_algo;
    std::string m_nomAlgo;
    std::string m_object;

public:
    DetectionTrackingAlgo();
    ~DetectionTrackingAlgo();

    void initialise(cv::Mat img, cv::Point point, cv::Size size, std::string detecAlgoName, std::string detectObjName);
    void track(cv::Mat img);
};

#endif // DETECTIONTRACKINGALGO_H

