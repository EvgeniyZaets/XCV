#ifndef EQUIPMENTCAMERAPRESENTER_H
#define EQUIPMENTCAMERAPRESENTER_H

#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QDateTime>
#include <QMessageBox>

namespace Ui {
class EquipmentCameraPresenter;
}

class EquipmentCameraPresenter : public QDialog
{
    Q_OBJECT

signals:
    void signalIdCam(QCameraInfo CameraInfo);

public slots:
    void slot();

public:
    explicit EquipmentCameraPresenter(QWidget *parent = nullptr);
    ~EquipmentCameraPresenter();

    QCameraInfo CameraInfo;
private slots:
    void on_on_startBt_clicked();

    void on_pushButton_clicked();

private:

    QCamera* Camera; // Указатель на объект камеры
    QCameraViewfinder* CameraViewFinder; // Видоискатель камеры
    QList<QCameraInfo> CameraInfoList; // Сохраняем информацию об устройстве камеры
    Ui::EquipmentCameraPresenter *ui;
};

#endif // EQUIPMENTCAMERAPRESENTER_H
