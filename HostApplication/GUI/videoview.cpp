#include "videoview.h"
#include "ui_videoview.h"

VideoView::VideoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoView)
{
    DEBUG("VideowView constructor 1");
    ui->setupUi(this);
    // Connecting videoview with drawing thread
    /*QObject::connect(&m_painterThread,   SIGNAL(sigDrawToView(QPixmap))  ,
                     this,              SLOT(slotDrawToView(QPixmap))   );//*/
    m_painterThread.start();
    DEBUG("VideowView constructor 2");
}

VideoView::~VideoView()
{
    delete ui;
}


void VideoView::updateView(QImage image){
    updateVideo(image);
    //updateDraw();
}


void VideoView::updateVideo(QImage image){
    // Displaying video to videoLabel
    ui->videoLabel->setPixmap(QPixmap::fromImage(image));
    ui->videoLabel->show();
}

void VideoView::updateDraw(){
    // Preparing and drawing ellipses
    if(!m_drawPointFIFO.empty()){
        m_ellipsePoint = QPoint(m_drawPointFIFO.front().x, m_drawPointFIFO.front().y);
        m_ellipseWidth = m_drawSizeFIFO.front().width;
        m_ellipseHeight = m_drawSizeFIFO.front().height;
        m_drawPointFIFO.pop();
        m_drawSizeFIFO.pop();
    }
    QImage image2 = QImage(640,360,QImage::Format_ARGB32);
    QPainter painter(&image2);
    QPen pen(Qt::green);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawEllipse(m_ellipsePoint, m_ellipseWidth, m_ellipseHeight);

    // Displaying ellipses to drawLabel
    ui->drawLabel->setPixmap(QPixmap::fromImage(image2));
    ui->drawLabel->show();
}

void VideoView::slotDrawToView(QPixmap pixmap){
    ui->drawLabel->setPixmap(pixmap);
    ui->drawLabel->repaint();
}


void VideoView::pushEllipse(Point point, Size size){
    m_painterThread.m_drawPointFIFO.push(point);
    m_painterThread.m_drawSizeFIFO.push(size);
    DEBUG("Pushing ellipse - DONE");
}
