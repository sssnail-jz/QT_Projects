#include "widget.h"
#include <QApplication>
#include <QPushButton>
#include <QLayout>
#include <iostream>
using namespace std;

class B: public QPushButton
{
    Q_OBJECT
public:

    QWidget* pw;
    QLayout *pl; //创建两个数据成员用于传递数据

    B(QString s="",QWidget* p=0): QPushButton(s,p){}
public slots:
    void f()
    {
        pw=parentWidget(); //获取当前按钮的父部件
        pl=pw->layout(); //获取父部件的布局管理器，layout()是 QWidget 类中的函数
        QString t=text(); //获取当前按钮显示的文本
        if(t=="Default") //如果按下的是 Default 按钮
        {
            pl->setSizeConstraint(QLayout::SetDefaultConstraint);
        } //设置大小约束
        if(t=="Fixed")
        {
            pl->setSizeConstraint(QLayout::SetFixedSize);
        }
        if(t=="Maxi")
        {
            pl->setSizeConstraint(QLayout::SetMaximumSize);
        }
        if(t=="MinAndMax")
        {
            pl->setSizeConstraint(QLayout::SetMinAndMaxSize);
        }
        if(t=="NoCon")
        {
            pl->setSizeConstraint(QLayout::SetNoConstraint);
        }
        if(t=="CusMin")
        {
            pw->setMinimumSize(22,22);
        } //手动设置主窗口的最小值
        pl->activate(); //重新设置主窗口的布局，此函数必须调用，否则主窗口的数据不会立即更新
        g(); //调用函数 g 显示当前父部件的最大/最小值
    }

    void g()//用于输出当前父部件的最大最小值。
    {
        cout<<"minW="<<pw->minimumSize().width()<<",";
        cout<<"minH="<<pw->minimumSize().height()<<",";
        cout<<"maxW="<<pw->maximumSize().width()<<",";
        cout<<"maxH="<<pw->maximumSize().height()<<endl;
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    B *pb,*pb1,*pb2,*pb3,*pb4,*pb5;
    QHBoxLayout *pg;

    pb=new B("Default");
    pb1=new B("Fixed");
    pb2=new B("Maxi");
    pb3=new B("MinAndMax");
    pb4=new B("NoCon");
    pb5=new B("CusMin");

    //设置各子部件的大小策略
    pb->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    pb1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    pb2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    pb3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    pb4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    pb5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    //把子部件添加到布局中
    pg=new QHBoxLayout;
    pg->addWidget(pb);
    pg->addWidget(pb1);
    pg->addWidget(pb2);
    pg->addWidget(pb3);
    pg->addWidget(pb4);
    pg->addWidget(pb5);
    w.setLayout(pg);

    //关联信号和槽
    QObject::connect(pb, &QPushButton::clicked, pb, &B::f);
    QObject::connect(pb1, &QPushButton::clicked, pb1, &B::f);
    QObject::connect(pb2, &QPushButton::clicked, pb2, &B::f);
    QObject::connect(pb3, &QPushButton::clicked, pb3, &B::f);
    QObject::connect(pb4, &QPushButton::clicked, pb4, &B::f);
    QObject::connect(pb5, &QPushButton::clicked, pb5, &B::f);

    w.resize(300,100);
    w.show();

    return a.exec();
}
