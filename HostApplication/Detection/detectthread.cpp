#include "detectthread.h"

DetectThread::DetectThread(QObject *parent) :
    QThread(parent)
{
    //m_algo = new HaarFaceDetectionAlgo("haarcascade_frontalface_alt.xml");
    m_algo = new HaarFaceDetectionAlgo("pyr_cascade_v2.xml");
    // Connecting this and the detection objects
    QObject::connect(this,              SIGNAL(sigFrameToObject(Mat)),
                     m_algo,            SLOT(handleFrame(Mat)));
    QObject::connect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                     this,              SLOT(handleDetectedObject(Point,Size)));
}

void DetectThread::run(){
    //DEBUG("> DetectThread::run()");
    while(1){
        if(!m_FIFO.empty()){
            // Popping element
            emit sigFrameToObject(m_FIFO.front());
            m_FIFO.pop();
            //DEBUG("DetectThread: send+pop DONE");
        }
    }
}

void DetectThread::pushMatToFIFO(Mat mat){
    m_FIFO.push(mat);
    //DEBUG("DectecThread: pushed");
}

void DetectThread::handleDetectedObject(Point center,Size size){
    emit sigDetectedToControl(center, size);
}
