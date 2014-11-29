#include "videoview.h"
#include "ui_videoview.h"

VideoView::VideoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoView)
{
    ui->setupUi(this);
}

VideoView::~VideoView()
{
    delete ui;
}

void VideoView::updateView(QImage image)
{
    if(!m_drawPointFIFO.empty()){
        m_ellipsePoint = QPoint(m_drawPointFIFO.front().x, m_drawPointFIFO.front().y);
        m_ellipseWidth = m_drawSizeFIFO.front().width;
        m_ellipseHeight = m_drawSizeFIFO.front().height;
        m_drawPointFIFO.pop();
        m_drawSizeFIFO.pop();
    }
    //ellipse( image, m_ellipsePoint, m_ellipseSize, 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

    QPainter painter(&image);
    QPen pen(Qt::green);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawEllipse(m_ellipsePoint, m_ellipseWidth, m_ellipseHeight);

    ui->videoLabel->setPixmap(QPixmap::fromImage(image));
    ui->videoLabel->show();
}

void VideoView::pushEllipse(Point point, Size size){
    m_drawPointFIFO.push(point);
    m_drawSizeFIFO.push(size);
}
