#ifndef PAINTERTHREAD_H
#define PAINTERTHREAD_H

#include <QThread>
#include <QPainter>
#include <queue>
#include "opencv2/opencv.hpp"
#include "includes.h"

using namespace std;
using namespace cv;

class PainterThread : public QThread
{
    Q_OBJECT
public:
    explicit PainterThread(QObject *parent = 0);
    ~PainterThread();

    std::queue<Point> m_drawPointFIFO;
    std::queue<Size> m_drawSizeFIFO;

protected:
     void run();

private:
    bool m_running;
    QPoint m_ellipsePoint;
    int m_ellipseWidth;
    int m_ellipseHeight;

signals:
    void sigDrawToView(QPixmap pixmap);

public slots:

};

#endif // PAINTERTHREAD_H
