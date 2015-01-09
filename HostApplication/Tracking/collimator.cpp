#include "collimator.h"

Collimator::Collimator(QObject *parent):
    QThread(parent)
{
    m_running = false;
    m_tracker = NULL;

}

Collimator::~Collimator()
{
    m_running = false;
}

void Collimator::init(Mat img, Point point, Size size){

    if(m_running == false){
        if(m_algoname == "<none>"){

            emit sigMessageToConsole("No algorithm is selected, abort initialize.");
            m_running = false;

        } else{

            if(m_algoname == "PatternMatching"){
                emit sigMessageToConsole("Initializing current tracking algorithm (PatternMatching)...");

                //New algorithm
                //m_tracker = new HaarFaceDetectionAlgo(m_object2detect);
                m_tracker->initialise(img, point, size);
                emit sigMessageToConsole("Algorithm is running.");
                m_running = true;

            } else if(m_algoname == "LucasKannade"){

                emit sigMessageToConsole("Initializing current tracking algorithm(Lucas-Kannade)...");
                emit sigMessageToConsole("Not yet implemented.  Algorithm removed.");
                m_running = false;

                //New algorithm
                //m_tracker = new PCMDetectionAlgo(m_object2detect);
                //emit sigMessageToConsole("Algorithm is running.");
            }
        }
    }
}

void Collimator::run(){
    while(!m_running);
    while(m_running){
        if(!m_FIFO.empty()){
            // Popping element
            if(m_tracker != NULL){
                //DEBUG("Nbr elements m_FIFO : "+QString::number(m_FIFO.size()));
                m_tracker->track(m_FIFO.front());
                Point objPoint; Size objSize;
                objPoint = m_tracker->getCoordinate();
                objSize = m_tracker->getSize();

                bool laserVisible;
                Point laserPoint; Size laserSize;
                getLaserPosition(m_FIFO.front(), laserVisible, laserPoint, laserSize);


                emit detectedObject(objPoint, objSize);

                if(laserVisible){
                    emit detectedLaser(laserPoint, laserSize);

                    if((laserPoint.x >= objPoint.x - objSize.width/2 + laserSize.width/2) &&
                       (laserPoint.x <= objPoint.x + objSize.width/2 - laserSize.width/2) &&
                       (laserPoint.y >= objPoint.y - objSize.height/2 + laserSize.height/2) &&
                       (laserPoint.y <= objPoint.y + objSize.height/2 - laserSize.height/2)){
                        m_aligned = true;
                        emit sigDirections("OK");


                    } else{
                        m_aligned = false;

                        if(!(laserPoint.x >= objPoint.x - objSize.width/2 + laserSize.width/2)){
                            emit sigDirections("T_LEFT");
                        }
                        if(!(laserPoint.x <= objPoint.x + objSize.width/2 - laserSize.width/2)){
                            emit sigDirections("T_RIGHT");
                        }
                        if(!(laserPoint.y >= objPoint.y - objSize.height/2 + laserSize.height/2)){
                            emit sigDirections("UP");
                        }
                        if(!(laserPoint.y <= objPoint.y + objSize.height/2 - laserSize.height/2)){
                            emit sigDirections("DOWN");
                        }
                    }
                } else{
                    m_aligned = false;
                    emit sigDirections("NOT_IN_RANGE");
                }
            }
            //usleep(2000);
            //DEBUG("Popping...");
            m_FIFO.pop();
        }
    }
}

bool Collimator::isAligned(){
    return m_aligned;
}


void Collimator::getLaserPosition(Mat frame, bool &visible, Point &point, Size &size){
    Mat binFrame;
    vector<vector<Point> > contours;
    m_laser_detector.createBinaryPhoto(frame, binFrame, Scalar(0,0,225), Scalar(255,255,255));
    //m_laser_detector.createBinaryPhotoHSV(frame, binFrame, Scalar(200,115,150), Scalar(255,255,255));
    //Mat dummy;
    //frame.copyTo(dummy);
    //imshow("Debug", binFrame);
    m_laser_detector.findTheContours(binFrame, contours);


    //drawContours(dummy, contours, -1, Scalar(0,255,0),2);
    //imshow("Debug 2", dummy);

    m_laser_detector.bestcontours2Coordinates(contours);


    if( (m_laser_detector.getR() >= 3) &&
        (m_laser_detector.getX() >= 50) && (m_laser_detector.getX() <= (640-50)) &&
        (m_laser_detector.getY() >= 28) && (m_laser_detector.getY() <= (360-28))){
        visible = true;
        point.x = m_laser_detector.getX();
        point.y = m_laser_detector.getY();
        size.width = m_laser_detector.getR();

    } else{
        visible = false;
    }
}


void Collimator::handleFrame(Mat frame){
    m_FIFO.push(frame);
    //DEBUG("Pushing Nbr elements m_FIFO : "+QString::number(m_FIFO.size()));
}

void Collimator::changeAlgo(std::string algoname){
    if(m_running == false){
        m_algoname = algoname;

        emit sigMessageToConsole("Removing previous detection algorithm...");

        if(m_tracker != NULL){
            delete m_tracker;
            m_tracker = NULL;
        }

        if(m_algoname == "<none>"){
            emit sigMessageToConsole("Detection algorithm is removed.");

        } else{
            if(m_algoname == "PatternMatching"){
                emit sigMessageToConsole("Changing current tracking algorithm to PatternMatching...");
                m_tracker =  new PMTrackingAlgo();

            } else if(m_algoname == "LucasKannade"){
                emit sigMessageToConsole("Changing current detection algorithm to Lucas-Kannade...");
                emit sigMessageToConsole("Not yet implemented.  Algorithm removed.");
            }
        }
    }
}
