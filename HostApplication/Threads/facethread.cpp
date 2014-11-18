#include "Includes.h"
#include "facethread.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;


Facethread::Facethread(QObject *parent) :
    QThread(parent)
{
    m_source = "Local";
}


void Facethread::run()
{
    // Initiating needed objects
    VideoCapture capture;
    Mat frame;
    FaceDetection faceDetector(FRAMES_B4_DETECT);

    // First video open
    openVideo(&capture);

    // Saving m_source before 1st iteration
    std::string m_source_old = m_source;

    while ( capture.read(frame) ) { // TODONEXT: Update source quite often
        //DEBUG("beginning of the while...");

        // Checking m_source changes
        if(m_source_old != m_source){
            DEBUG("Source actually changed in the last iteration");
            // then opening a new video stream for next iteration
            capture.release();
            openVideo(&capture);
        }

        // Just a check
        if(frame.empty()){
            ERROR("no captured frame -- Break!");
            break;
        }

        // Send output of algorithm to main window
        dispFrame(faceDetector.detectAndDisplay(frame));

        // Save m_source for later
        m_source_old = m_source;

        //DEBUG("end of the while...");
    }

    capture.release();
    DEBUG("exiting Facethread::run()");
}

int Facethread::openVideo(VideoCapture * capture){
    DEBUG("entering openVideo");
    if (m_source == "Local"){   capture->open(SRC_DEFAULT);  } else
    if (m_source == "TCP")  {   capture->open(SRC_TCP);      }
    if ( !capture->isOpened() ) {
        ERROR("opening video capture, getting back to Local source."); // TODO: Make this a thing :/
        m_source = "Local";
        return -1;
    }
    DEBUG("exiting openVideo with status 0k");
    return 0;
}


//
// Signals/Slots
//

void Facethread::dispFrame(QImage image){
    emit displayedFrame(image);
}

// Deprecated
void Facethread::getSrc(){
    emit sigReqSrc();
}

void Facethread::updateSrc(std::string src){
    m_source = src;
}

