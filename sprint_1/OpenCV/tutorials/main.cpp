
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

#include "facedetection.hpp"

#define DEBUG(arg) printf("%s[DEBUG] %s%s\n","\033[1;36m",arg,"\033[0m")
#define ERROR(arg) printf("%s[ERROR] %s%s\n","\033[1;31m",arg,"\033[0m")

#define FRAMES_B4_DETECT 50

using namespace std;
using namespace cv;



//TODO: RELEASE LA CONNEXION LOL




/** @function main */
int main( void ){

    const string source = "tcp://@192.168.1.1:5555";
    //const string source = 0;

    VideoCapture capture;
    Mat frame;
    FaceDetection faceDetector(FRAMES_B4_DETECT);

    //-- 2. Read the video stream
    DEBUG("just before isOpened");
    capture.open(source);

    if ( !capture.isOpened() ) {
        ERROR("opening video capture"); return -1;
    }

    DEBUG("open seems ok...");

    while (capture.read(frame) ) {
        if(frame.empty()){
            ERROR("no captured frame -- Break!");
            break;
        }

        //-- 3. Apply the classifier to the frame
        faceDetector.detectAndDisplay(frame);

        int c = waitKey(10);
        if( (char)c == 27 ) { break; } // escape
    }
    DEBUG("Exiting main");
    capture.release();
    return 0;
 }
