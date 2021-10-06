#include "mytestwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTestWidget w;
    w.show();

    return a.exec();
}
