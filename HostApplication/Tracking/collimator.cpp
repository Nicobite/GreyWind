#include "collimator.h"

Collimator::Collimator(Mat img, Point point, Size size, QObject *parent):
    QThread(parent)
{
    m_running = true;
}

Collimator::~Collimator()
{
    m_running = false;
}

void Collimator::run(){
    while(m_running){

    }
}

void Collimator::handleFrame(Mat frame){

}
