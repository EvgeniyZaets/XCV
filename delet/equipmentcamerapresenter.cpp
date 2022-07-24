#include "equipmentcamerapresenter.h"
#include "ui_equipmentcamerapresenter.h"




/////////////////////////////////// первый вариант работы с камерой ///////////////////////////////////////
//void EquipmentCameraPresenter::slot()
//{

//}

//EquipmentCameraPresenter::EquipmentCameraPresenter(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::EquipmentCameraPresenter)
//{
//    ui->setupUi(this);
//    // При подключении к нескольким устройствам камеры получить доступную информацию о камере
//    CameraInfoList = QCameraInfo::availableCameras();
//    // Перемещаемся, добавляем информацию о камерах в раскрывающийся список по очереди
//    QList<QCameraInfo>::const_iterator it;
//    for(it=CameraInfoList.begin(); it!=CameraInfoList.end(); it++)
//    {
//        ui->deviceComboBox->addItem((*it).description());
//    }

//}

//EquipmentCameraPresenter::~EquipmentCameraPresenter()
//{
//    delete ui;
//}

//void EquipmentCameraPresenter::on_on_startBt_clicked()
//{
//    // Получаем имя открываемого устройства
//    CameraInfo = CameraInfoList.at(ui->deviceComboBox->currentIndex());
//    // Создаем объект камеры
//    Camera = new QCamera(CameraInfo);
//    // Создаем видоискатель и прикрепляем его к отображаемой области
//    CameraViewFinder = new QCameraViewfinder(ui->CameraLabel);
//    Camera->setViewfinder(CameraViewFinder);
//    // Регулируем размер отображения данных камеры
//    CameraViewFinder->resize(ui->CameraLabel->width(), ui->CameraLabel->height());
//    // Отображение видоискателя камеры
//    CameraViewFinder->show();
//    //Включи камеру
//    Camera->start();
//}


//void EquipmentCameraPresenter::on_pushButton_clicked()
//{
//    emit signalIdCam(CameraInfo);
//}

