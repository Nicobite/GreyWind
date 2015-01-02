#ifndef HAARFACEDETECTIONALGO_H
#define HAARFACEDETECTIONALGO_H

#include "opencv2/opencv.hpp"
#include "Detection/detectionalgo.h"

class HaarFaceDetectionAlgo : public DetectionAlgo
{
private:
    String m_base_path;
    String              m_face_cascade_name;
    CascadeClassifier   m_face_cascade;
    std::vector<Rect>   m_faces;

public:
    HaarFaceDetectionAlgo(String face_cascade_name);
    ~HaarFaceDetectionAlgo();

protected:
    void detect(Mat &frame);
};

#endif // HAARFACEDETECTIONALGO_H
