#ifndef PMDETECTIONALGO_H
#define PMDETECTIONALGO_H

#include "opencv2/opencv.hpp"
#include <vector>
#include "Detection/detectionalgo.h"
#include <fstream>

using namespace std;
using namespace cv;

class PMDetectionAlgo : public DetectionAlgo
{
private:
    String m_base_path;
    String m_template_filename;
    int m_lastGoodPattern;
    vector<Mat> m_templates;


public:
    PMDetectionAlgo(String filename);
    ~PMDetectionAlgo();

protected:

    void detect(Mat &frame);
    void loadTemplates();

    void detectPattern(Mat &frame, Mat &templ, Rect &size, Point &pos, float &score);


};

#endif // PMDETECTIONALGO_H
