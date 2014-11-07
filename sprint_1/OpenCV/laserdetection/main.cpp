#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "laserdetect.hpp"


using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
    float coord_x = 0, coord_y = 0;
    laserDetect laserCoord;
    /* Détection zone rouge */
    Mat image = imread("sample2.jpg");
    if (image.empty())
    {
        std::cout << "!!! Failed imread()" << std::endl;
        return -1;
    }

    Mat imageBinary;
    Scalar rangeInf(255, 186, 210);
    Scalar rangeHig(255, 255, 255);
    laserCoord.createBinaryPhoto(image, imageBinary, rangeInf, rangeHig);


    vector<vector<Point> > contours;
    laserCoord.findTheContours(imageBinary, contours);


    laserCoord.contours2Coordinates(contours);

    // Draw a circle with the laser as the center
    circle(image,Point(laserCoord.getX(),laserCoord.getY()), 100,Scalar(255,0,255),1,LINE_8,0);
    imwrite("out2.png", image);

    printf("Image Size X : %d, Y : %d \n", image.size().height, image.size().width);
    printf("Coordonnees X : %f, Y : %f \n", laserCoord.getX(), laserCoord.getY());
    cout << "Hello World!" << endl;
    return 0;
}

