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

    QObject::connect(ui->skip1Button,       SIGNAL(clicked()),
                     this,                  SLOT(skip1Detection()));

    QObject::connect(ui->skip5Button,       SIGNAL(clicked()),
                     this,                  SLOT(skip5Detection()));

    QObject::connect(ui->skip10Button,       SIGNAL(clicked()),
                     this,                  SLOT(skip10Detection()));
}

Detection::~Detection()
{
    delete ui;
}


void Detection::enable(bool state){
    ui->validButton->setEnabled(state);
    ui->blackListButton->setEnabled(state);
    ui->skip1Button->setEnabled(state);
    ui->skip5Button->setEnabled(state);
    ui->skip10Button->setEnabled(state);
}


void Detection::validDetection(){

    emit sendValidDetection();

}

void Detection::addToBlackListDetection(){

    emit sendAddToBlackListDetection();

}

void Detection::skip1Detection(){
    emit sendSkip1Detection();
}

void Detection::skip5Detection(){
    emit sendSkip5Detection();
}

void Detection::skip10Detection(){
    emit sendSkip10Detection();
}
