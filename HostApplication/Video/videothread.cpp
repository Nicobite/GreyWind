#include "includes.h"
#include "Video/videothread.hpp"
#include "opencv2/opencv.hpp"
#include <QTime>
#define CV_IMWRITE_JPEG_QUALITY 1


VideoThread::VideoThread(QObject *parent) :
    QThread(parent)
{
    m_running = false;
    m_source = "None";
    m_nbFramesBeforeDetect = 40;
    m_picnumber = 0;
    m_takepicture = false;
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
                try{
                    capture->read(frame);

                    // Just a check
                    if(!frame.empty()){
                        Size dsize(640, 360);
                        resize(frame, frame, dsize, 0, 0);

                        if(m_takepicture){
                            vector<int> compression_params;
                            compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
                            compression_params.push_back(95);
                            std::string filename = QString("./pics/image"+QString::number(m_picnumber++)+".jpg").toStdString();
                            bool result = imwrite(filename, frame, compression_params);
                            m_takepicture = false;
                        }


                        if(frameCounter >= m_nbFramesBeforeDetect){
                            emit sendDetectionFrame(frame);
                            frameCounter = 0;
                        } else{
                            frameCounter++;
                        }

                        QImage image = QImage((const unsigned char*)frame.data,frame.cols,frame.rows,frame.step,QImage::Format_RGB888);

                        //DEBUG(frame.cols << " " << frame.rows);

                        //DEBUG("VideoThread: sendVideoFrame " << QTime::currentTime().toString("h:mm:ss:zzz"));
                        emit sendVideoFrame(image.rgbSwapped());

                    } else{
                        ERROR("[VideoThread]: no captured frame -- Break!");
                        emit cannotChangeSource(m_source, 1);
                        m_source = "None";

                    }
                } catch(cv::Exception e){
                    ERROR("[VideoThread]: Read failed!");
                    emit cannotChangeSource(m_source, 1);
                    m_source = "None";
                }
            } else{
                DEBUG("[VideoThread]: Source disappeared.");
                emit cannotChangeSource(m_source, 1);
                m_source = "None";
            }
        } else{
            QImage img = QImage(640, 360, QImage::Format_RGB888);
            img.fill(Qt::black);
            QPainter p(&img);

            p.setPen(QPen(Qt::white));
            p.setFont(QFont("Times", 16, QFont::Bold));
            p.drawText(img.rect(), Qt::AlignCenter, "No display source is selected.");
            emit sendVideoFrame(img.rgbSwapped());
        }
        usleep(25000);
    }
    DEBUG("[VideoThread] just before last realease");
    capture->release();
    delete capture;
    DEBUG("[VideoThread] exiting Facethread::run()");
}

int VideoThread::openVideo(VideoCapture * capture){
    DEBUG("[VideoThread] entering openVideo");
    if( m_source == "None" ){                                }else
    if (m_source == "Local"){   capture->open(SRC_DEFAULT);  } else
    if (m_source == "TCP")  {   capture->open(SRC_TCP);      }
    if (m_source!="None" && !capture->isOpened() ) {
        ERROR("[VideoThread] opening video capture, getting back to Local source."); // TODO: Make this a thing :$
        m_source = "Local";
        return -1;
    }
    DEBUG("[VideoThread] exiting openVideo with status Ok");
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

void VideoThread::savePicture(){
    m_takepicture = true;
}
