#include "Includes.h"
#include "facethread.h"
#include "opencv2/opencv.hpp"
#include <iostream>

//#define SOURCE "tcp://@192.168.1.1:5555"
//#define SOURCE 0

using namespace std;
using namespace cv;


Facethread::Facethread(QObject *parent) :
    QThread(parent)
{
    m_source = "Local";
}


void Facethread::run()
{

    VideoCapture capture;
    Mat frame;
    FaceDetection faceDetector(FRAMES_B4_DETECT);

    dispFrame(QImage("/home/nikko/Desktop/screen1.png"));

    //-- 2. Read the video stream
#if DBG
    DEBUG("just before isOpened");
#endif
    if (m_source == "Local")
        capture.open(0);
    else
        capture.open(m_source);

    if ( !capture.isOpened() ) {
        ERROR("opening video capture");
    }

#if DBG
    DEBUG("open seems ok...");
#endif

    while (capture.read(frame) ) { // TODONEXT: Update source quite often

        //m_source = globalSource;

        //getSrc();

#if DBG
        DEBUG(m_source.c_str());
#endif

        if(frame.empty()){
            ERROR("no captured frame -- Break!");
            break;
        }

        //-- 3. Apply the classifier to the frame
        dispFrame(faceDetector.detectAndDisplay(frame));
#if DBG
        //DEBUG("right after detectAndDisplay");
#endif
        //int c = waitKey(10);
        //if( (char)c == 27 ) { break; } // escape
    }
#if DBG
    DEBUG("exiting main");
#endif
    capture.release();
}

void Facethread::dispFrame(QImage image){
    emit displayedFrame(image);
}

void Facethread::getSrc(){
    emit sigReqSrc();
}

void Facethread::updateSrc(std::string src){
    m_source = src;
}

