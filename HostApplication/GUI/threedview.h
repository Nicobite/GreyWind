#ifndef THREEDVIEW_H
#define THREEDVIEW_H

#include <QDialog>
#include <QGLWidget>

namespace Ui {
class ThreeDView;
}

class ThreeDView : public QDialog
{
    Q_OBJECT

public:
    explicit ThreeDView(QWidget *parent = 0);
    ~ThreeDView();
    void drawPyramid();

private:
    Ui::ThreeDView *ui;
};

#endif // THREEDVIEW_H
