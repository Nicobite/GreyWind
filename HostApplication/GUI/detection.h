#ifndef DETECTION_H
#define DETECTION_H

#include <QDialog>

namespace Ui {
class Detection;
}

class Detection : public QDialog
{
    Q_OBJECT

public:
    explicit Detection(QWidget *parent = 0);
    ~Detection();


private:
    Ui::Detection *ui;


private slots:
    void validDetection();
    void addToBlackListDetection();

signals:
    void sendValidDetection();
    void sendAddToBlackListDetection();

};

#endif // DETECTION_H
