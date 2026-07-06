#include "mainwindow.h"

#include <QApplication>
#include "customer.h"
#include "classfood.h"
#include "sides.h"
#include "manger.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loadcustomertofile();
    loadfood();
    loadsides();
    loadmanger();
    MainWindow w;
    w.show();
    QObject::connect(&a,&QCoreApplication::aboutToQuit,[](){
        savecustomertofile();
        savesides();
        savefood();
        savemanger();
    });
    return a.exec();
}
