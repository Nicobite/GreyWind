#include "Detection/surfdetectionalgo.h"
#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv::xfeatures2d;

SurfDetectionAlgo::SurfDetectionAlgo(String img_source_name): DetectionAlgo()
{
    m_base_path = "surf/"+img_source_name+"/";
    m_img_source_name = img_source_name+".png";
    //m_face_cascade_name     =   "haarcascade_frontalface_alt.xml";
    //m_face_cascade_name     =   "cascade_pyramide.xml";
    //m_face_cascade_name     =   "banana_classifier.xml";
    if( m_img_source_name.empty() ){
        ERROR("[SurfDetectionAlgo]: loading image source");
    };
}


SurfDetectionAlgo::~SurfDetectionAlgo()
{
}

void SurfDetectionAlgo::detect(Mat &frame)
{
    Mat img_1 = imread( m_base_path + m_img_source_name, IMREAD_COLOR );
    imwrite("studentcard.png",img_1);
    printf("%s",m_img_source_name.c_str());

    if( !img_1.data )
    std::cout<< " --(!) Error reading images " << std::endl;

    if ( !frame.data )
        std::cout << "--(!) Error reading frames " << std::endl;

    //-- Step 1: Detect the keypoints using SURF Detector
    int minHessian = 400;
    Size size;
    Ptr<SURF> detector = SURF::create( minHessian );

    std::vector<KeyPoint> keypoints_1, keypoints_2;

    detector->detect( img_1, keypoints_1 );
    detector->detect( frame, keypoints_2 );


    //-- Draw keypoints
    Mat img_keypoints_1; Mat img_keypoints_2;

    drawKeypoints( img_1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    drawKeypoints( frame, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT );

    Mat descriptors_1, descriptors_2;

    detector->compute( img_1, keypoints_1, descriptors_1 );
    detector->compute( frame, keypoints_2, descriptors_2 );

    //-- Step 3: Matching descriptor vectors using FLANN matcher
    FlannBasedMatcher matcher;
    std::vector< DMatch > matches;
    matcher.match( descriptors_1, descriptors_2, matches );

    double max_dist = 0; double min_dist = 100;

    //-- Quick calculation of max and min distances between keypoints
    for( int i = 0; i < descriptors_1.rows; i++ )
    { double dist = matches[i].distance;
        if( dist < min_dist ) min_dist = dist;
        if( dist > max_dist ) max_dist = dist;
    }

    printf("-- Max dist : %f \n", max_dist );
    printf("-- Min dist : %f \n", min_dist );

    //-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist,
    //-- or a small arbitary value ( 0.02 ) in the event that min_dist is very
    //-- small)
    //-- PS.- radiusMatch can also be used here.
    std::vector< DMatch > good_matches;

    for( int i = 0; i < descriptors_1.rows; i++ )
    { if( matches[i].distance <= max(2*min_dist, 0.02) )
        { good_matches.push_back( matches[i]); }
    }

    //-- Draw only "good" matches
    Mat img_matches;
    drawMatches( img_1, keypoints_1, frame, keypoints_2,
                 good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
                 std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

    for( int i = 0; i < (int)good_matches.size(); i++ )
    { printf( "-- Good Match [%d] Keypoint 1: %d  -- Keypoint 2: %d  \n", i, good_matches[i].queryIdx, good_matches[i].trainIdx ); }

    imshow("Video frame", img_matches);
    int cols=0, rows=0;
    for(int i = 0; i < (int)good_matches.size(); i++)
    {
        cols += keypoints_2[good_matches[i].trainIdx].pt.x;
        rows += keypoints_2[good_matches[i].trainIdx].pt.y;
    }
    cols /= good_matches.size();
    rows /= good_matches.size();

    printf("Cols centre : %d Rows center : %d \n", cols, rows);
    Point centre(cols,rows);
    size = Size(50,50);
    /*///-- Localize the object
    std::vector<Point2f> obj;
    std::vector<Point2f> scene;

    for( int i = 0; i < good_matches.size(); i++ )
    {
        //-- Get the keypoints from the good matches
        obj.push_back( keypoints_1[ good_matches[i].queryIdx ].pt );
        scene.push_back( keypoints_2[ good_matches[i].trainIdx ].pt );
    }*/
    /*
    Mat H = findHomography( obj, scene, RANSAC );

    //-- Get the corners from the image_1 ( the object to be "detected" )
    std::vector<Point2f> obj_corners(4);
    obj_corners[0] = Point(0,0); obj_corners[1] = Point( img_1.cols, 0 );
    obj_corners[2] = Point( img_1.cols, img_1.rows ); obj_corners[3] = Point( 0, img_1.rows );
    std::vector<Point2f> scene_corners(4);

    //printf("Size Homography : %d x %d ", H.cols, H.rows);
    perspectiveTransform( obj_corners, scene_corners, H);

    //-- Draw lines between the corners (the mapped object in the scene - image_2 )
    line( img_matches, scene_corners[0] + Point2f( img_1.cols, 0), scene_corners[1] + Point2f( img_1.cols, 0), Scalar( 0, 255, 0), 4 );
    line( img_matches, scene_corners[1] + Point2f( img_1.cols, 0), scene_corners[2] + Point2f( img_1.cols, 0), Scalar( 0, 255, 0), 4 );
    line( img_matches, scene_corners[2] + Point2f( img_1.cols, 0), scene_corners[3] + Point2f( img_1.cols, 0), Scalar( 0, 255, 0), 4 );
    line( img_matches, scene_corners[3] + Point2f( img_1.cols, 0), scene_corners[0] + Point2f( img_1.cols, 0), Scalar( 0, 255, 0), 4 );
    Point center(scene_corners[0] + Point2f(img_1.cols,0));
    Point center1(scene_corners[1] + Point2f(img_1.cols,0));
    Point center2(scene_corners[2] + Point2f(img_1.cols,0));
    Point center3(scene_corners[3] + Point2f(img_1.cols,0));*/
    /*circle(img_matches,center, 100, Scalar(255,0,0));
    circle(img_matches,center1, 100, Scalar(255,0,0));
    circle(img_matches,center2, 100, Scalar(255,0,0));
    circle(img_matches,center3, 100, Scalar(255,0,0));*/
    circle(frame, centre, 100, Scalar(0,255,0));
    emit detectedObject(centre, size);
    //-- Show detected matches
    /*imshow ("Object detection", frame_vid);
    imshow( "Good Matches & Object detection", img_matches);*/
    imshow("Video frame", frame);
}

