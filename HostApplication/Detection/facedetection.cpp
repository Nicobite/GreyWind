#include "facedetection.hpp"
#include "mainwindow.h"
#include <QImage>
#include <QApplication>

FaceDetection::FaceDetection(int framesBeforeDetect):
    m_framesBeforeDetect(framesBeforeDetect)
{
    m_face_cascade_name =   "haarcascade_frontalface_alt.xml";
    m_window_name =         "Capture - Face detection";
    m_frameCounter =        1;
    if( !m_face_cascade.load( m_face_cascade_name ) ){
        printf("%s[ERROR] %s%s\n","\033[1;31m","loading face cascade","\033[0m");
    };
}

FaceDetection::~FaceDetection(){}

void FaceDetection::detectAndDisplay(Mat frame){
    //DEBUG("Entering detectAndDisplay");

    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    if(m_frameCounter == m_framesBeforeDetect){
        //-- Detect faces every "framesBeforeDetect" frame
        m_face_cascade.detectMultiScale( frame_gray, m_faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
        m_frameCounter = 0;
    }

        //-- Highlight faces every 1 frame
        for (size_t i = 0;i < m_faces.size();i++){
            Point center( m_faces[i].x + m_faces[i].width/2, m_faces[i].y + m_faces[i].height/2 );
            ellipse( frame, center, Size( m_faces[i].width/2, m_faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
            Mat faceROI = frame_gray( m_faces[i] );
            std::vector<Rect> eyes;
        }

    m_frameCounter++;

    //-- Show what you got
    //imshow( m_window_name, frame );
    QImage image = QImage((const unsigned char*)frame.data,frame.cols,frame.rows,frame.step,QImage::Format_RGB888);
    //w.getView()->updateView(image);
    //TODO CANCER

}

void FaceDetection::set_framesBeforeDetect(int framesBeforeDetect){
    m_framesBeforeDetect = framesBeforeDetect;
}
