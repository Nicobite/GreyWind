//-- Il faut ajouter les fonctions extra de opencv "opencv-contrib"
//-- git clone https://github.com/Itseez/opencv_contrib
//-- cd <opencv_build_directory>
//-- cmake -DOPENCV_EXTRA_MODULES_PATH=<opencv_contrib>/modules <opencv_source_directory>
//-- make -j5
//-- sudo make install

#ifndef SURFDETECTIONALGO_H
#define SURFDETECTIONALGO_H

#include "opencv2/opencv.hpp"
#include "Detection/detectionalgo.h"

class SurfDetectionAlgo : public DetectionAlgo
{
private:
    String m_base_path;
    String m_img_source_name;

public:
    SurfDetectionAlgo(String img_source);
    ~SurfDetectionAlgo();

protected:
    void detect(Mat &frame);
};

#endif // SURFDETECTIONALGO_H

