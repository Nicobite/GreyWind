#include "Detection/haarfacedetectionalgo.h"
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
    DEBUG("> Entering detect\t" << CURRENT_TIME);
    Mat frame_gray;

    if(frame.empty()){
        ERROR("[HaarDetect] This frame seems to be empty.");
    } else{

        if(frame.channels()>1){
            cvtColor(frame, frame_gray, COLOR_BGR2GRAY );
        } else{
            frame_gray = frame;
        }

        equalizeHist(frame_gray, frame_gray );
        try{
            //DEBUG("B4 detectMS\t\t" << CURRENT_TIME);
            //m_face_cascade.detectMultiScale( frame_gray, m_faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );  //face
            m_face_cascade.detectMultiScale( frame_gray, m_faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

            //DEBUG("Af detectMS\t\t" << CURRENT_TIME);

            for (size_t i = 0;i < m_faces.size();i++){
                center = Point( m_faces[i].x + m_faces[i].width/2, m_faces[i].y + m_faces[i].height/4 );
                //size = Size( m_faces[i].width/2, m_faces[i].height/2 );
                size = Size( m_faces[i].width/2, m_faces[i].height/2);
                //ellipse( frame, center, Size( m_faces[i].width/2, m_faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
                emit detectedObject(center, size);
            }
        } catch(...){
            ERROR("[HaarDetect] Something wicked somewhere around here.")
        }
    }

}


