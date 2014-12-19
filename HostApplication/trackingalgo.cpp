#include "trackingalgo.h"

TrackingAlgo::TrackingAlgo(QObject *parent) :
    QObject(parent)
{
}

cv::Point TrackingAlgo::getCoordinate(){
    return m_coordinate;
}

cv::Size TrackingAlgo::getSize(){
    return m_size;
}

bool TrackingAlgo::getStatus(){
    return m_status;
}
