#include "aboutbox.h"
#include "ui_aboutbox.h"
#include <QPixmap>

AboutBox::AboutBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutBox)
{
    ui->setupUi(this);
    // задаем параметры окна
    setFixedSize(550,380);
    ui->label_2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QPixmap pic(":/new/prefix1/icons/icons/icons8-бот-80.png");
    pic=pic.scaled(80, 80, Qt::KeepAspectRatio);
    ui->label_2->setPixmap(pic);
}

AboutBox::~AboutBox()
{
    delete ui;
}

void AboutBox::on_pushButton_clicked() //закрытие окна AboutBox
{
    close();
}

