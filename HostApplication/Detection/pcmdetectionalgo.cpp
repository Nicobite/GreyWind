#include "pcmdetectionalgo.h"

#define CONTOUR_APPROX_MODE CHAIN_APPROX_TC89_L1

PCMDetectionAlgo::PCMDetectionAlgo(String pcm_filename): DetectionAlgo()
{
    m_pcm_filename=pcm_filename;
    m_template_filename = m_pcm_filename+".templates";
    this->loadContour(m_contour_template, m_pcm_filename);
    this->loadTemplates(m_templates, m_template_filename);
}

PCMDetectionAlgo::~PCMDetectionAlgo(){

}

void PCMDetectionAlgo::detect(Mat &frame){
    unsigned int iter=0;
    bool found=false;
    Point position_contour;

    Scalar avg = mean(frame);
    Rect size = getAverageShapeSize(frame, m_contour_template, position_contour);

    while(!found){
        Mat tempTempl;
        m_templates[iter].copyTo(tempTempl);

        floodFill(tempTempl, Point(0,0), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
        floodFill(tempTempl, Point(tempTempl.cols-1,0), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
        floodFill(tempTempl, Point(0,tempTempl.rows-1), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
        floodFill(tempTempl, Point(tempTempl.cols-1,tempTempl.rows-1), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);

        Point match_pos;
        float match_score;
        detectPattern(frame, tempTempl, size, match_pos, match_score);

        if(norm(Mat(match_pos), Mat(position_contour))<=30){
            found = true;
            rectangle( frame, match_pos, Point( match_pos.x + size.width , match_pos.y + size.height), Scalar(0,255,0), 2, 8, 0 );
            imshow( "Pattern Matching", frame );
        } else{
            imshow( "Pattern Matching", frame );
            if(iter < m_templates.size()-1){
                iter++;
            } else{
                found = true;
            }
        }
    }
}


void PCMDetectionAlgo::loadContour(vector<Point>& contour_template, String filename){
    ifstream inputFile;
    inputFile.open(filename.c_str());
    if(inputFile.is_open()){
        int size;
        inputFile >> size;
        for(int i=0; i<size ;i++){
            int x,y;
            inputFile >> x >> y;
            Point pt(x,y);
            contour_template.push_back(pt);
        }

        inputFile.close();
        printf("[PCM] Contour loaded.\n");
    } else{
        printf("[PCM] Contour load failed.\n");
    }
}

void PCMDetectionAlgo::loadTemplates(vector<Mat>& templates, String filename){
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
        printf("[PCM] Template loaded.\n");
    } else{
        printf("[PCM] Template load failed.\n");
    }
}

Rect PCMDetectionAlgo::getAverageShapeSize(Mat& frame, vector<Point>& contour_template, Point& pos){
    static float height=boundingRect(contour_template).height, width=boundingRect(contour_template).width;

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
        float res = matchShapes(contour_template, contoursTempl[i], 1 , 0.0);
        if(res > 0.8 || arcLength(contoursTempl[i], false)<100 || contourArea(contoursTempl[i])<1000){
            //nop
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

void PCMDetectionAlgo::detectPattern(Mat &frame, Mat &templ, Rect &size, Point &pos, float &score){
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
