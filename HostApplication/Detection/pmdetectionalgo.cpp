#include "pmdetectionalgo.h"


PMDetectionAlgo::PMDetectionAlgo(String filename): DetectionAlgo()
{
    m_base_path = "./pm/"+filename+"/";
    m_template_filename = m_base_path+filename+".templates";
    this->loadTemplates();

    m_lastGoodPattern = 0;
}

PMDetectionAlgo::~PMDetectionAlgo(){

}

void PMDetectionAlgo::detect(Mat &frame){
    unsigned int iter=0;
    bool found=false;

    Scalar avg = mean(frame);

    //Try others
    if(!found){
        Mat tempTempl;
        m_templates[iter].copyTo(tempTempl);

        floodFill(tempTempl, Point(0,0), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
        floodFill(tempTempl, Point(tempTempl.cols-1,0), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
        floodFill(tempTempl, Point(0,tempTempl.rows-1), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
        floodFill(tempTempl, Point(tempTempl.cols-1,tempTempl.rows-1), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);

        Point match_pos_1_0, match_pos_0_8, match_pos_1_2;
        Rect size_1_0, size_0_8, size_1_2;
        size_1_0.width = tempTempl.rows;
        size_1_0.height = tempTempl.cols;
        size_0_8.width = 0.8*size_1_0.width ;
        size_0_8.height = 0.8*size_1_0.height;
        size_1_2.width = 1.2*size_1_0.width ;
        size_1_2.height = 1.2*size_1_0.height;
        float match_score_1_0, match_score_1_2, match_score_0_8, bestMatchScore=0.2;
        int bestMatch=0;

        detectPattern(frame, tempTempl, size_0_8, match_pos_0_8, match_score_0_8);
        if(bestMatchScore <= match_score_0_8){
            bestMatch=1;
            bestMatchScore = match_score_0_8;
        }
        detectPattern(frame, tempTempl, size_1_0, match_pos_1_0, match_score_1_0);
        if(bestMatchScore <= match_score_1_0){
            bestMatch=2;
            bestMatchScore = match_score_1_0;
        }
        detectPattern(frame, tempTempl, size_1_2, match_pos_1_2, match_score_1_2);
        if(bestMatchScore <= match_score_1_2){
            bestMatch=3;
            bestMatchScore = match_score_1_2;
        }

        if((match_score_0_8>0.2)&&(match_score_1_0>0.2)&&(match_score_1_2>0.2)&&
                (norm(Mat(match_pos_0_8), Mat(match_pos_1_0))<=15) &&
                (norm(Mat(match_pos_1_2), Mat(match_pos_1_0))<=15)){
            found = true;
            m_lastGoodPattern = iter;

            switch(bestMatch){
            case 1:
                m_point = Point(match_pos_0_8.x+0.5*size_0_8.width, match_pos_0_8.y+0.5*size_0_8.height);
                m_size = Size(size_0_8.width/2 , size_0_8.height/2);
                break;
            case 2:
                m_point = Point(match_pos_1_0.x+0.5*size_1_0.width, match_pos_1_0.y+0.5*size_1_0.height);
                m_size = Size(size_1_0.width/2 , size_1_0.height/2);
                break;
            case 3:
                m_point = Point(match_pos_1_2.x+0.5*size_1_2.width, match_pos_1_2.y+0.5*size_1_2.height);
                m_size = Size(size_1_2.width/2 , size_1_2.height/2);
                break;
            default:
                exit(-666);
                break;
            }

            emit detectedObject(m_point, m_size);

            //imshow( "Pattern Matching", frame );
        }
    }

    //Try others
    while(!found){
        Mat tempTempl;
        m_templates[iter].copyTo(tempTempl);

        floodFill(tempTempl, Point(0,0), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
        floodFill(tempTempl, Point(tempTempl.cols-1,0), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
        floodFill(tempTempl, Point(0,tempTempl.rows-1), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);
        floodFill(tempTempl, Point(tempTempl.cols-1,tempTempl.rows-1), avg, 0, cv::Scalar(255), cv::Scalar(255), 8);

        Point match_pos_1_0, match_pos_0_8, match_pos_1_2;
        Rect size_1_0, size_0_8, size_1_2;
        size_1_0.width = tempTempl.rows;
        size_1_0.height = tempTempl.cols;
        size_0_8.width = 0.8*size_1_0.width ;
        size_0_8.height = 0.8*size_1_0.height;
        size_1_2.width = 1.2*size_1_0.width ;
        size_1_2.height = 1.2*size_1_0.height;
        float match_score_1_0, match_score_1_2, match_score_0_8, bestMatchScore=0.2;
        int bestMatch=0;

        detectPattern(frame, tempTempl, size_0_8, match_pos_0_8, match_score_0_8);
        if(bestMatchScore <= match_score_0_8){
            bestMatch=1;
            bestMatchScore = match_score_0_8;
        }
        detectPattern(frame, tempTempl, size_1_0, match_pos_1_0, match_score_1_0);
        if(bestMatchScore <= match_score_1_0){
            bestMatch=2;
            bestMatchScore = match_score_1_0;
        }
        detectPattern(frame, tempTempl, size_1_2, match_pos_1_2, match_score_1_2);
        if(bestMatchScore <= match_score_1_2){
            bestMatch=3;
            bestMatchScore = match_score_1_2;
        }

        if((match_score_0_8>0.2)&&(match_score_1_0>0.2)&&(match_score_1_2>0.2)&&
                (norm(Mat(match_pos_0_8), Mat(match_pos_1_0))<=15) &&
                (norm(Mat(match_pos_1_2), Mat(match_pos_1_0))<=15)){
            found = true;
            m_lastGoodPattern = iter;

            switch(bestMatch){
            case 1:
                m_point = Point(match_pos_0_8.x+0.5*size_0_8.width, match_pos_0_8.y+0.5*size_0_8.height);
                m_size = Size(size_0_8.width/2 , size_0_8.height/2);
                break;
            case 2:
                m_point = Point(match_pos_1_0.x+0.5*size_1_0.width, match_pos_1_0.y+0.5*size_1_0.height);
                m_size = Size(size_1_0.width/2 , size_1_0.height/2);
                break;
            case 3:
                m_point = Point(match_pos_1_2.x+0.5*size_1_2.width, match_pos_1_2.y+0.5*size_1_2.height);
                m_size = Size(size_1_2.width/2 , size_1_2.height/2);
                break;
            default:
                exit(-666);
                break;
            }

            emit detectedObject(m_point, m_size);


            //imshow( "Pattern Matching", frame );
        } else{
            //imshow( "Pattern Matching", frame );
            if(iter < m_templates.size()-1){
                iter++;
            } else{
                found = true;
            }
        }
    }
}


void PMDetectionAlgo::loadTemplates(){
    ifstream inputFile;
    inputFile.open(m_template_filename.c_str());
    if(inputFile.is_open()){
        int size;
        inputFile >> size;
        for(int i=0; i<size ;i++){
            std::string templ_fd;
            inputFile >> templ_fd;
            m_templates.push_back(imread(m_base_path+templ_fd,1));
        }

        inputFile.close();
        printf("[PM] Template loaded.\n");
    } else{
        printf("[PM] Template load failed.\n");
    }
}


void PMDetectionAlgo::detectPattern(Mat &frame, Mat &templ, Rect &size, Point &pos, float &score){
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

    /// Localizing the best match with minMaxLoc
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
    //printf("Found maximum %f at (%i,%i) \n", maxVal, maxLoc.x, maxLoc.y);

    score = maxVal;
    pos = maxLoc;
}
