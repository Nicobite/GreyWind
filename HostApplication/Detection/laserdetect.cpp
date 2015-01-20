#include "laserdetect.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <fstream>
#include <iostream>


laserDetect::laserDetect(){
    m_x = 0;
    m_y = 0;

    ifstream inputFile;
    inputFile.open("laser.pcm");
    if(inputFile.is_open()){
        int size;
        inputFile >> size;
        for(int i=0; i<size ;i++){
            int x,y;
            inputFile >> x >> y;
            Point pt(x,y);
            m_laserContour.push_back(pt);
        }

        inputFile.close();
    }
}

laserDetect::laserDetect(float c_x, float c_y){
    m_x = c_x;
    m_y = c_y;
}

void laserDetect::createBinaryPhoto(Mat &src, Mat &dest, Scalar rangeInf, Scalar rangeHig){
    inRange(src,rangeInf, rangeHig, dest);
}

void laserDetect::createBinaryPhotoHSV(Mat &src, Mat &dest, Scalar rangeInf, Scalar rangeHig){
    Mat hsv;
    cv::cvtColor(src, hsv, COLOR_BGR2HSV);
    inRange(src,rangeInf, rangeHig, dest);
}

void laserDetect::findTheContours(Mat &binaryPhoto, vector<vector<Point> > &contours){
    vector<Vec4i> hierarchy;
    findContours( binaryPhoto, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
}


void laserDetect::contours2Coordinates(vector<vector<Point> > contours){
    float coord_x = 0, coord_y = 0, dot_radius=0;
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
        dot_radius += radius[i]/radius.size();
    }

    setCoord(coord_x, coord_y);
    m_r = dot_radius;
}

void laserDetect::bestcontours2Coordinates(vector<vector<Point>  > contours){
    int bestIndex=-1;
    float indexScore=1.0;

    for(unsigned int i=0; i<contours.size(); i++){
        float res = matchShapes(m_laserContour, contours[i], 1 , 0.0);
        if(res > 0.5 || arcLength(contours[i], false)<15){
            //nop
        } else{
            std::cout << "BestContour : "<< res << " " << arcLength(contours[i], false) << " " << contourArea(contours[i]) << endl;

            float radius=0;
            Point2f center;
            minEnclosingCircle( (Mat)contours[i], center, radius );

            if(res< indexScore && (center.x >= 330) && (center.x <= 370) &&
              (center.y >= 240) && (center.y <= 280)){
                indexScore = res;
                bestIndex = i;
            }
        }
    }
    if( bestIndex != -1){
        float radius=0;
        Point2f center;
        minEnclosingCircle( (Mat)contours[bestIndex], center, radius );
        setCoord(center.x, center.y);
        m_r = radius;
    } else{
        setCoord(0, 0);
        m_r = 0;
    }

}


float laserDetect::getX(void){
    return m_x;
}

float laserDetect::getY(void){
    return m_y;
}

float laserDetect::getR(void){
    return m_r;
}

void laserDetect::setCoord(float c_x, float c_y)
{
    m_x = c_x;
    m_y = c_y;
}



/***Pour stocker le contour laser
 * /*    laserDetect laser_detector;

    Mat frame = imread("laser.jpg");
    Mat binFrame;
    vector<vector<Point> > contours;
    laser_detector.createBinaryPhoto(frame, binFrame, Scalar(0,0,225), Scalar(255,255,255));
    //m_laser_detector.createBinaryPhotoHSV(frame, binFrame, Scalar(200,115,150), Scalar(255,255,255));
    Mat dummy;
    frame.copyTo(dummy);
    imshow("Debug", binFrame);
    laser_detector.findTheContours(binFrame, contours);


    drawContours(dummy, contours, 0, Scalar(0,255,0),2);
    imshow("Debug 2", dummy);

    std::cout << contours[0].size() << " ";
    for(unsigned int i=0; i<contours[0].size(); i++){
         std::cout << contours[0].at(i).x << " " << contours[0].at(i).y << " ";
    }


    while(1){
        int c = waitKey(10);
        if( (char)c == 27 ) { break; } // escape
    }
*/
