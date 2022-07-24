#ifndef VIDEOSTREAMPRESENTER_H
#define VIDEOSTREAMPRESENTER_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QImage>
#include <QLabel>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class VideoStreamPresenter : public QObject
{
    Q_OBJECT
public:
    explicit VideoStreamPresenter(QObject *parent = nullptr);

signals:
    void FrameVideo(QImage,QImage,QString);

public slots:

    void ReadFrame();

    void OpenVideo(std::string, int, QTimer*);

    void CloseVideo(QLabel*,QTimer*);

private:
    VideoCapture capture;
    Mat frame;
    Mat result_frame;

};

#endif // VIDEOSTREAMPRESENTER_H

