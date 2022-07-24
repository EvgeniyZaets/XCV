#ifndef DETECTEDFACEMODEL_H
#define DETECTEDFACEMODEL_H
#include <iostream>
#include <QObject>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <QTimer>

using namespace cv;
using namespace std;

class detectedFaceModel : public QObject
{
    Q_OBJECT
public:
    detectedFaceModel(string pathImg,
                      string pathHaarEyeXML,
                      string pathHaarAltXML);
    // передается адрес фотографии и адреса xml файлов глаз и лица
    detectedFaceModel(Mat image,
                      string pathHaarAltXML);
    // передается адрес фотографии или кадра и адрес xml файла лица
    detectedFaceModel(string pathVideo,
                      int fps,
                      string pathHaarAltXML);
    // передается адрес видео, количество кадров для обработки в секунду,

    ~detectedFaceModel(){
    };

    Mat image_gray;
    //изображение в градациях серого
    QString InfoStatus;
    //строка сохраняющая в себе информацию о работе в цикле
    Mat image;
    // исходное изображение
private:
    cv::CascadeClassifier eye_Classifier; // классификатор глаз
    cv::CascadeClassifier face_cascade; // классификатор лица
    vector<Rect> eyeRect;
    vector<Rect> faceRect;

};

#endif // DETECTEDFACEMODEL_H




