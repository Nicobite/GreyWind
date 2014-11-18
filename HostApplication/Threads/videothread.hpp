#ifndef VIDEOTHREAD_HPP
#define VIDEOTHREAD_HPP

#include <QThread>

#include "Detection/facedetection.hpp"

class VideoThread : public QThread
{
    Q_OBJECT
public:
    explicit VideoThread(QObject *parent = 0);

protected:
     void run();

private:
     FaceDetection m_algo;
     std::string m_source;
     int openVideo(VideoCapture * capture);

public slots:
    void displayFrame(QImage image);
    void updateSrc(std::string src);

signals:
    void sigFrameToGUI(QImage image);

};

#endif // VIDEOTHREAD_HPP
