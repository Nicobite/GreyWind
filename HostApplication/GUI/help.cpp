#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    ui->a->setStyleSheet("background:transparent;");
    ui->z->setStyleSheet("background:transparent;");
    ui->q->setStyleSheet("background:transparent;");
    ui->s->setStyleSheet("background:transparent;");
    ui->d->setStyleSheet("background:transparent;");
    ui->f->setStyleSheet("background:transparent;");
}

Help::~Help()
{
    delete ui;
}
