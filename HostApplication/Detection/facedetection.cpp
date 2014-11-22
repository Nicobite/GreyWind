#include "includes.h"
#include "facedetection.hpp"
#include <QApplication>
#include <QPainter>

FaceDetection::FaceDetection()
{
    m_face_cascade_name     =   "haarcascade_frontalface_alt.xml";
    m_window_name           =   "Capture - Face detection";
    m_frameCounter          =   1;
    if( !m_face_cascade.load( m_face_cascade_name ) ){
        ERROR("loading face cascade");
    };
}

FaceDetection::~FaceDetection(){}

QImage FaceDetection::detectAndDisplay(Mat frame){
    //DEBUG("Entering detectAndDisplay");
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    if(m_frameCounter == framesB4Detect){
#if DBG
        //printf("\tframesB4Detect->%d\n",framesB4Detect);
#endif
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

    //QImage image = QImage("/home/nikko/Desktop/screen1.png");
    return image.rgbSwapped(); //Because OpenCV return BGR frames instead of RGB

}

