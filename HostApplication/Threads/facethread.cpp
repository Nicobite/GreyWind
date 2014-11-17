#include "facethread.h"
#include "Includes.h"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


Facethread::Facethread(QObject *parent) :
    QThread(parent)
{
}


void Facethread::run()
{
    const string source = "tcp://@192.168.1.1:5555";
    //const string source = 0;

    VideoCapture capture;
    Mat frame;
    FaceDetection faceDetector(FRAMES_B4_DETECT);

    dispFrame(QImage("/home/nikko/Desktop/screen1.png"));

    //-- 2. Read the video stream
    DEBUG("just before isOpened");
    capture.open(0);

    if ( !capture.isOpened() ) {
        ERROR("opening video capture");
    }

    DEBUG("open seems ok...");

    while (capture.read(frame) ) {
        if(frame.empty()){
            ERROR("no captured frame -- Break!");
            break;
        }

        //-- 3. Apply the classifier to the frame
        dispFrame(faceDetector.detectAndDisplay(frame));

        int c = waitKey(10);
        if( (char)c == 27 ) { break; } // escape
    }
    DEBUG("Exiting main");
    capture.release();
}

void Facethread::dispFrame(QImage image){
    emit displayedFrame(image);
}
