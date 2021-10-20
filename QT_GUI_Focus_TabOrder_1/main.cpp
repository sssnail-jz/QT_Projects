#include "widget.h"
#include <QApplication>
#include <QGridLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication aa(argc, argv);

    QWidget w,w1; //创建两个窗口

    QGridLayout *pg=new QGridLayout;
    QPushButton *a,*b,*c,*d,*e,*f,*g,*h,*i;

    //设置容器 pw 中的部件
    QWidget *pw=new QWidget(&w); //pw 用作容器，不用作窗口
    a=new QPushButton("A");
    b=new QPushButton("B");
    c=new QPushButton("C");
    d=new QPushButton("D");
    e=new QPushButton("E");
    f=new QPushButton("F");

    pg->addWidget(a,0,0);
    pg->addWidget(b,0,1);
    pg->addWidget(c,1,0);
    pg->addWidget(d,1,1);
    pg->addWidget(e,2,0);
    pg->addWidget(f,2,1);

    pw->setLayout(pg);

    //设置容器 pw1 中的部件
    QWidget *pw1=new QWidget(&w);
    pw1->move(188,0);
    g=new QPushButton("G",pw1);
    h=new QPushButton("H",pw1);
    h->move(0,33);

    //设置窗口 w1 中的部件
    i=new QPushButton("I",&w1);

    //设置容器 pw 和 pw1 的背景色
    QPalette pt,pt1; //创建调色板
    pt.setColor(QPalette::Window,QColor(111,1,1)); //设置背景色
    pw->setPalette(pt); //为 pw 安装调色板
    pw->setAutoFillBackground(true); //自动填充背景，此函数必须调用，否则背景可能不会被更新。

    pt1.setColor(QPalette::Window,QColor(1,111,1));
    pw1->setPalette(pt1);
    pw1->setAutoFillBackground(true);

    //设置焦点顺序，默认焦点顺序为 a-b-c-d-e-f-g-h
    w.setTabOrder(d,g); //a-b-c-d-g-e-f-h
    w.setTabOrder(d,c); //a-b-d-c-g-e-f-h
    w.setTabOrder(c,a); //b-d-c-a-g-e-f-h
    // dcag
    //w.setTabOrder(h,i); //无效设置，h 和 i 位于不同的窗口中
    w1.resize(222,111);
    w1.show();
    w.resize(300,200);
    w.show();

    return aa.exec();
}
