#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::keyPressEvent(QKeyEvent* e){
    if(!e->isAutoRepeat())
        qDebug() << "Button pressed " << e->text() << ", " << e->key() << "!\n";

}

void MainWindow::keyReleaseEvent(QKeyEvent* e){
    if(!e->isAutoRepeat())
        qDebug() << "Button released " << e->text() << ", " << e->key()  << "!\n";
}
