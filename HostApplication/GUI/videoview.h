#ifndef VIDEOVIEW_H
#define VIDEOVIEW_H

#include <QWidget>
#include <QPainter>
#include <queue>
#include <unistd.h>
#include "opencv2/opencv.hpp"
#include "includes.h"
#include "painterthread.h"

namespace Ui {
class VideoView;
}

using namespace cv;

class VideoView : public QWidget
{
    Q_OBJECT

public:
    explicit VideoView(QWidget *parent = 0);
    ~VideoView();
    void updateView(QImage image);
    void pushEllipse(Point point, Size size);
    void updateVideo(QImage);
    void updateDraw();
    void resetDrawLabel();
    void setFrameB4Detect(int framesB4Detect);
    void penInit();
    void penChange(QColor color, int size);
    void setObjname(std::string objname);
    void setHaltDraw(bool hold);

private:
    int m_framesB4Detect;
    int m_currentFrame;
    std::string m_objName;
    Ui::VideoView * ui;
    PainterThread m_painterThread;
    bool m_haltDraw;

    std::queue<Point> m_drawPointFIFO;
    std::queue<Size> m_drawSizeFIFO;
    QPoint m_ellipsePoint;
    int m_ellipseWidth;
    int m_ellipseHeight;//*/
    QPen m_pen;

};

#endif // VIDEOVIEW_H
