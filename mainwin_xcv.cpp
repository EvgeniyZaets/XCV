#include "mainwin_xcv.h"
#include "ui_mainwin_xcv.h"
#include "aboutbox.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "detectedfacemodel.h"
#include "mattoqt.h"
//#include "equipmentcamerapresenter.h"

using namespace std;
using namespace cv;

MainWin_XCV::MainWin_XCV(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin_XCV)
{
    ui->setupUi(this);


    // для потока видео
    VideoStream = new VideoStreamPresenter; // создаем объект класса видеопотока
    timer = new QTimer(this); //создаем таймер

    //соединяем через сигналы и слоты с файлом detectedfacemodel.h
    connect(this,&MainWin_XCV::OpenVideoSignal,VideoStream,&VideoStreamPresenter::OpenVideo);
    connect(timer,&QTimer::timeout,VideoStream,&VideoStreamPresenter::ReadFrame);
    connect(VideoStream,&VideoStreamPresenter::FrameVideo,this,&MainWin_XCV::FrameVideo);
}

MainWin_XCV::~MainWin_XCV()
{
    delete ui;
}

void MainWin_XCV::FrameVideo(QImage frame, QImage result_frame, QString infostatus) // вывод изображения с видео на два экрана
{
    ui->PanelOutputImg->setPixmap(QPixmap::fromImage(result_frame));
    ui->PanelOriginalImg->setPixmap(QPixmap::fromImage(frame));
    ui->plainTextConsole->append(infostatus);
}

///////////////////////////////// Запуск диалогового окна -  информация о приложении ///////////////////////////////////////////
void MainWin_XCV::on_aboutInfo_triggered()
{
    AboutBox about(this);
    about.exec();
}

///////////////////////////////// Запуск диалогового окна -  открыть файл изображения ///////////////////////////////////////////
void MainWin_XCV::on_openFileImg_triggered() // открыть файл - диалоговое окно
{
    QString selfilter = tr("JPEG (*.jpg *.jpeg);;TIFF (*.tiff *.tif);;PNG (*.png)");
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл для обработки",
                                                    QDir::currentPath(),
                                                    tr("JPEG (*.jpg *.jpeg);;TIFF (*.tiff *.tif);;PNG (*.png)"),
                                                    &selfilter); //сохраняем путь к файлу
    ui->plainTextConsole->append("открт файл :" + fileName);
    // выводит информацию в консоль не стирая старый статус
    string pathHaarEyeXML = "C:/OpenCV/opencv-3.4.15/source/data/haarcascades/haarcascade_eye.xml";
    //по умолчанию файл для детектора глаз
    string pathHaarAltXML = "C:/OpenCV/opencv-3.4.15/source/data/haarcascades/haarcascade_frontalface_alt.xml";
    //по умолчанию файл для детектора лиц
    string pathImg = fileName.toStdString();
    detectedFaceModel Face(pathImg,pathHaarEyeXML,pathHaarAltXML);
    //передаем путь к файлу в функцию детектора лиц
    ui->plainTextConsole->append(Face.InfoStatus);
    // выводит информацию в консоль не стирая старый статус
    Mat cvImgoOut = Face.image;
    // создаем матрицу изображения на основе пути - класс Mat из библиотеки OpenCV
    QImage qtImgOut;
    matToQimage(cvImgoOut, qtImgOut);
    QImage qtImgIn (fileName);
    qtImgOut=qtImgOut.scaled(640, 480, Qt::KeepAspectRatio);
    qtImgIn=qtImgIn.scaled(640, 480, Qt::KeepAspectRatio);
    ui->PanelOutputImg->setPixmap(QPixmap::fromImage(qtImgOut));
    ui->PanelOriginalImg->setPixmap(QPixmap::fromImage(qtImgIn));//выводим изображение
}

///////////////////////////////// Запуск диалогового окна -  открыть файл видео ///////////////////////////////////////////
void MainWin_XCV::on_openFileVideo_triggered()
{
    string pathVideo = (QFileDialog::getOpenFileName(this, tr("Open Video"), ".", tr("Video File(*.avi *.mp4 *.h264)"))).toStdString();
    emit OpenVideoSignal(pathVideo,35, timer);
    emit MainWin_XCV::ReadFrame();

}

