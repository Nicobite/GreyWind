#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

int main()
{
    float coord_x = 0, coord_y = 0;

    /* Détection zone rouge */
    Mat image = imread("samples.jpg");
    if (image.empty())
    {
        std::cout << "!!! Failed imread()" << std::endl;
        return -1;
    }

    Mat red_image;
    inRange(image, Scalar(40, 0, 180), Scalar(135, 110, 255), red_image);
    imwrite("output.jpg ", red_image);

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( red_image, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );

    /* Contour de la zone rouge */
    vector<vector<Point> > contours_poly( contours.size() );
    vector<Rect> boundRect( contours.size() );
    vector<Point2f> center(contours.size());
      vector<float>radius( contours.size() );
    for( int i = 0; i < contours.size(); i++ )
        {
            approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
            boundRect[i] = boundingRect( Mat(contours_poly[i]) );
            minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
        }

    Mat tmp = Mat::zeros( red_image.size(), CV_8UC3 );
    for( int i = 0; i< contours.size(); i++ )
    {
      rectangle( tmp, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 2, 8, 0 );
      circle(tmp,center[i],10,Scalar(255,255,255),1,LINE_8,0);
    }

    imwrite("out2.png", tmp);

    /* Renvoie de coordonnées */
    vector<Point> rect_points;
    for( int i = 0; i < contours.size(); i++ )
    {
        rect_points.push_back(boundRect[i].tl());
        rect_points.push_back(boundRect[i].br());
    }
    printf("Image Size X : %f, Y : %f \n", image.size().height, image.size().width);
    printf("Coordonnees X : %f, Y : %f \n", coord_x/rect_points.size(), coord_y/rect_points.size());
    cout << "Hello World!" << endl;
    return 0;
}

