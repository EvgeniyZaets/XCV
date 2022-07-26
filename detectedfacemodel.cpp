#include "detectedfacemodel.h"
///////////////////////////// РАСПОЗНОВАНИЯ ЛИЦ НА ИЗОБРАЖЕНИИ ////////////////////////////////////////
detectedFaceModel::detectedFaceModel(string pathImg,string pathHaarEyeXML,string pathHaarAltXML)
{

        this->image = imread(pathImg);
         cvtColor (this->image, this->image_gray, CV_BGR2GRAY);

         // Преобразовать в оттенки серого
         equalizeHist (this->image_gray, this->image_gray);

         // Выравниваем гистограмму, увеличиваем контраст для легкой обработки
          if (! eye_Classifier.load (pathHaarEyeXML))
         {
              qDebug() << "Load haarcascade_eye.xml failed!" << Qt::endl;
              InfoStatus = "Load haarcascade_eye.xml failed!";
         }

        if (!face_cascade.load(pathHaarAltXML))
        {
            qDebug() << "Load haarcascade_frontalface_alt failed!" << Qt::endl;
            InfoStatus = "Load haarcascade_frontalface_alt failed!";
        }

        // Определить положение глаз на фотографии
        this->eye_Classifier.detectMultiScale(this->image_gray, this->eyeRect, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
        for (size_t eyeIdx = 0; eyeIdx < this->eyeRect.size(); eyeIdx++)
        {
            rectangle (this->image, this->eyeRect [eyeIdx], Scalar (255, 0, 0),3);
            // Рисуем обнаруженную позицию с помощью прямоугольника
        }

        // Определить положение лица на фотографии
        this->face_cascade.detectMultiScale(this->image_gray, this->faceRect, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
        qDebug() << "faces number:"<< this->faceRect.size();
        QString Num =QString::number(faceRect.size());
        InfoStatus = "найдено лиц на изображении " + Num;
        for (size_t i = 0; i < this->faceRect.size(); i++)
        {
            rectangle (this->image, this->faceRect [i], Scalar (255, 0, 0),3);
            // Рисуем обнаруженную позицию с помощью прямоугольника
        }
}

///////////////////////////// РАСПОЗНОВАНИЯ ЛИЦ НА ВИДЕО ПОКАДРОВОЕ ////////////////////////////////////////
detectedFaceModel::detectedFaceModel(Mat image, string pathHaarAltXML)
{
     this->image = image;
     cvtColor (this->image, this->image_gray, CV_BGR2GRAY);
     equalizeHist (this->image_gray, this->image_gray);
    if (!face_cascade.load(pathHaarAltXML))
    {
        qDebug() << "Load haarcascade_frontalface_alt failed!" << Qt::endl;
        InfoStatus = "Load haarcascade_frontalface_alt failed!";
    }
    this->face_cascade.detectMultiScale(this->image_gray, this->faceRect, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(120, 120));
    qDebug() << "faces number:"<< this->faceRect.size();
    QString Num =QString::number(faceRect.size());
    InfoStatus = "найдено лиц на изображении " + Num;
    for (size_t i = 0; i < this->faceRect.size(); i++)
    {
        rectangle (this->image, this->faceRect [i], Scalar (255, 0, 0),3);
    }
}
