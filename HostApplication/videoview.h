#ifndef VIDEOVIEW_H
#define VIDEOVIEW_H

#include <QWidget>

namespace Ui {
class VideoView;
}

class VideoView : public QWidget
{
    Q_OBJECT

public:
    explicit VideoView(QWidget *parent = 0);
    ~VideoView();
    void updateView(QImage image);

private:
    Ui::VideoView *ui;
};

#endif // VIDEOVIEW_H
