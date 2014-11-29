#ifndef VIDEOVIEW_H
#define VIDEOVIEW_H

#include <QWidget>
#include "includes.h"
#include <queue>
#include "opencv2/opencv.hpp"
#include <QPainter>

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

private:
    Ui::VideoView *ui;
    std::queue<Point> m_drawPointFIFO;
    std::queue<Size> m_drawSizeFIFO;
    QPoint m_ellipsePoint;
    int m_ellipseWidth, m_ellipseHeight;
};

#endif // VIDEOVIEW_H
