#include "widget.h"
#include <QApplication>
#include "qcustomitemmodel.h"
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //创建一个 3 行 3 列的表格模型
    QCustomItemModel *model=new QCustomItemModel(3,3);

    //使用表格视图来显示以上模型管理的数据
    QTableView *pv2=new QTableView;

    //向模型中添加数据
    model->setData(model->index(0,0,QModelIndex()),"111",Qt::DisplayRole);
    model->setData(model->index(1,0,QModelIndex()),222);
    model->setData(model->index(1,1,QModelIndex()),333);
    model->setData(model->index(2,1,QModelIndex()),QIcon("D:/QT_Project_Git/QT_GUI_QAbstractItemModel/1.jpg"),Qt::DecorationRole);

    pv2->setModel(model);
    pv2->resize(600,400);
    pv2->show();

    // 自定义实现插入行
    model->insertRows(1,2);
    model->setData(model->index(1,0,QModelIndex()), "AAA");
    model->setData(model->index(2,0,QModelIndex()), "BBB");

    return a.exec();
}
