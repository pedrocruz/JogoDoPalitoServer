#include <QtGui/QApplication>
#include "serverwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerWindow w;
    w.show();
    
    return a.exec();
}