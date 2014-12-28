#include "Tracking/pmtrackingalgo.h"

PMTrackingAlgo::PMTrackingAlgo() : TrackingAlgo()
{
    m_status = false;
}

PMTrackingAlgo::~PMTrackingAlgo(){

}

void PMTrackingAlgo::initialise(cv::Mat img, cv::Point point, cv::Size size){
    cv::Rect myROI(point, size);
    img(myROI).copyTo(m_tmpl);

    m_status = true;
    m_coordinate = point;
    m_size = size;
}

void PMTrackingAlgo::track(cv::Mat img){
    cv::Mat result;
    double minVal; double maxVal;
    cv::Point minLoc; cv::Point maxLoc;

    matchTemplate(img, m_tmpl, result, 5);

    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());

    //printf("[ScaleOpt] Found maximum %f at (%i,%i) \n", maxVal, maxLoc.x, maxLoc.y);
    m_coordinate = maxLoc;
}
