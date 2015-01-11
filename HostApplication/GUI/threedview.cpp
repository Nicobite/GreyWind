#include "threedview.h"
#include "ui_threedview.h"
#include "glwidget.h"
#include <QKeyEvent>

ThreeDView::ThreeDView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThreeDView)
{
    ui->setupUi(this);
    connect(ui->myGlWidget, SIGNAL(xRotationChanged(int)), ui->xRotSlider, SLOT(setValue(int)));
    connect(ui->myGlWidget, SIGNAL(yRotationChanged(int)), ui->yRotSlider, SLOT(setValue(int)));
    connect(ui->myGlWidget, SIGNAL(zRotationChanged(int)), ui->zRotSlider, SLOT(setValue(int)));
}

ThreeDView::~ThreeDView()
{
    delete ui;
}

void QDialog::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}
