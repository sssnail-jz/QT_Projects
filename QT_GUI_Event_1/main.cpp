#include "widget.h"
#include <QApplication>
#include "widgeteventcustom.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetEventCustom w;
    w.resize(600,400);
    w.show();

    return a.exec();
}
