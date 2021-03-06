#ifndef LASERDETECT_HPP
#define LASERDETECT_HPP
#include <opencv2/core.hpp>
/*
    LASER POINT DETECTION LIBRARY
    The library containes functions to help to detect a red dot laser.
        - Detect what part of the photo contain the red dot laser
        - Transfer the photo to a binary photo (the part containes the red dot laser as '1' and the rest as '0')
        - Find the red dot's contour from the binary photo
        - Calculate the center of the contour and return the point's coordinates
    Le range pour le laser rouge : High(255,255,255) - Inf(0,0,255)
*/

using namespace cv;
using namespace std;

class laserDetect
{
public:
    laserDetect();
    laserDetect(float c_x, float c_y);

    float getX(void);
    float getY(void);
    float getR(void);

    void createBinaryPhoto (Mat &src, Mat &dest, Scalar rangeInf, Scalar rangeHig);
    void createBinaryPhotoHSV (Mat &src, Mat &dest, Scalar rangeInf, Scalar rangeHig);
    void findTheContours (Mat &binaryPhoto, vector<vector<Point> > &contours);
    void contours2Coordinates(vector<vector<Point>  > contours);
    void bestcontours2Coordinates(vector<vector<Point>  > contours);

private:
    float m_x;
    float m_y;
    float m_r;
    void setCoord(float c_x, float c_y);

    vector<Point> m_laserContour;
};

#endif // LASERDETECT_HPP
