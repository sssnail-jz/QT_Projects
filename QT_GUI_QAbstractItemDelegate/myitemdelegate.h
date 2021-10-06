#ifndef MYITEMDELEGATE_H
#define MYITEMDELEGATE_H

#include <QObject>
#include <QAbstractItemDelegate>
#include <QtWidgets>

class MyItemDelegate: public QAbstractItemDelegate
{
public:
    MyItemDelegate(QObject *parent = 0);

    //重新实现 paint 函数，以绘制每个单元格(项目)
    void paint(QPainter *painter,
               const QStyleOptionViewItem &p1,
               const QModelIndex &index) const;

    //此函数对本例没有影响，可返回任意值。
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;

    //重新实现 createEditor 以便为每个单元格创建各自的编辑器
    QWidget* createEditor(QWidget* parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    //重新实现 setEditorData 以便把单元格的数据读入到编辑器中
    void setEditorData(QWidget *e, const QModelIndex &index) const;

    //重新实现 setModelData 以便把编辑器中的数据写入到单元格(即模型)
    void setModelData(QWidget *e, QAbstractItemModel *m,
                      const QModelIndex &index) const;
    // 设置编辑器的几何尺寸
    void updateEditorGeometry(QWidget *e, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;

    //该函数可以不需重新实现而使用默认的实现方式
    void destroyEditor(QWidget *e, const QModelIndex &index) const;
};

#endif // MYITEMDELEGATE_H
