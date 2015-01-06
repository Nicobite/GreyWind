#include "Tracking/pmtrackingalgo.h"

PMTrackingAlgo::PMTrackingAlgo() : TrackingAlgo()
{
    m_status = false;
}

PMTrackingAlgo::~PMTrackingAlgo(){
    m_status = false;
}

void PMTrackingAlgo::initialise(cv::Mat img, cv::Point point, cv::Size size){
    cv::Size realSize;
    realSize.width = size.width*2;
    realSize.height = size.height*2;
    cv::Point realPoint;
    realPoint.x = point.x - size.width;
    realPoint.y = point.y - size.height;
    cv::Rect myROI(realPoint, realSize);
    img(myROI).copyTo(m_tmpl);
    imshow("Debug", m_tmpl);
    m_status = true;
    m_coordinate = point;
    m_size = realSize;
}

void PMTrackingAlgo::track(cv::Mat img){
    cv::Mat result;
    double minVal; double maxVal;
    cv::Point minLoc; cv::Point maxLoc;

    matchTemplate(img, m_tmpl, result, 5);

    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());

    //printf("[ScaleOpt] Found maximum %f at (%i,%i) \n", maxVal, maxLoc.x, maxLoc.y);
    cv::Point center;
    center.x = maxLoc.x + m_size.width/2;
    center.y = maxLoc.y + m_size.height/2;
    m_coordinate = center;
}
