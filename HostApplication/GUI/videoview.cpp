#include "videoview.h"
#include "ui_videoview.h"

#define THREADED_DRAWING 0

VideoView::VideoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoView)
{
    DEBUG("VideowView constructor 1");
    ui->setupUi(this);
    // Connecting videoview with drawing thread
#if THREADED_DRAWING
    QObject::connect(&m_painterThread,   SIGNAL(sigDrawToView(QPixmap))  ,
                     this,              SLOT(slotDrawToView(QPixmap))   );//*/
    m_painterThread.start();
#endif
    DEBUG("VideowView constructor 2");

    // Initialize the color et the size of the pen
    penInit();
}

VideoView::~VideoView()
{
    delete ui;
}


void VideoView::updateView(QImage image){
    //DEBUG("VideoView: updateView ");
    updateVideo(image);
#if !THREADED_DRAWING
    if(m_currentFrame == m_framesB4Detect){
        updateDraw();
        m_currentFrame = 0;
    }
    m_currentFrame++;
#endif
}


void VideoView::updateVideo(QImage image){
    // Displaying video to videoLabel
    ui->videoLabel->setPixmap(QPixmap::fromImage(image));
    ui->videoLabel->show();
}

void VideoView::updateDraw(){
    // Preparing and drawing ellipses
    QImage image2;
    //QPen pen;
    QString string;
    while(!m_drawPointFIFO.empty()){
        DEBUG("while: debut" << CURRENT_TIME);
        m_ellipsePoint = QPoint(m_drawPointFIFO.front().x, m_drawPointFIFO.front().y);
        m_ellipseWidth = m_drawSizeFIFO.front().width;
        m_ellipseHeight = m_drawSizeFIFO.front().height;
        m_drawPointFIFO.pop();
        m_drawSizeFIFO.pop();
        image2 = QImage(640,360,QImage::Format_ARGB32);
        QPainter painter(&image2);
        //pen.setColor(Qt::cyan);
        //pen.setWidth(3);
        painter.setPen(m_pen);
        painter.drawEllipse(m_ellipsePoint, m_ellipseWidth, m_ellipseHeight);
        painter.setFont( QFont("Arial") );

       string = "Face (x"+QString::number(m_ellipsePoint.x())+";y"+QString::number(m_ellipsePoint.y())+")";
        //DEBUG("updateDraw coordinates " << string);
        //pen.setColor(Qt::cyan);
        painter.setPen(m_pen);
        painter.drawText( m_ellipsePoint, string );
        // Displaying ellipses to drawLabel
        ui->drawLabel->setPixmap(QPixmap::fromImage(image2));
        ui->drawLabel->show();
        if(m_drawPointFIFO.empty()){
            DEBUG("while: empty==true" << CURRENT_TIME);
        }
    }

    /*
    if(!m_drawPointFIFO.empty()){
        m_ellipsePoint = QPoint(m_drawPointFIFO.front().x, m_drawPointFIFO.front().y);
        m_ellipseWidth = m_drawSizeFIFO.front().width;
        m_ellipseHeight = m_drawSizeFIFO.front().height;
        m_drawPointFIFO.pop();
        m_drawSizeFIFO.pop();
    }
    QImage image2 = QImage(640,360,QImage::Format_ARGB32);
    QPainter painter(&image2);
    QPen pen(Qt::);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawEllipse(m_ellipsePoint, m_ellipseWidth, m_ellipseHeight);
    painter.setFont( QFont("Arial") );
    QString string = "Face (x"+QString::number(m_ellipsePoint.x())+";y"+QString::number(m_ellipsePoint.y())+")";
    //DEBUG("updateDraw coordinates " << string);
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawText( m_ellipsePoint, string );
    // Displaying ellipses to drawLabel
    ui->drawLabel->setPixmap(QPixmap::fromImage(image2));
    ui->drawLabel->show();//*/
}

void VideoView::slotDrawToView(QPixmap pixmap){
    ui->drawLabel->setPixmap(QPixmap());
    ui->drawLabel->setPixmap(pixmap);
    ui->drawLabel->show();
}


void VideoView::pushEllipse(Point point, Size size){
#if THREADED_DRAWING
    m_painterThread.m_drawPointFIFO.push(point);
    m_painterThread.m_drawSizeFIFO.push(size);
#else
    m_drawPointFIFO.push(point);
    m_drawSizeFIFO.push(size);
#endif
    //DEBUG("Pushing ellipse - DONE");
}

void VideoView::resetDrawLabel(){ // TODO RESET DRAW LABEL WHEN NO VIDEO HOLYSHIT, THIS DOESN'T WORK FUCK
    QPixmap pixmap;
    pixmap.fill(QColor(0,0,0,0));
    ui->drawLabel->setPixmap(pixmap);
    ui->drawLabel->show();
    DEBUG("--> resetDrawLabel");
}

void VideoView::setFrameB4Detect(int framesB4Detect){
    m_framesB4Detect = framesB4Detect;
}

void VideoView::penInit(void){
    m_pen.setColor(Qt::cyan);
    m_pen.setWidth(3);
}

void VideoView::penChange(QColor color, int size){
    m_pen.setColor(color);
    m_pen.setWidth(size);
}
