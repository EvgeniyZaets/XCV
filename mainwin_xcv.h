#ifndef MAINWIN_XCV_H
#define MAINWIN_XCV_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
//#include "equipmentcamerapresenter.h"
#include "videostreampresenter.h"

using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWin_XCV; }
QT_END_NAMESPACE

class MainWin_XCV : public QMainWindow
{
    Q_OBJECT

public:
    MainWin_XCV(QWidget *parent = nullptr);
    ~MainWin_XCV();

signals:

    void OpenVideoSignal(std::string, int, QTimer*);
    void ReadFrame();

private:
    QTimer *timer;

private slots:

    void FrameVideo(QImage,QImage,QString);

    void on_aboutInfo_triggered();

    void on_openFileImg_triggered();

    //void on_WebCamOpen_triggered();

    void on_openFileVideo_triggered();


private:
    Ui::MainWin_XCV *ui;
//    EquipmentCameraPresenter *cameraForm;
    VideoStreamPresenter *VideoStream;
};
#endif // MAINWIN_XCV_H
