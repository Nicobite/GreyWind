/**
 * This is an old version of the detection thread class. It will be later replaced by a more generic and configurable class.
 */

#include "includes.h"
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

Facethread::~Facethread(){
    this->m_running = false;
    this->quit();
    this->wait();
}


void Facethread::run()
{
    // Initiating needed objects
    VideoCapture* capture;
    Mat frame;
    FaceDetection faceDetector;

    // First video open
    capture = new VideoCapture;
    openVideo(capture);

    // Saving m_source before 1st iteration
    std::string m_source_old = m_source;
    m_running = true;

    while (  m_running ) { // TODONEXT: Update source quite often
        //DEBUG("beginning of the while...");
        if(capture->isOpened())
        {
            capture->read(frame);
        } else{
            DEBUG("Source disappeared.");
        }
        // Checking m_source changes
        if(m_source_old != m_source){
            DEBUG("Source actually changed in the last iteration");
            // then opening a new video stream for next iteration
            capture->release();
            //while(capture->isOpened());
            capture->~VideoCapture();
            capture = new VideoCapture;
            openVideo(capture);
        } else{

            // Just a check
            if(frame.empty()){
                ERROR("no captured frame -- Break!");
                break;
            }

            // Send output of algorithm to main window
            dispFrame(faceDetector.detectAndDisplay(frame));
        }
        // Save m_source for later
        m_source_old = m_source;

        //DEBUG("end of the while...");
    }
    DEBUG("just before last realease");
    capture->release();
    delete capture;
    DEBUG("exiting Facethread::run()");
}

int Facethread::openVideo(VideoCapture * capture){
    DEBUG("entering openVideo");
    if (m_source == "Local"){   capture->open(SRC_DEFAULT);  } else
    if (m_source == "TCP")  {   capture->open(SRC_TCP);      }
    if ( !capture->isOpened() ) {
        ERROR("opening video capture, getting back to Local source."); // TODO: Make this a thing :$
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

// @Deprecated
void Facethread::getSrc(){
    emit sigReqSrc();
}

void Facethread::updateSrc(std::string src){
    m_source = src;
}

