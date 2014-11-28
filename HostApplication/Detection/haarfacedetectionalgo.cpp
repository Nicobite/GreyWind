#include "haarfacedetectionalgo.h"
#include "opencv2/opencv.hpp"

HaarFaceDetectionAlgo::HaarFaceDetectionAlgo(String face_cascade_name): DetectionAlgo()
{
    m_face_cascade_name = face_cascade_name;
    //m_face_cascade_name     =   "haarcascade_frontalface_alt.xml";
    //m_face_cascade_name     =   "cascade_pyramide.xml";
    //m_face_cascade_name     =   "banana_classifier.xml";
    if( !m_face_cascade.load( m_face_cascade_name ) ){
        ERROR("[HaarFaceDetectionAlgo]: loading face cascade");
    };
}


HaarFaceDetectionAlgo::~HaarFaceDetectionAlgo()
{
}

void HaarFaceDetectionAlgo::detect(Mat &frame)
{
    Point center;
    Size size;
    //DEBUG("Entering detectAndDisplay");
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist(frame_gray, frame_gray );

    m_face_cascade.detectMultiScale( frame_gray, m_faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

    for (size_t i = 0;i < m_faces.size();i++){
        center = Point( m_faces[i].x + m_faces[i].width/2, m_faces[i].y + m_faces[i].height/2 );
        size = Size( m_faces[i].width/2, m_faces[i].height/2 );
        //ellipse( frame, center, Size( m_faces[i].width/2, m_faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

        emit detectedObject(center, size);
    }
}


