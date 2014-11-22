#ifndef FACEDETECTION_HPP
#define FACEDETECTION_HPP

#include <QObject>
#include <QImage>

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
public:
    FaceDetection();
    ~FaceDetection();
    QImage detectAndDisplay(Mat frame);
public slots:

signals:

};

#endif // FACEDETECTION_HPP
