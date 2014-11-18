#include "Includes.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videoview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->srcSelect  , SIGNAL(   currentIndexChanged(int)          ),
                     this           , SLOT  (   getSrc())                         );

    ui->theFrame->setAutoFillBackground(true); // IMPORTANT!
    QPalette pal = ui->theFrame->palette();
    pal.setColor(QPalette::Window, QColor(Qt::black));
    ui->theFrame->setPalette(pal);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*VideoView* MainWindow::getView()
{
    return ui->theFrame;
}//*/

void MainWindow::getFrame(QImage image){
    ui->theFrame->updateView(image);
}

void MainWindow::getSrc(){
    emit sigResponsesSrc(ui->srcSelect->currentText().toStdString());
#if DBG
    DEBUG("MainWindow: sigResponsesSrc");
    printf("\t->(%s)\n",ui->srcSelect->currentText().toStdString().c_str());
#endif
}

//    ui->srcSelect->currentText().toStdString();
