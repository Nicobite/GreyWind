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

enum Shape{ CyanEllipse, RedEllipse, GreenEllipse, BlackEllipse, CyanSquare, RedSquare};

class VideoView : public QWidget
{
    Q_OBJECT

public:
    explicit VideoView(QWidget *parent = 0);
    ~VideoView();
    void updateView(QImage image);
    void pushShape(Point point, Size size, Shape shape, std::string tag);
    void updateVideo(QImage);
    void updateDraw();
    void resetDrawLabel();
    void setFrameB4Detect(int framesB4Detect);
    void penInit();
    //void penChange(QColor color, int size);
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
    std::queue<Shape> m_drawShapeFIFO;
    std::queue<std::string> m_drawTagFIFO;
    QPoint m_currentPoint;
    int m_currentWidth;
    int m_currentHeight;//*/
    Shape m_currentShape;
    std::string m_currentTag;
    QPen m_pen;

private slots:


};

#endif // VIDEOVIEW_H
