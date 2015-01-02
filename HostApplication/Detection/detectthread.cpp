#include "detectthread.h"

DetectThread::DetectThread(QObject *parent) :
    QThread(parent)
{
    m_running = true;
    m_algoname = "<none>";
    m_object2detect = "";
    m_algo = NULL;
    /*m_algoname = "Haar";
    m_object2detect = "face";
    m_algo = new HaarFaceDetectionAlgo("haarcascade_frontalface_alt");
    //m_algo = new HaarFaceDetectionAlgo("pyr_cascade_v2.xml"); // BUGGY
    QObject::connect(this,              SIGNAL(sigFrameToObject(Mat)),
                     m_algo,            SLOT(handleFrame(Mat)));
    QObject::connect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                     this,              SLOT(handleDetectedObject(Point,Size)));*/
}


DetectThread::~DetectThread(){
    m_running = false;
    delete m_algo;
}


void DetectThread::run(){
    DEBUG("> DetectThread::run()");
    while(m_running){
        if(!m_FIFO.empty()){
            // Popping element
            if(m_algo != NULL){
                emit sigFrameToObject(m_FIFO.front());
            }
            m_FIFO.pop();
            //DEBUG("DetectThread: send+pop DONE");
        }
    }
}

void DetectThread::pushMatToFIFO(Mat mat){
    m_FIFO.push(mat);
    //DEBUG("DectecThread: pushed");
}

void DetectThread::handleDetectedObject(Point center,Size size){
    emit sigDetectedToControl(center, size);
}



void DetectThread::changeDetectionAlgo(std::string algoname){

    m_algoname = algoname;

    if(m_algoname == "<none>"){

        emit sigMessageToConsole("Removing current detection algorithm...");

        if(m_algo != NULL){
            // Disconnecting this and the detection objects
            QObject::disconnect(this,              SIGNAL(sigFrameToObject(Mat)),
                             m_algo,            SLOT(handleFrame(Mat)));
            QObject::disconnect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                             this,              SLOT(handleDetectedObject(Point,Size)));
            delete m_algo;
            m_algo = NULL;
        }

        emit sigMessageToConsole("Detection algorithm is removed.");

    } else{

        if(m_algoname == "Haar"){
            emit sigMessageToConsole("Changing current detection algorithm to Haar...");

            //Removing the previous algorithm
            emit sigMessageToConsole("Removing current detection algorithm...");
            if(m_algo != NULL){
                // Disconnecting this and the detection objects
                QObject::disconnect(this,              SIGNAL(sigFrameToObject(Mat)),
                                 m_algo,            SLOT(handleFrame(Mat)));
                QObject::disconnect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                                 this,              SLOT(handleDetectedObject(Point,Size)));
                delete m_algo;
                m_algo = NULL;
            }



            //Settting new object path
            QString algpath = "./haar/"+QString::fromStdString(m_object2detect);

            if(m_object2detect==""){
                emit sigMessageToConsole("No object is specified. Nothing to do.");
            }else if(QDir(algpath).exists()){
                emit sigMessageToConsole("Selected object '"+m_object2detect+"' is found.");
                //New algorithm
                m_algo = new HaarFaceDetectionAlgo(m_object2detect);
                // Connecting this and the detection objects
                QObject::connect(this,              SIGNAL(sigFrameToObject(Mat)),
                                 m_algo,            SLOT(handleFrame(Mat)));
                QObject::connect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                                 this,              SLOT(handleDetectedObject(Point,Size)));
                emit sigMessageToConsole("Algorithm is changed.");
            } else{
                emit sigMessageToConsole("Error changing detection algorithm! Selected object '"+m_object2detect+"' doesn't exist! Nothing to do.");
            }

        } else if(m_algoname == "PCM"){
            emit sigMessageToConsole("Changing current detection algorithm to PCM...");

            //Removing the previous algorithm
            emit sigMessageToConsole("Removing current detection algorithm...");
            if(m_algo != NULL){
                // Disconnecting this and the detection objects
                QObject::disconnect(this,              SIGNAL(sigFrameToObject(Mat)),
                                 m_algo,            SLOT(handleFrame(Mat)));
                QObject::disconnect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                                 this,              SLOT(handleDetectedObject(Point,Size)));
                delete m_algo;
                m_algo = NULL;
            }



            //Settting new object path
            QString algpath = "./pcm/"+QString::fromStdString(m_object2detect);

            if(m_object2detect==""){
                emit sigMessageToConsole("No object is specified. Nothing to do.");
            }else if(QDir(algpath).exists()){
                emit sigMessageToConsole("Selected object '"+m_object2detect+"' is found.");
                //New algorithm
                m_algo = new PCMDetectionAlgo(m_object2detect);
                // Connecting this and the detection objects
                QObject::connect(this,              SIGNAL(sigFrameToObject(Mat)),
                                 m_algo,            SLOT(handleFrame(Mat)));
                QObject::connect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                                 this,              SLOT(handleDetectedObject(Point,Size)));
                emit sigMessageToConsole("Algorithm is changed.");
            } else{
                emit sigMessageToConsole("Error changing detection algorithm! Selected object '"+m_object2detect+"' doesn't exist! Nothing to do.");
            }



        } else if(m_algoname == "SURF"){
            emit sigMessageToConsole("Changing current detection algorithm to SURF...");

            /**
             * SURF NOT YET INTEGRATED
            **/
            emit sigMessageToConsole("SURF is not integrated in this release. Removing algorithm.");
            if(m_algo != NULL){
                // Disconnecting this and the detection objects
                QObject::disconnect(this,              SIGNAL(sigFrameToObject(Mat)),
                                 m_algo,            SLOT(handleFrame(Mat)));
                QObject::disconnect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                                 this,              SLOT(handleDetectedObject(Point,Size)));
                delete m_algo;
                m_algo = NULL;
            }


            emit sigMessageToConsole("Detection algorithm is removed.");

        }
    }
}

void DetectThread::changeObject2Detect(std::string objectname){

    m_object2detect = objectname;

    if(m_algoname == "<none>"){

        emit sigMessageToConsole("Nothing to do. No detection alogithm is active.");

    } else{

        if(m_algoname == "Haar"){
            emit sigMessageToConsole("Changing the object for current detection algorithm, Haar.");

            //Removing the previous algorithm
            emit sigMessageToConsole("Removing current detection algorithm...");
            if(m_algo != NULL){
                // Disconnecting this and the detection objects
                QObject::disconnect(this,              SIGNAL(sigFrameToObject(Mat)),
                                 m_algo,            SLOT(handleFrame(Mat)));
                QObject::disconnect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                                 this,              SLOT(handleDetectedObject(Point,Size)));
                delete m_algo;
                m_algo = NULL;
            }



            //Settting new object path
            QString algpath = "./haar/"+QString::fromStdString(m_object2detect);

            if(m_object2detect==""){
                emit sigMessageToConsole("No object is specified. Nothing to do.");
            }else if(QDir(algpath).exists()){
                emit sigMessageToConsole("Selected object '"+m_object2detect+"' is found.");
                //New algorithm
                m_algo = new HaarFaceDetectionAlgo(m_object2detect);
                // Connecting this and the detection objects
                QObject::connect(this,              SIGNAL(sigFrameToObject(Mat)),
                                 m_algo,            SLOT(handleFrame(Mat)));
                QObject::connect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                                 this,              SLOT(handleDetectedObject(Point,Size)));
                emit sigMessageToConsole("Algorithm is changed.");
            } else{
                emit sigMessageToConsole("Error changing detection algorithm! Selected object '"+m_object2detect+"' doesn't exist! Nothing to do.");
            }

        } else if(m_algoname == "PCM"){
            emit sigMessageToConsole("Changing the object for current detection algorithm, PCM.");

            //Removing the previous algorithm
            emit sigMessageToConsole("Removing current detection algorithm...");
            if(m_algo != NULL){
                // Disconnecting this and the detection objects
                QObject::disconnect(this,              SIGNAL(sigFrameToObject(Mat)),
                                 m_algo,            SLOT(handleFrame(Mat)));
                QObject::disconnect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                                 this,              SLOT(handleDetectedObject(Point,Size)));
                delete m_algo;
                m_algo = NULL;
            }



            //Settting new object path
            QString algpath = "./pcm/"+QString::fromStdString(m_object2detect);

            if(m_object2detect==""){
                emit sigMessageToConsole("No object is specified. Nothing to do.");
            }else if(QDir(algpath).exists()){
                emit sigMessageToConsole("Selected object '"+m_object2detect+"' is found.");
                //New algorithm
                m_algo = new PCMDetectionAlgo(m_object2detect);
                // Connecting this and the detection objects
                QObject::connect(this,              SIGNAL(sigFrameToObject(Mat)),
                                 m_algo,            SLOT(handleFrame(Mat)));
                QObject::connect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                                 this,              SLOT(handleDetectedObject(Point,Size)));
                emit sigMessageToConsole("Algorithm is changed.");
            } else{
                emit sigMessageToConsole("Error changing detection algorithm! Selected object '"+m_object2detect+"' doesn't exist! Nothing to do.");
            }



        } else if(m_algoname == "SURF"){
            emit sigMessageToConsole("Changing current detection algorithm to SURF...");

            /**
             * SURF NOT YET INTEGRATED
            **/
            emit sigMessageToConsole("SURF is not integrated in this release. Removing algorithm.");
            if(m_algo != NULL){
                // Disconnecting this and the detection objects
                QObject::disconnect(this,              SIGNAL(sigFrameToObject(Mat)),
                                 m_algo,            SLOT(handleFrame(Mat)));
                QObject::disconnect(m_algo,            SIGNAL(detectedObject(Point,Size)),
                                 this,              SLOT(handleDetectedObject(Point,Size)));
                delete m_algo;
                m_algo = NULL;
            }

            emit sigMessageToConsole("Detection algorithm is removed.");

        }
    }

}
