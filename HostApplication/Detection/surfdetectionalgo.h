//-- Il faut ajouter les fonctions extra de opencv "opencv-contrib"
//-- git clone https://github.com/Itseez/opencv_contrib
//-- cd <opencv_build_directory>
//-- cmake -DOPENCV_EXTRA_MODULES_PATH=<opencv_contrib>/modules <opencv_source_directory>
//-- make j5

#ifndef HAARFACEDETECTIONALGO_H
#define HAARFACEDETECTIONALGO_H

#include "opencv2/opencv.hpp"
#include "Detection/detectionalgo.h"

class SurfDetectAlgo : public DetectionAlgo
{
private:
    String              m_img_source_name;

public:
    SurfDetectAlgo(String face_cascade_name);
    ~SurfDetectAlgo();

protected:
    void detect(Mat &frame);
};

#endif // HAARFACEDETECTIONALGO_H
