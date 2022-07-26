#include "videostreampresenter.h"
#include "ui_mainwin_xcv.h"
#include "mattoqt.h"
#include "detectedfacemodel.h"


VideoStreamPresenter::VideoStreamPresenter(QObject *parent)
    : QObject{parent}
{ }

void VideoStreamPresenter::ReadFrame() // воспроизведение потока и покадровая передача в метод распознования лиц
{
    if(capture.isOpened())
    {
        capture >> frame;
        if(!frame.empty())
        {
            cv::resize(frame, result_frame, Size(640, 480));
            QImage image;
            matToQimage(result_frame, image);
            QImage image_resul;
            string pathHaarAltXML = "C:/OpenCV/opencv-3.4.15/source/data/haarcascades/haarcascade_frontalface_alt.xml";
            //по умолчанию файл для детектора лиц
            detectedFaceModel Face(result_frame,pathHaarAltXML);
            matToQimage(Face.image, image_resul);
            emit FrameVideo(image,image_resul,Face.InfoStatus);
        }
    }
}

void VideoStreamPresenter::OpenVideo(std::string file_name, int fps, QTimer* timer) // открытие видеоканала
{
    capture.open(file_name);
    timer-> start (1000/fps);
}

void VideoStreamPresenter::CloseVideo(QLabel* label, QTimer* timer) //закрытие видеоканала
{
    timer-> stop (); // Прекращаем чтение данных.
    // освобождаем память;
    capture.release();
    frame.release();
    label->setText("Нажмите открыть видео для включения");
}
