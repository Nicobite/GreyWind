#include "includes.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videoview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setting up UI
    ui->setupUi(this);

    // Connecting the qcombobox with the main window
    QObject::connect(ui->srcSelect  , SIGNAL(   currentIndexChanged(int)          ),
                     this           , SLOT  (   getSrc())                         );

    // Coloring the video frame for style points
    ui->theFrame->setAutoFillBackground(true);
    QPalette pal = ui->theFrame->palette();
    pal.setColor(QPalette::Window, QColor(Qt::black));
    ui->theFrame->setPalette(pal);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getFrame(QImage image){
    ui->theFrame->updateView(image);
}

void MainWindow::getSrc(){
    emit sigResponsesSrc(ui->srcSelect->currentText().toStdString());
    DEBUG("MainWindow: sigResponsesSrc");
#if DBG
    printf("\t->(%s)\n",ui->srcSelect->currentText().toStdString().c_str());
#endif
}
