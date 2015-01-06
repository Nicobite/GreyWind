#include "videoview.h"
#include "ui_videoview.h"

#define THREADED_DRAWING 0

VideoView::VideoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoView)
{
    m_framesB4Detect = 40;
    m_currentFrame = m_framesB4Detect;
    m_haltDraw = false;

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
    updateDraw();
    updateVideo(image);
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

    if(!m_drawPointFIFO.empty()){
        image2 = QImage(640,360,QImage::Format_ARGB32);
        image2.fill(QColor(0,0,0,0));
        QPainter painter(&image2);
        painter.setPen(m_pen);
        painter.setFont( QFont("Arial") );

        DEBUG("while: debut" << CURRENT_TIME);

        while(!m_drawPointFIFO.empty()){
            m_currentPoint = QPoint(m_drawPointFIFO.front().x, m_drawPointFIFO.front().y);
            m_currentWidth = m_drawSizeFIFO.front().width;
            m_currentHeight = m_drawSizeFIFO.front().height;
            m_currentShape = m_drawShapeFIFO.front();
            m_currentTag = m_drawTagFIFO.front();

            m_drawPointFIFO.pop();
            m_drawSizeFIFO.pop();
            m_drawShapeFIFO.pop();
            m_drawTagFIFO.pop();

            switch (m_currentShape) {
            case CyanEllipse:
                m_pen.setColor(Qt::cyan);
                painter.drawEllipse(m_currentPoint, m_currentWidth, m_currentHeight);
                break;
            case RedEllipse:
                m_pen.setColor(Qt::red);
                painter.drawEllipse(m_currentPoint, m_currentWidth, m_currentHeight);
                break;
            case GreenEllipse:
                m_pen.setColor(Qt::green);
                painter.drawEllipse(m_currentPoint, m_currentWidth, m_currentHeight);
                break;
            case BlackEllipse:
                m_pen.setColor(Qt::black);
                painter.drawEllipse(m_currentPoint, m_currentWidth, m_currentHeight);
                break;
            case CyanSquare:
                m_pen.setColor(Qt::cyan);
                painter.drawRect(m_currentPoint.x()-m_currentWidth,
                                 m_currentPoint.y()-m_currentHeight,
                                 m_currentWidth,
                                 m_currentHeight);
                break;
            case RedSquare:
                m_pen.setColor(Qt::red);
                painter.drawRect(m_currentPoint.x()-m_currentWidth,
                                 m_currentPoint.y()-m_currentHeight,
                                 m_currentWidth,
                                 m_currentHeight);
                break;
            }


            string = QString::fromStdString(m_currentTag)+" (x"+QString::number(m_currentPoint.x())+";y"+QString::number(m_currentPoint.y())+")";
            //DEBUG("updateDraw coordinates " << string);
            painter.drawText( m_currentPoint, string );
        }
        DEBUG("while: empty==true" << CURRENT_TIME);

        // Displaying ellipses to drawLabel
        ui->drawLabel->setPixmap(QPixmap::fromImage(image2));
        ui->drawLabel->show();
        m_currentFrame = m_framesB4Detect;
    } else{
        if(!m_haltDraw){
            if(m_currentFrame<=0){
                image2 = QImage(640,360,QImage::Format_ARGB32);
                image2.fill(QColor(0,0,0,0));
                ui->drawLabel->setPixmap(QPixmap::fromImage(image2));
                ui->drawLabel->show();
            } else{
                m_currentFrame--;
            }
        }
    }
}


void VideoView::pushShape(Point point, Size size, Shape shape, string tag){
    m_drawPointFIFO.push(point);
    m_drawSizeFIFO.push(size);
    m_drawShapeFIFO.push(shape);
    m_drawTagFIFO.push(tag);
}

void VideoView::resetDrawLabel(){
    while(!m_drawPointFIFO.empty()) {m_drawPointFIFO.pop();}
    while(!m_drawSizeFIFO.empty()) {m_drawSizeFIFO.pop();}
    while(!m_drawShapeFIFO.empty()) {m_drawShapeFIFO.pop();}
    while(!m_drawTagFIFO.empty()) {m_drawTagFIFO.pop();}

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

void VideoView::setObjname(std::string objname){
    m_objName = objname;
}

void VideoView::setHaltDraw(bool hold){
    m_haltDraw = hold;
}
