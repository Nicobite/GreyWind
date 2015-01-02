#include "helpdetect.h"
#include "ui_helpdetect.h"

HelpDetect::HelpDetect(QWidget *parent)  :
    QDialog(parent),
    ui(new Ui::HelpDetect)
{
    ui->setupUi(this);
}


HelpDetect::~HelpDetect()
{
    delete ui;
}
