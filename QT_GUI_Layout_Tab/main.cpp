#include "widget.h"
#include <QApplication>
#include <QTabBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTabBar tabBar;
    tabBar.addTab("AAA");
    tabBar.addTab("BBB");
    tabBar.show();

    return a.exec();
}
