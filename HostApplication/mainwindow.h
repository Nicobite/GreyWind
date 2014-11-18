#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

private:


public slots:
    void getFrame(QImage image);
    void getSrc();

signals:
    void sigResponsesSrc(std::string src);

};

#endif // MAINWINDOW_H
