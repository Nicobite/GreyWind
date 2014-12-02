#ifndef VIDEOVIEW_H
#define VIDEOVIEW_H

#include <QWidget>
#include <QPainter>
#include <queue>
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

private:
    Ui::VideoView * ui;
    PainterThread m_painterThread;

    std::queue<Point> m_drawPointFIFO;
    std::queue<Size> m_drawSizeFIFO;
    QPoint m_ellipsePoint;
    int m_ellipseWidth;
    int m_ellipseHeight;//*/

public slots:
    void slotDrawToView(QPixmap pixmap);

};

#endif // VIDEOVIEW_H
