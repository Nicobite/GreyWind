#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>

#define DEBUG(arg) printf("%s[DEBUG] %s%s\n","\033[1;36m",arg,"\033[0m")
#define ERROR(arg) printf("%s[ERROR] %s%s\n","\033[1;31m",arg,"\033[0m")

#define CONTOUR_APPROX_MODE CHAIN_APPROX_TC89_L1

#define SHOW_DEBUG 1

using namespace std;
using namespace cv;

void help();
void detectContours(Mat templ);
void saveTemplateContour(Mat templ, int id, std::string filename);
void loadTemplateContour(vector<Point> &contourTempl, std::string filename);
void detectBestContoursAndDisp(Mat &frame, vector<Point> &contourTempl);
Rect getAverageShapeSize(Mat &frame, vector<Point> &contourTempl, Point &pos);
void detectPatternAndDisplay(Mat &frame, Mat &templ, Rect size);
void detectPattern(Mat &frame, Mat &templ, Rect size, Point &pos, float &score);

void loadTemplates(vector<Mat>& templates, std::string filename);

int main(int argc, char** argv )
{
    if(argc>1){

        switch(argv[1][0]){
        case 'c':
            //see contours of a template
            if(argc > 2){
                Mat templ = imread(argv[2],1);
                detectContours(templ);
            } else{
                printf("Not enough arguments for contour display.\n");
                exit(-1);
            }
            break;
        case 's':
            // save a contour
            if(argc > 4){
                Mat templ = imread(argv[2],1);
                int contour_id = atoi(argv[3]);
                saveTemplateContour(templ, contour_id, argv[4]);
            } else{
                printf("Not enough arguments for saving contour.\n");
                exit(-1);
            }
            break;
        case 't':
            //test with a pcm file
            if(argc > 2){
                vector<Point> contourTempl;
                loadTemplateContour(contourTempl, argv[2]);

                VideoCapture capture;
                Mat frame;
                capture.open(0);

                if ( !capture.isOpened() ) {
                    ERROR("opening video capture"); return -1;
                }{
                    DEBUG("open seems ok...");

                    while (capture.read(frame) ) {
                        if(frame.empty()){
                            ERROR("no captured frame -- Break!");
                            break;
                        }else{

                          detectBestContoursAndDisp(frame, contourTempl);

                          int c = waitKey(10);
                          if( (char)c == 27 ) { break; } // escape
                      }
                  }
                  DEBUG("Exiting main");
                  capture.release();
                  return 0;
                }

            } else{
                printf("Not enough arguments for contour detection test.\n");
                exit(-1);
            }
            break;
        case 'p':
            //test with a pcm file & pattern matching
            if(argc > 3){
                vector<Point> contourTempl;
                loadTemplateContour(contourTempl, argv[2]);
                Mat templ = imread(argv[3],1);
                Point position_contour;

                VideoCapture capture;
                Mat frame;
                capture.open(0);

                if ( !capture.isOpened() ) {
                    ERROR("opening video capture"); return -1;
                }{
                    DEBUG("open seems ok...");

                    while (capture.read(frame) ) {
                        if(frame.empty()){
                            ERROR("no captured frame -- Break!");
                            break;
                        }else{
                          Mat mask; Mat tempTempl;
                          templ.copyTo(tempTempl);
                          Scalar avg = mean(frame);
                          inRange(tempTempl, Scalar::all(0), Scalar::all(25), mask);
                          imshow("Test mask", mask);
                          floodFill(tempTempl, Point(0,0), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
                          floodFill(tempTempl, Point(tempTempl.cols-1,0), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
                          floodFill(tempTempl, Point(0,tempTempl.rows-1), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
                          floodFill(tempTempl, Point(tempTempl.cols-1,tempTempl.rows-1), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);

                          imshow("Test", tempTempl);
                          detectPatternAndDisplay(frame, tempTempl,                 getAverageShapeSize(frame, contourTempl, position_contour));

                          int c = waitKey(10);
                          if( (char)c == 27 ) { break; } // escape
                      }
                  }
                  DEBUG("Exiting main");
                  capture.release();
                  return 0;
                }

            } else{
                printf("Not enough arguments for pattern&contour matching.\n");
                exit(-1);
            }
        case 'm':
            //test with a pcm file & pattern matching
            if(argc > 3){
                vector<Point> contourTempl;
                loadTemplateContour(contourTempl, argv[2]);
                vector<Mat> templates;
                loadTemplates(templates, argv[3]);
                Point position_contour;

                VideoCapture capture;
                Mat frame;
                capture.open(0);

                if ( !capture.isOpened() ) {
                    ERROR("opening video capture"); return -1;
                }{
                    DEBUG("open seems ok...");

                    while (capture.read(frame) ) {
                        if(frame.empty()){
                            ERROR("no captured frame -- Break!");
                            break;
                        }else{

                            int iter=0;
                            bool found=false;

                            Scalar avg = mean(frame);
                            Rect size = getAverageShapeSize(frame, contourTempl, position_contour);

                            while(!found){
                              Mat tempTempl;
                              templates[iter].copyTo(tempTempl);

                              floodFill(tempTempl, Point(0,0), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
                              floodFill(tempTempl, Point(tempTempl.cols-1,0), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
                              floodFill(tempTempl, Point(0,tempTempl.rows-1), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
                              floodFill(tempTempl, Point(tempTempl.cols-1,tempTempl.rows-1), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
                              //imshow("Test", tempTempl);

                              Point match_pos;
                              float match_score;
                              detectPattern(frame, tempTempl, size, match_pos, match_score);

                              if(norm(Mat(match_pos), Mat(position_contour))<=30){
                                  found = true;
                                  rectangle( frame, match_pos, Point( match_pos.x + size.width , match_pos.y + size.height), Scalar(0,255,0), 2, 8, 0 );
                                  imshow( "Pattern Matching", frame );


                              } else{
                                  imshow( "Pattern Matching", frame );

                                  if(iter < templates.size()-1){
                                      iter++;
                                  } else{
                                      found = true;
                                  }
                              }

                          }


                          int c = waitKey(10);
                          if( (char)c == 27 ) { break; } // escape
                      }
                  }
                  DEBUG("Exiting main");
                  capture.release();
                  return 0;
                }

            } else{
                printf("Not enough arguments for pattern&contour matching.\n");
                exit(-1);
            }
        default:
            printf("Error: inexistant argument.\n");
        case 'h':
            //help menu
            help();
            break;
        }

    } else{
        printf("Error: No argument.\n");
        help();
        exit(-1);
    }
}


void help(){
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~ Help Menu ~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    cout << " h : Displays this menu." << endl;
    cout << " c image_path : Show all contours of an image with id numbers." << endl;
    cout << " s image_path contour_id pcm_file : Save selected contour at the end of the pcm_file." << endl;
    cout << " t pcm_file : Test contour detection with contours of the pcm_file." << endl;
    cout << " p pcm_file template_img : Test pattern & contour matching detection." << endl;
    cout << " m pcm_file template_img : Test pattern & contour matching detection with intelligence." << endl;
}


void detectContours(Mat templ){
    vector<vector<Point> > contoursTempl;
    vector<Vec4i> hierarchyTempl;

    Mat im_gray, im_edges;

    cvtColor(templ, im_gray, COLOR_BGR2GRAY);
    blur( im_gray, im_gray, Size(3,3) );
    Canny(im_gray, im_edges, 45, 3*45, 3);
    blur( im_edges, im_edges, Size(3,3) );
    threshold(im_edges, im_edges, 25, 255, THRESH_BINARY_INV);
    GaussianBlur( im_edges, im_edges, Size(7,7), 3);
    threshold(im_edges, im_edges, 200, 255, THRESH_BINARY_INV);
    imshow("Contours", im_edges);

    findContours( im_edges, contoursTempl, hierarchyTempl, RETR_LIST, CONTOUR_APPROX_MODE, Point(0, 0) );

    printf("\nFound %i contours!\n", contoursTempl.size());

    for(unsigned int i=0; i < contoursTempl.size(); i++){
        char title[50];
        sprintf(title, "Source Image Contour n°%i", i);
        printf("Contour no %i, arc length = %f, area = %f! \n", i, arcLength(contoursTempl[i], false), contourArea(contoursTempl[i]));
        Mat drawedge;
        templ.copyTo(drawedge);
        drawContours(drawedge, contoursTempl, i, Scalar(0,255,0), 2);
        imshow(title, drawedge);
    }

    while(1){
        int c = waitKey(10);
        if( (char)c == 27 ) { break; } // escape
    }
}


void loadTemplates(vector<Mat>& templates, std::string filename){
    ifstream inputFile;
    inputFile.open(filename.c_str());
    if(inputFile.is_open()){
        int size;
        inputFile >> size;
        for(int i=0; i<size ;i++){
            std::string templ_fd;
            inputFile >> templ_fd;
            templates.push_back(imread(templ_fd,1));
        }

        inputFile.close();
        printf("Template loaded.\n");
    } else{
        printf("Template load failed.\n");
    }
}


void saveTemplateContour(Mat templ, int id, std::string filename){
    vector<vector<Point> > contoursTempl;
    vector<Vec4i> hierarchyTempl;

    Mat im_gray, im_edges;

    cvtColor(templ, im_gray, COLOR_BGR2GRAY);
    blur( im_gray, im_gray, Size(3,3) );
    Canny(im_gray, im_edges, 45, 3*45, 3);
    blur( im_edges, im_edges, Size(3,3) );
    threshold(im_edges, im_edges, 25, 255, THRESH_BINARY_INV);
    GaussianBlur( im_edges, im_edges, Size(7,7), 3);
    threshold(im_edges, im_edges, 200, 255, THRESH_BINARY_INV);
    imshow("Contours", im_edges);

    findContours( im_edges, contoursTempl, hierarchyTempl, RETR_LIST, CONTOUR_APPROX_MODE, Point(0, 0) );

    ofstream outputFile;
    outputFile.open(filename.c_str());
    if(outputFile.is_open()){
        outputFile << contoursTempl[id].size() << " ";
        for(unsigned int i=0; i<contoursTempl[id].size(); i++){
            outputFile << contoursTempl[id].at(i).x << " " << contoursTempl[id].at(i).y << " ";
        }

        outputFile.close();
        printf("Saved.\n");
    }else{
        printf("Save failed.\n");
    }
}

void loadTemplateContour(vector<Point> &contourTempl, std::string filename){
    ifstream inputFile;
    inputFile.open(filename.c_str());
    if(inputFile.is_open()){
        int size;
        inputFile >> size;
        for(int i=0; i<size ;i++){
            int x,y;
            inputFile >> x >> y;
            Point pt(x,y);
            contourTempl.push_back(pt);
        }

        inputFile.close();
        printf("Loaded.\n");
    } else{
        printf("Load failed.\n");
    }
}



void detectBestContoursAndDisp(Mat &frame, vector<Point> &contourTempl){
    vector<vector<Point> > contoursTempl;
    vector<Vec4i> hierarchyTempl;
    Mat im_gray, im_edges;
    Mat drawedge;

    cvtColor(frame, im_gray, COLOR_BGR2GRAY);
    blur( im_gray, im_gray, Size(3,3) );
    Canny(im_gray, im_edges, 45, 3*45, 3);
    blur( im_edges, im_edges, Size(3,3) );
    threshold(im_edges, im_edges, 25, 255, THRESH_BINARY_INV);
    GaussianBlur( im_edges, im_edges, Size(7,7), 3);
    threshold(im_edges, im_edges, 200, 255, THRESH_BINARY_INV);
    imshow("Contours", im_edges);
    findContours( im_edges, contoursTempl, hierarchyTempl, RETR_LIST, CONTOUR_APPROX_MODE, Point(0, 0) );

    int bestIndex=-1;
    float indexScore=1.0;

    for(unsigned int i=0; i<contoursTempl.size(); i++){
        float res = matchShapes(contourTempl, contoursTempl[i], 1 , 0.0);

        if(res > 0.2 || arcLength(contoursTempl[i], false)<100 || contourArea(contoursTempl[i])<1000){

        } else{
            if(res< indexScore){
                indexScore = res;
                bestIndex = i;
            }
        }
    }

    if(bestIndex != -1){
        char title[50];
        frame.copyTo(drawedge);
        drawContours(drawedge, contoursTempl, bestIndex, Scalar(0,255,0), 2);
        printf("Match result: %f\n", indexScore);
        sprintf(title, "Source Image");
        imshow(title, drawedge);
    }
}


Rect getAverageShapeSize(Mat &frame, vector<Point> &contourTempl, Point &pos){

    static float height=boundingRect(contourTempl).height, width=boundingRect(contourTempl).width;


    vector<vector<Point> > contoursTempl;
    vector<Vec4i> hierarchyTempl;
    Mat im_gray, im_edges;
    Mat drawedge;

    cvtColor(frame, im_gray, COLOR_BGR2GRAY);
    blur( im_gray, im_gray, Size(3,3) );
    Canny(im_gray, im_edges, 35, 3*35, 3);
    blur( im_edges, im_edges, Size(3,3) );
    threshold(im_edges, im_edges, 35, 255, THRESH_BINARY_INV);
    GaussianBlur( im_edges, im_edges, Size(7,7), 3);
    threshold(im_edges, im_edges, 200, 255, THRESH_BINARY_INV);

#if SHOW_DEBUG==1
    imshow("Contours", im_edges);
#endif
    findContours( im_edges, contoursTempl, hierarchyTempl, RETR_LIST, CONTOUR_APPROX_MODE, Point(0, 0) );

    int bestIndex=-1;
    float indexScore=1.0;

    for(unsigned int i=0; i<contoursTempl.size(); i++){
        float res = matchShapes(contourTempl, contoursTempl[i], 1 , 0.0);

        if(res > 0.8 || arcLength(contoursTempl[i], false)<100 || contourArea(contoursTempl[i])<1000){

        } else{
            if(res< indexScore){
                indexScore = res;
                bestIndex = i;
            }
        }
    }

    if(bestIndex != -1){
        char title[50];
        frame.copyTo(drawedge);
        drawContours(drawedge, contoursTempl, bestIndex, Scalar(0,255,0), 2);
        sprintf(title, "Source Image");
#if SHOW_DEBUG==1
        imshow(title, drawedge);
#endif


        height=0.95*height + 0.05*boundingRect(contoursTempl[bestIndex]).height;
        width=0.95*width + 0.05*boundingRect(contoursTempl[bestIndex]).width;

        pos.x = boundingRect(contoursTempl[bestIndex]).x;
        pos.y = boundingRect(contoursTempl[bestIndex]).y;

        printf("Match result: %f,\th = %f,\tw=%f\n", indexScore, height, width);
    }

    Rect size;
    size.height=height;
    size.width=width;
    return size;
}



void detectPatternAndDisplay(Mat &frame, Mat &templ, Rect size){
    /// Source image to display
    Mat img_display;
    frame.copyTo( img_display );

    Mat temp;
    Size dsize(size.width, size.height);
    resize(templ, temp, dsize, 0, 0);

    Point matchLoc, maxLoc, minLoc;
    double minVal, maxVal;
    Mat result;
    /// Do the Matching and Normalize
    matchTemplate( frame, temp, result, 5 );
    //normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );
    /// Localizing the best match with minMaxLoc
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
    //printf("Found maximum %f at (%i,%i) \n", maxVal, maxLoc.x, maxLoc.y);

    if(maxVal > 0.4){
        matchLoc = maxLoc;
        rectangle( frame, matchLoc, Point( matchLoc.x + temp.cols , matchLoc.y + temp.rows ), Scalar::all(128), 2, 8, 0 );
        imshow( "Pattern Matching", frame );
        imshow( "Corr", result );
    }

}



void detectPattern(Mat &frame, Mat &templ, Rect size, Point &pos, float &score){
    /// Source image to display
    Mat img_display;
    frame.copyTo( img_display );

    Mat temp;
    Size dsize(size.width, size.height);
    resize(templ, temp, dsize, 0, 0);

    Point maxLoc, minLoc;
    double minVal, maxVal;
    Mat result;
    /// Do the Matching and Normalize
    matchTemplate( frame, temp, result, 5 );
    //normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );
    /// Localizing the best match with minMaxLoc
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
    //printf("Found maximum %f at (%i,%i) \n", maxVal, maxLoc.x, maxLoc.y);

    score = maxVal;
    pos = maxLoc;
}



/*
void detectPatternAndDisp(Mat &frame){
    /// Source image to display
    Mat img_display;
    frame.copyTo( img_display );

    double scaleFactor, bestScaleFactor=0.1;
    double score = 0; Point scoreLoc;
    Mat temp; Mat eqFrame;
    Size dsize(0,0);
    Mat result;

    for(scaleFactor = 1; scaleFactor < 1.1; scaleFactor+=0.1){
        resize(templ, temp, Size(scaleFactor*templ.cols, scaleFactor*templ.rows));
        /// Create the result matrix
        int result_cols = frame.cols - temp.cols + 1;
        int result_rows = frame.rows - temp.rows + 1;
        result.create( result_rows, result_cols, CV_32FC1 );
        //cvtColor( temp, temp, COLOR_BGR2GRAY );
        //equalizeHist( temp, temp );
        //cvtColor( frame, eqFrame, COLOR_BGR2GRAY );
        //equalizeHist( eqFrame, eqFrame );
        matchTemplate( frame, temp, result, 5 );
        minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
        //maxVal=maxVal*temp.rows*temp.cols/countNonZero(temp);
        printf("[ScaleOpt] For scale: %f, found maximum %f at (%i,%i) \n", scaleFactor, maxVal, maxLoc.x, maxLoc.y);

        if(maxVal > score){
            score = maxVal;
            scoreLoc = maxLoc;
            bestScaleFactor = scaleFactor;
        }

        imshow( "Temp", temp);
        usleep(100000);
    }
    printf("[ScaleOpt] Best  For scale: %f, found maximum %f at (%i,%i) \n", bestScaleFactor, score, scoreLoc.x, scoreLoc.y);
    resize(templ, temp, dsize, bestScaleFactor, bestScaleFactor);

    /// Do the Matching and Normalize
    //matchTemplate( frame, templ, result, 5 );
    //normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );
    /// Localizing the best match with minMaxLoc
    //minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
    //printf("Found maximum %f at (%i,%i) \n", maxVal, maxLoc.x, maxLoc.y);

    //if(maxVal > 0.5){
        matchLoc = maxLoc;
        rectangle( frame, matchLoc, Point( matchLoc.x + temp.cols , matchLoc.y + temp.rows ), Scalar::all(128), 2, 8, 0 );
    //}
    imshow( "Pattern Matching", frame );
    imshow( "Corr", result );
}
*/
