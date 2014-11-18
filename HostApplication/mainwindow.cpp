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
#endif
}

//    ui->srcSelect->currentText().toStdString();
