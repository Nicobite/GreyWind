#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UI/videoview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
