#ifndef DETECTION_H
#define DETECTION_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Detection;
}

class Detection : public QDialog
{
    Q_OBJECT

public:
    explicit Detection(QWidget *parent = 0);
    ~Detection();

    void enable(bool state);


private:
    Ui::Detection *ui;


private slots:
    void validDetection();
    void addToBlackListDetection();
    void skip1Detection();
    void skip5Detection();
    void skip10Detection();

signals:
    void sendValidDetection();
    void sendAddToBlackListDetection();
    void sendSkip1Detection();
    void sendSkip5Detection();
    void sendSkip10Detection();
};

#endif // DETECTION_H
