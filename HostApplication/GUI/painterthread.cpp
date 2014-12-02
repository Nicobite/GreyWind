#include "painterthread.h"
#include "opencv2/opencv.hpp"

PainterThread::PainterThread(QObject *parent) :
    QThread(parent)
{
    m_running = true;
}

PainterThread::~PainterThread(){
    this->m_running = false;
    this->quit();
    this->wait();
}

void PainterThread::run(){
    while(m_running){
        while(!m_drawPointFIFO.empty()){
            // Popping element
            m_ellipsePoint = QPoint(m_drawPointFIFO.front().x, m_drawPointFIFO.front().y);
            m_ellipseWidth = m_drawSizeFIFO.front().width;
            m_ellipseHeight = m_drawSizeFIFO.front().height;
            m_drawPointFIFO.pop();
            m_drawSizeFIFO.pop();
            // Creating transparent picture
            QImage image2 = QImage(640,360,QImage::Format_ARGB32);
            QPainter painter(&image2);
            QPen pen(Qt::green);
            pen.setWidth(3);
            painter.setPen(pen);
            painter.drawEllipse(m_ellipsePoint, m_ellipseWidth, m_ellipseHeight);

            // Displaying ellipses to drawLabel
            emit sigDrawToView(QPixmap::fromImage(image2));
        }

    }
}
