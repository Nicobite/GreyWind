#include "detectiontrackingalgo.h"

DetectionTrackingAlgo::DetectionTrackingAlgo() : TrackingAlgo()
{
    m_algo = NULL;
}

DetectionTrackingAlgo::~DetectionTrackingAlgo(){
    if(m_algo != NULL){
        delete m_algo;
        m_algo = NULL;
    }}

void DetectionTrackingAlgo::initialise(cv::Mat img, cv::Point point, cv::Size size, std::string detecAlgoName, std::string detectObjName){
    m_nomAlgo = detecAlgoName;
    m_object = detectObjName;
    if(m_nomAlgo == "<none>"){

        if(m_algo != NULL){
            delete m_algo;
            m_algo = NULL;
        }


    } else{

        if(m_nomAlgo == "Haar"){
            //Removing the previous algorithm
            if(m_algo != NULL){
                delete m_algo;
                m_algo = NULL;
            }
            //Settting new object path
            QString algpath = "./haar/"+QString::fromStdString(m_object);
            if(m_object==""){
            }else if(QDir(algpath).exists()){
                //New algorithm
                m_algo = new HaarFaceDetectionAlgo(m_object);
            } else{
            }

        } else if(m_nomAlgo == "PCM"){

            //Removing the previous algorithm
            if(m_algo != NULL){
                delete m_algo;
                m_algo = NULL;
            }
            //Settting new object path
            QString algpath = "./pcm/"+QString::fromStdString(m_object);
            if(m_object==""){
            }else if(QDir(algpath).exists()){
                //New algorithm
                m_algo = new PCMDetectionAlgo(m_object);

            } else{
            }

        } else if(m_nomAlgo == "SURF"){
            //Removing the previous algorithm
            if(m_algo != NULL){
                delete m_algo;
                m_algo = NULL;
            }
            //Settting new object path
            QString algpath = "./surf/"+QString::fromStdString(m_object);
            if(m_object==""){
            }else if(QDir(algpath).exists()){
                //New algorithm
                //m_algo = new SurfDetectionAlgo(m_object2detect);
            } else{

            }
        }
    }
}

void DetectionTrackingAlgo::track(cv::Mat img){
 if(m_algo!=NULL){
     m_algo->detectOnFrame(img);

     cv::Point center = m_algo->getPoint();
     cv::Size size = m_algo->getSize();
     m_size.width = size.width*2;
     m_size.height = size.height*2;
     m_coordinate = center;
 }
}
