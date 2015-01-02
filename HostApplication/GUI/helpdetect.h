#ifndef HELPDETECT_H
#define HELPDETECT_H

#include <QDialog>

namespace Ui {
class HelpDetect;
}

class HelpDetect : public QDialog
{
    Q_OBJECT
public:
    explicit HelpDetect(QWidget *parent = 0);
    ~HelpDetect();

signals:

public slots:

private:
    Ui::HelpDetect *ui;

};

#endif // HELPDETECT_H
