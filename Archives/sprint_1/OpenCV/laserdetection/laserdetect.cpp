#include "laserdetect.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"



laserDetect::laserDetect(){
    m_x = 0;
    m_y = 0;
}

laserDetect::laserDetect(float c_x, float c_y)
{
    m_x = c_x;
    m_y = c_y;
}

void laserDetect::createBinaryPhoto(Mat &src, Mat &dest, Scalar rangeInf, Scalar rangeHig){
    inRange(src,rangeInf, rangeHig, dest);
}

void laserDetect::findTheContours(Mat &binaryPhoto, vector<vector<Point> > &contours){
    vector<Vec4i> hierarchy;
    findContours( binaryPhoto, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
}

void laserDetect::contours2Coordinates(vector<vector<Point> > contours){
    float coord_x = 0, coord_y = 0;
    vector<vector<Point> > contours_poly( contours.size() );
    vector<Point2f> center(contours.size());
    vector<float>radius( contours.size() );
    for( int i = 0; i < contours.size(); i++ )
        {
            // Approximates a polygonal curve(s) with the specified precision
            approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
            // Finds a circle of the minimum area enclosing a 2D point set
            minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
        }

    // Finds a center of the contours
    for (int i = 0; i < center.size(); i++){
        coord_x += center[i].x/center.size();
        coord_y += center[i].y/center.size();
    }

    setCoord(coord_x, coord_y);
}

float laserDetect::getX(void){
    return x;}

float laserDetect::getY(void){
    return y;
}

void laserDetect::setCoord(float c_x, float c_y)
{
    m_x = c_x;
    m_y = c_y;
}
