#include "mainwin_xcv.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWin_XCV w;
    w.show();
    return a.exec();
}
