#include "widget.h"
#include <QApplication>

#include <iostream>
#include <QObject>
#include <QPushButton>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>

using namespace std;

class A:public QWidget
{
public:

    void mousePressEvent(QMouseEvent *e)
    {
        cout<<"AmouseDwon"<<endl;
    } //鼠标按下
    void mouseReleaseEvent(QMouseEvent *e)
    {
        cout<<"AmouseRelease"<<endl;
    } //鼠标释放
    void keyPressEvent(QKeyEvent* e)
    {
        cout<<"AkeyDwon"<<endl;
    } //键盘按下
    void keyReleaseEvent(QKeyEvent* e)
    {
        cout<<"AkeyRelease"<<endl;//键盘释放
    }
};

class C:public QPushButton
{
public:
    void mousePressEvent(QMouseEvent *e)
    {
        cout<<"CmouseDwon"<<endl;
        e->accept();
    } //验证事件被接受后不会再被传递给父对象
    void mouseReleaseEvent(QMouseEvent *e)
    {
        cout<<"CmouseRelease"<<endl;
        QWidget::mouseReleaseEvent(e);
    }//验证 QWidget 默认为忽略事件
    void keyPressEvent(QKeyEvent* e)
    {
        cout<<"CkeyDwon"<<endl;
        e->ignore();
    } //验证事件事件被忽略后会被传递给父对象
    void keyReleaseEvent(QKeyEvent* e)
    {
        cout<<"CkeyRelease"<<endl;
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    A ma;
    C *mc=new C();

    mc->setParent(&ma); //设置父对象为 ma
    mc->setText("AAA");
    mc->move(22,22); //设置 mc 相对于 ma 的位置

    ma.resize(333,222); //设置部件的大小
    ma.show();

    return a.exec();
}
