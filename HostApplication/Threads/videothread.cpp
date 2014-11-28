#include "includes.h"
#include "videothread.hpp"
#include "opencv2/opencv.hpp"



VideoThread::VideoThread(QObject *parent) :
    QThread(parent)
{
    m_running = false;
    m_source = "None";
    m_nbFramesBeforeDetect = 40;
}

VideoThread::~VideoThread(){
    this->m_running = false;
    this->quit();
    this->wait();
}

void VideoThread::run() //TODO + TODO2 make better folders
{
    // Initiating needed objects
    VideoCapture* capture;
    Mat frame;

    // First video open
    capture = new VideoCapture;
    openVideo(capture);

    // Saving m_source before 1st iteration
    std::string m_source_old = m_source;
    m_running = true;

    int frameCounter = 0;

    while (m_running) {

        // Checking m_source changes
        if(m_source_old != m_source){
            DEBUG("[VideoThread]: Source actually changed in the last iteration");
            // then opening a new video stream for next iteration
            capture->release();
            capture->~VideoCapture();
            capture = new VideoCapture;
            openVideo(capture);

            // Save m_source for later
            m_source_old = m_source;

        } else if(m_source != "None"){
            //DEBUG("[VideoThread]: beginning of the while...");
            if(capture->isOpened())
            {
                capture->read(frame);

                // Just a check
                if(frame.empty()){
                    ERROR("[VideoThread]: no captured frame -- Break!");
                    break;
                }

                if(frameCounter == m_nbFramesBeforeDetect){
                    emit sendDetectionFrame(frame);
                    frameCounter = 0;
                } else{
                    frameCounter++;
                }

                // Send output of video feed to the video view
                QImage image = QImage((const unsigned char*)frame.data,frame.cols,frame.rows,frame.step,QImage::Format_RGB888);
                //Because OpenCV return BGR frames instead of RGB
                emit sendVideoFrame(image.rgbSwapped());

            } else{
                DEBUG("[VideoThread]: Source disappeared.");
            }
        } else{
            QImage image = QImage(320, 240, QImage::Format_RGB888);
            image.fill(Qt::black);
            QPainter p(&image);

            p.setPen(QPen(Qt::white));
            p.setFont(QFont("Times", 10, QFont::Bold));
            p.drawText(image.rect(), Qt::AlignCenter, "No display source is selected.");
            emit sendVideoFrame(image.rgbSwapped());
        }
    }
    DEBUG("[VideoThread]: just before last realease");
    capture->release();
    delete capture;
    DEBUG("[VideoThread]: exiting Facethread::run()");
}

int VideoThread::openVideo(VideoCapture * capture){
    DEBUG("[VideoThread]: entering openVideo");
    if( m_source == "None" ){                                }else
    if (m_source == "Local"){   capture->open(SRC_DEFAULT);  } else
    if (m_source == "TCP")  {   capture->open(SRC_TCP);      }
    if (m_source!="None" && !capture->isOpened() ) {
        ERROR("[VideoThread]: opening video capture, getting back to Local source."); // TODO: Make this a thing :$
        m_source = "Local";
        return -1;
    }
    DEBUG("[VideoThread]: exiting openVideo with status Ok");
    return 0;
}

/*
 Slots
*/
void VideoThread::setSource(std::string src){
    m_source = src;
}

void VideoThread::setDetectionPeriod(int nbFramesBeforeDetect){
    m_nbFramesBeforeDetect = nbFramesBeforeDetect;
}
