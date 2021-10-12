#include "widget.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    QPushButton *pb=new QPushButton("Preferred");
    QPushButton *pb1=new QPushButton("Expanding"); //该部件具有优先扩展权
    pb->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    pb1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    QHBoxLayout *pg=new QHBoxLayout; pg->addWidget(pb); pg->addWidget(pb1);
    w.setLayout(pg); w.resize(300,200); w.show();

    return a.exec();
}
