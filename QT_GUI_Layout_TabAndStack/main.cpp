#include "widget.h"
#include <QApplication>
#include "mylab.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //创建子部件
    QWidget w;
    MyLab *pt=new MyLab;

    QPushButton *pb;
    QRadioButton *pr,*pr1,*pr2,*pr3,*pr4,*pr5;

    pr=new QRadioButton("AAA");
    pr1=new QRadioButton("BBB");
    pr2=new QRadioButton("CCC");
    pr3=new QRadioButton("DDD");
    pr4=new QRadioButton("EEE");
    pr5=new QRadioButton("FFF");

    pt->addTab("AAA");
    pt->addTab("BBB");
    pt->addTab("CCC");

    pb=new QPushButton("moveTab");

    //创建容器
    QWidget *pw=new QWidget(&w);
    QWidget *pw1=new QWidget;
    QWidget *pw2=new QWidget;

    QStackedLayout *ps=new QStackedLayout;
    /*
        三个容器 pw,pw1,pw2 位于该布局内，这样容器和
        选项卡就可以通过信号和槽进行关联了。
    */
    ps->addWidget(pw);
    ps->addWidget(pw1);
    ps->addWidget(pw2);

    QVBoxLayout *pv=new QVBoxLayout; //容器 pw 使用的布局
    pv->addWidget(pr);
    pv->addWidget(pr1);
    pw->setLayout(pv);

    QVBoxLayout *pv1=new QVBoxLayout; //容器 pw1 使用的布局
    pv1->addWidget(pr2);
    pv1->addWidget(pr3);
    pw1->setLayout(pv1);

    QVBoxLayout *pv2=new QVBoxLayout; //容器 pw2 使用的布局
    pv2->addWidget(pr4);
    pv2->addWidget(pr5);
    pw2->setLayout(pv2);

    QHBoxLayout *ph=new QHBoxLayout;
    ph->addWidget(pb); //此布局仅有一个按钮

    QVBoxLayout *pv3=new QVBoxLayout; //把布局 ph，ps 和部件 pt 放于于此容器内。
    pv3->addLayout(ph); // 按钮
    pv3->addWidget(pt); // tab
    pv3->addLayout(ps); // stack
    w.setLayout(pv3);

    //关联信号和槽以实现多页面切换(这是关键步骤)。
    QObject::connect(pt, SIGNAL(currentChanged(int)),
                     ps, SLOT(setCurrentIndex(int)));
    QObject::connect(pb, &QPushButton::clicked,
                     pt, &MyLab::f);

    w.resize(300,155);
    w.show();

    return a.exec();
}
