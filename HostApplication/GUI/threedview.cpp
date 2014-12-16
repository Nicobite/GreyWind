#include "threedview.h"
#include "ui_threedview.h"

ThreeDView::ThreeDView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThreeDView)
{
    ui->setupUi(this);
}

ThreeDView::~ThreeDView()
{
    delete ui;
}

void ThreeDView::drawPyramid(){

    ui->glWidget->qglClearColor(Qt::black);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glShadeModel(GL_SMOOTH);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    ui->glWidget->qglColor(Qt::red);
    glBegin(GL_QUADS);
        glNormal3f( 0, 0,-1);
        glNormal3f(-1,-1, 0);
        glNormal3f( 1,-1, 0);
        glNormal3f( 0, 0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f( 0,-1,0.707);
        glNormal3f(-1,-1, 0);
        glNormal3f( 1,-1, 0);
        glNormal3f( 0, 0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(-1, 0,0.707);
        glNormal3f( 1,-1, 0);
        glNormal3f( 1, 1, 0);
        glNormal3f( 0, 0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f( 0, 1,0.707);
        glNormal3f( 1, 1, 0);
        glNormal3f(-1, 1, 0);
        glNormal3f( 0, 0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(-1, 0,0.707);
        glNormal3f(-1, 1, 0);
        glNormal3f(-1, 1, 0);
        glNormal3f( 0, 0,1.2);
    glEnd();
}
