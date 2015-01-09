#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

class glWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit glWidget(QWidget *parent = 0);
    ~glWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void draw();
    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

public slots:
    // slots for xyz-rotation slider (might not be needed)
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

};

#endif // GLWIDGET_H
