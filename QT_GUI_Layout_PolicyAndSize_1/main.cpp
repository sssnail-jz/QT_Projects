#include "widget.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    QPushButton *pb=new QPushButton("Fixed");
    QPushButton *pb1=new QPushButton("MaxSetMin");
    QPushButton *pb2=new QPushButton("MaxNoMin");
    //每部件设置大小策略
    pb->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    pb1->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Fixed);
    pb2->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Fixed);
    QHBoxLayout *pg=new QHBoxLayout;
    pb->resize(222,222); //使用布局后，resize 函数将不再起作用
    pb->setMinimumWidth(11); pb->setMaximumWidth(188); //为 pb 设置最大/最小大小
    pb1->setMinimumWidth(1); //为 pb1 设置最小大小
    pg->addWidget(pb); pg->addWidget(pb1); pg->addWidget(pb2);
    w.setLayout(pg);
    w.resize(300,200); w.show();

    return a.exec();
}
