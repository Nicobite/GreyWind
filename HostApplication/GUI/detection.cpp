#include "detection.h"
#include "ui_detection.h"

Detection::Detection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Detection)
{
    ui->setupUi(this);
    // Connect Valid button
    QObject::connect(ui->validButton,    SIGNAL(clicked()),
                    this,              SLOT(validDetection()));

    // Connect Add to BlackList button
    QObject::connect(ui->blackListButton,    SIGNAL(clicked()),
                     this,              SLOT(addToBlackListDetection()));
}

Detection::~Detection()
{
    delete ui;
}


void Detection::validDetection(){

    emit sendValidDetection();

}

void Detection::addToBlackListDetection(){

    emit sendAddToBlackListDetection();

}

