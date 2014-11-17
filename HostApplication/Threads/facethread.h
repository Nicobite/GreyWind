#ifndef FACETHREAD_H
#define FACETHREAD_H

#include <QThread>

class Facethread : public QThread
{
    Q_OBJECT
public:
    explicit Facethread(QObject *parent = 0);

protected:
     void run();

signals:

public slots:

};

#endif // FACETHREAD_H
