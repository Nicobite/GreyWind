#ifndef CONTROLVIEW_H
#define CONTROLVIEW_H

#include <QWidget>
#include "help.h"
#include <QDebug>
#include <QKeyEvent>

namespace Ui {
class ControlView;
}

class ControlView : public QWidget
{
    Q_OBJECT

public:
    explicit ControlView(QWidget *parent = 0);
    ~ControlView();

    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);
public slots:
    void displayHelp();

signals:
    void pressCmd(int keyval);
    void releaseCmd();

private:
    Help m_helpWindow;

    Ui::ControlView *ui;
};

#endif // CONTROLVIEW_H
