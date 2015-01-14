#include "Detection/detectionalgo.h"

DetectionAlgo::DetectionAlgo(QObject *parent): QObject(parent){

}

DetectionAlgo::~DetectionAlgo(){

}

void DetectionAlgo::handleFrame(Mat frame){
    this->detect(frame);
}

void DetectionAlgo::detectOnFrame(Mat frame){
    this->detect(frame);
}

Point DetectionAlgo::getPoint(){
    return m_point;
}

Size DetectionAlgo::getSize(){
    return m_size;
}
