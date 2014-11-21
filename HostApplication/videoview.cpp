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
   ui->videoLabel->setPixmap(QPixmap::fromImage(image));
   ui->videoLabel->show();
}
