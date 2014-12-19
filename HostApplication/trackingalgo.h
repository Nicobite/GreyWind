#ifndef TRACKINGALGO_H
#define TRACKINGALGO_H

#include <QObject>
#include <opencv2/opencv.hpp>


class TrackingAlgo : public QObject
{
    Q_OBJECT

private:
    cv::Point m_coordinate;
    cv::Size m_size;
    bool m_status;

public:
    explicit TrackingAlgo(QObject *parent = 0);

    virtual void initialise(cv::Mat img, cv::Point point, cv::Size size) = 0;
    virtual void track(cv::Mat img) = 0;

    cv::Point getCoordinate();
    cv::Size getSize();
    bool getStatus();

signals:

public slots:


};

#endif // TRACKINGALGO_H
