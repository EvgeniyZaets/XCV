#include "importimg.h"
#include "ui_mainwin_xcv.h"
#include <QtCore>

importImg::importImg(QWidget *parent)
    : QWidget{parent}, ui(new Ui::MainWin_XCV)
{
    ui->setupUi(this);
}
