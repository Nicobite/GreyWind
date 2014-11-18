#ifndef FACETHREAD_H
#define FACETHREAD_H

#include <QThread>

#include "Detection/facedetection.hpp"

class Facethread : public QThread
{
    Q_OBJECT
public:
    Facethread(QObject *parent = 0);
    //void setAlgo(FaceDetection algo);
    //void linkSrcComboBox(std::string src);
    //const String m_source;

protected:
     void run();

private:
     FaceDetection m_algo;
     std::string m_source;

public slots:
    void dispFrame(QImage image);
    void getSrc();
    void updateSrc(std::string src);

signals:
    void displayedFrame(QImage image);
    void sigReqSrc();

};

#endif // FACETHREAD_H
