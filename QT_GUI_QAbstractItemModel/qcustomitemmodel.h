#ifndef QCUSTOMITEMMODEL_H
#define QCUSTOMITEMMODEL_H

#include <QAbstractItemModel>
#include <QVariant>
#include <iostream>
#include <QDebug>

using namespace std;

class QCustomItemModel: public QAbstractItemModel
{
public:

    int m_colCount; // 列数
    int m_rowCount; // 行数

    QList<QVariant> m_list; //这是模型管理的数据
    QList<int> m_role; //存储数据的角色

    explicit QCustomItemModel(QObject *parent = nullptr);

    //构造函数表示创建一个 i 行 j 列的表格模型
    QCustomItemModel(int i, int j);

    //1、返回表格模型的行数
    int rowCount(const QModelIndex &parent = QModelIndex ()) const;

    //2、返回表格模型的列数
    int columnCount(const QModelIndex &parent =QModelIndex ()) const;

    //3、返回表格模型的父索引，因为所有单元格都是顶级节点，所以使用无效节点作为父节点
    QModelIndex parent(const QModelIndex &index) const;

    //4、为每个单元格创一个唯一的索引
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex ()) const;

    //5、返回视图上显示的数据，该函数会被视图多次调用(注：其他虚函数同样会被 Qt 调用多次)
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    //6、重写 setData 以使用户可以向模型中添加数据
    bool setData(const QModelIndex &index,const QVariant &value, int role=Qt :: EditRole);

    //7、重写 insertRows 以使用户可以扩展模型的行
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
};

#endif // QCUSTOMITEMMODEL_H
