#include "widget.h"
#include <QApplication>

#include<QMouseEvent>
#include<QPushButton>
#include<QObject>
#include <iostream>
using namespace std;

class A:public QObject
{
public: //该类的对象用作过滤器对象，使用事件过滤器需继承 QObject
    bool eventFilter(QObject *w, QEvent *e)
    {
        if(e->type()==QEvent::MouseButtonPress)
        {
            cout<<w->objectName().toStdString(); //验证 w 为事件本应到达的目标对象
            cout<<"=Ak"<<endl;
            return 1; //返回 1 表示该事件不再进一步处理
        }
        return 0;
    }
};
class B:public A
{
public: //继承自类 A
    bool eventFilter(QObject *w, QEvent *e)
    {
        if(e->type()==QEvent::MouseButtonPress)
        {
            cout<<w->objectName().toStdString()<<"=Bk"<<endl;
            return 0;
        }
        return 0;
    }
};

class C:public QWidget
{public: void mousePressEvent(QMouseEvent *e){cout<<"Ck"<<endl;}};
class D:public QPushButton
{public:void mousePressEvent(QMouseEvent *e){cout<<"DK"<<endl;}};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    A ma;
    B mb;
    C mc;
    D *pd=new D;
    D *pd1=new D;

    pd->setText("AAA");
    pd->move(22,22);
    pd1->setText("BBB");
    pd1->move(99,22);

    //设置对象名
    ma.setObjectName("ma");
    mb.setObjectName("mb");
    mc.setObjectName("mc");
    pd->setObjectName("pd");
    pd1->setObjectName("pd1");

    //设置父对象
    pd->setParent(&mc);
    pd1->setParent(&mc);
    mb.setParent(&ma);

    //注册过滤器对象
    pd->installEventFilter(&mb);
    pd1->installEventFilter(&ma);
    mc.resize(333,222);
    mc.show();

    return a.exec();
}
