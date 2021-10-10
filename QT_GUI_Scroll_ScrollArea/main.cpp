#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *pw=new QWidget; //创建一个容器
    QLabel *pb=new QLabel;
    pb->setPixmap(QPixmap("D:/QT_Project_Git/QT_GUI_Scroll_ScrollArea/1.jpg")); //把图片加载到标签中
    QPushButton *pb1=new QPushButton("AAA");
    QPushButton *pb2=new QPushButton("BBB");
    pb1->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed); //设置大小策略。

    //布局容器 pw 的部件
    QVBoxLayout *pv=new QVBoxLayout; //主布局
    QHBoxLayout *ph=new QHBoxLayout;

    ph->addWidget(pb1); ph->addWidget(pb2);
    pv->addWidget(pb); pv->addLayout(ph);
    pw->setLayout(pv); //此语句应位于 ps.setWidget(pw);之前。

    //设置容器 pw 的背景色为红色
    QPalette p1; p1.setColor(QPalette::Background,QColor(111,1,1));
    pw->setPalette(p1);

    /*
        创建一个滚动区域，记住，QScrollArea 的祖先是 QWidget，因此，还
        可以像使用 QWidget 一样来使用 QScrollArea。
    */
    QScrollArea ps;
    ps.setWidget(pw);

    //设置滚动区域 ps 的背景色为蓝色
    QPalette p2; p2.setColor(QPalette::Background,QColor(0,0,255));
    ps.setPalette(p2);

    //在调用 show()显示 QScrollArea 之前需为子部件设置大小，否则子部件会不可见。
    pw->resize(600,500);
    /*
        若 widgetResizable 属性为 true，还必须设置最小大小，此时，即使使用 resize()设置了子部件大
        小，子部件也会不可见。
    */
    pw->setMinimumSize(300,200);

    ps.resize(300, 300);
    ps.show(); //显示 QScrollArea，也可把 ps 作为子部件添加到其他部件中。

    //#########################
    //以下部分内容用于验证视口部件，不是必须代码
    QWidget *pw1=ps.viewport(); //获取 ps 的视口
    //以下语句视情况修改为 0 或 1，用于填充背景，若为 0 背景将透明。
    pw1->setAutoFillBackground(0);
    QPalette p3; p3.setColor(QPalette::Background,QColor(1,1,111));
    pw1->setPalette(p3); //设置视口的背景色。

    return a.exec();
}
