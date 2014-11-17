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

protected:
     void run();

private:
     FaceDetection m_algo;

signals:
    void displayedFrame(QImage image);

public slots:
    void dispFrame(QImage image);
};

#endif // FACETHREAD_H
