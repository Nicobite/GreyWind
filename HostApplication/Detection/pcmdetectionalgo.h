#ifndef PCMDETECTIONALGO_H
#define PCMDETECTIONALGO_H

#include "opencv2/opencv.hpp"
#include <vector>
#include "Detection/detectionalgo.h"
#include <fstream>

using namespace std;
using namespace cv;

class PCMDetectionAlgo : public DetectionAlgo
{
private:
    String m_pcm_filename;
    String m_template_filename;
    vector<Point> m_contour_template;
    vector<Mat> m_templates;
public:
    PCMDetectionAlgo(String pcm_filename);
    ~PCMDetectionAlgo();

protected:

    void detect(Mat &frame);

    void loadContour(vector<Point>& contour_template, String filename);
    void loadTemplates(vector<Mat>& templates, String filename);

    Rect getAverageShapeSize(Mat& frame, vector<Point>& contour_template, Point& pos);

    void detectPattern(Mat &frame, Mat &templ, Rect &size, Point &pos, float &score);


};

#endif // PCMDETECTIONALGO_H
