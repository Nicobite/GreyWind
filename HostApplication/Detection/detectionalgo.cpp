#include "detectionalgo.h"

DetectionAlgo::DetectionAlgo(QObject *parent): QObject(parent){

}

DetectionAlgo::~DetectionAlgo(){

}

void DetectionAlgo::handleFrame(Mat frame){
    this->detect(frame);
}
