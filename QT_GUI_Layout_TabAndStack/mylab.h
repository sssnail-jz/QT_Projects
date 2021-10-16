#ifndef MYLAB_H
#define MYLAB_H

#include<QtWidgets>
class MyLab: public QTabBar
{
    Q_OBJECT
public:
    MyLab(QWidget* p=0):QTabBar(p){}
public slots:
    void f()
    {
        moveTab(0,2);
    }
}; //把选项卡从索引 0 移至索引 2 处。

#endif // MYLAB_H
