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
    QObject::connect(ui->srcSelect  , SIGNAL(   currentIndexChanged(int)        ),
                     this           , SLOT  (   getSrc())                       );

    // Connecting qdoublespinbox
    QObject::connect(ui->framesB4Detect , SIGNAL(   valueChanged(double)                ),
                     this               , SLOT  (   getFramesB4Detect(double))          );
    QObject::connect(this               , SIGNAL(   sigDispToCuteConsole(QString)       ),
                     ui->cuteConsole    , SLOT  (   appendPlainText(QString))           );

    // Coloring the video frame for style points
    ui->theFrame->setAutoFillBackground(true);
    QPalette pal = ui->theFrame->palette();
    pal.setColor(QPalette::Window, QColor(Qt::black));
    ui->theFrame->setPalette(pal);

    // Coloring navdata panel (temporary)
    ui->navDataLabel->setAutoFillBackground(true);
    pal = ui->navDataLabel->palette();
    pal.setColor(QPalette::Window, QColor(Qt::green));
    ui->navDataLabel->setPalette(pal);

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
    //DEBUG("MainWindow: sigResponsesSrc");
#if DBG
    printf("\t->(%s)\n",ui->srcSelect->currentText().toStdString().c_str());
#endif
}

void MainWindow::getFramesB4Detect(double fbd){
    DEBUG("MainWindow: sigResponsesSrc");
    framesB4Detect = (int)fbd;
    emit sigDispToCuteConsole(QString::fromStdString("[Detect] Frames before detection changed to ")+QString::number(fbd));
}
