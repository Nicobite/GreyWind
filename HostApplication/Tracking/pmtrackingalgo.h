#ifndef PMTRACKINGALGO_H
#define PMTRACKINGALGO_H

#include "Tracking/trackingalgo.h"

class PMTrackingAlgo : public TrackingAlgo
{
private:
    cv::Mat m_tmpl;
public:
    PMTrackingAlgo();
    ~PMTrackingAlgo();

    void initialise(cv::Mat img, cv::Point point, cv::Size size, std::string detecAlgoName, std::string detectObjName);
    void track(cv::Mat img);

};

#endif // PMTRACKINGALGO_H
