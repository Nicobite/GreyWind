#include <iostream>
/*
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
*/

#include "opencv2/opencv.hpp"
#include "laserdetect.hpp"


using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
    float coord_x = 0, coord_y = 0;
    laserDetect laserPhoto;
    String window_name = "Capture - Face detection";

    //----- Detect laser dot from photo -----//

    /* Détection zone rouge */
    Mat image = imread("sample3.jpg");
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
    laserPhoto.findTheContours(imageBinary, contours);


    laserPhoto.contours2Coordinates(contours);

    // Draw a circle with the laser as the center
    circle(image,Point(laserPhoto.getX(),laserPhoto.getY()), 100,Scalar(255,0,255),1,LINE_8,0);
    imwrite("out2.png", image);

    printf("Image Size X : %d, Y : %d \n", image.size().height, image.size().width);
    printf("Coordonnees X : %f, Y : %f \n", laserPhoto.getX(), laserPhoto.getY());
    cout << "Hello World!" << endl;

    //------ Detect laser dot from video ----//

    VideoCapture capture;
    Mat frame;
    Mat binaryFrame;

    vector<vector<Point> > contour;

    laserDetect laserVideo;
    capture.open( 0 );
    if ( !capture.isOpened() ) { printf("--(!)Error opening video capture\n"); return -1; }
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            printf(" --(!) No captured frame -- Break!");
            break;
        }
        //-- 3. Apply the classifier to the frame
       laserVideo.createBinaryPhoto(frame, binaryFrame, rangeInf, rangeHig);

       laserVideo.findTheContours(binaryFrame, contour);
       laserVideo.contours2Coordinates(contour);
       circle(frame,Point(laserVideo.getX(),laserVideo.getY()), 100,Scalar(255,0,255),1,LINE_8,0);
        imshow( window_name, frame );
        int c = waitKey(10);
        if( (char)c == 27 ) { break; } // escape
    }

    return 0;
}

