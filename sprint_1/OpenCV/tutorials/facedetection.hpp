#ifndef FACEDETECTION_HPP
#define FACEDETECTION_HPP

#include "opencv2/opencv.hpp"

using namespace cv;

class FaceDetection
{
private:
    String              m_face_cascade_name;
    String              m_window_name;
    CascadeClassifier   m_face_cascade;
    std::vector<Rect>   m_faces;
    int                 m_frameCounter;
    int                 m_framesBeforeDetect;
public:
    FaceDetection(int framesBeforeDetect=30);
    ~FaceDetection();
    void detectAndDisplay(Mat frame);
    void set_framesBeforeDetect(int framesBeforeDetect);
};

#endif // FACEDETECTION_HPP
