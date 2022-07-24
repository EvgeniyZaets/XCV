#ifndef IMPORTIMG_H
#define IMPORTIMG_H
#include <QObject>
#include <QWidget>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class importImg : public QWidget
{
    Q_OBJECT

public:
    explicit importImg(QWidget *parent = nullptr);
    ~importImg();

private:
    cv::VideoCapture capWebcam;

    cv::Mat matOriginal;
    cv::Mat matOutput;
signals:

};

#endif // IMPORTIMG_H
