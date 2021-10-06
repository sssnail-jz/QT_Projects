#include "myitemdelegate.h"

MyItemDelegate::MyItemDelegate(QObject *parent)
    :QAbstractItemDelegate(parent)
{

}

void MyItemDelegate::paint(QPainter *painter,
                           const QStyleOptionViewItem &p1,
                           const QModelIndex &index) const
{
    //为第 1 行 1 列的项目绘制一个进度条
    if (index.row()==1&&index.column() == 1)
    {
        int i = index.data().toInt();
        QStyleOptionProgressBar p; //该类用于设置绘制进度条时所需的信息
        // 设置绘制进度条的区域(使用 Qt 自动获取的区域)。
        // 此项必须设置，否则图形不知绘制于何处。
        p.rect = p1.rect;
        p.minimum = 0; //进度条的最小值
        p.maximum = 100; //进度条的最大值
        p.progress = i; //进度条的当前进度来自模型中的数据
        p.text = QString::number(i) + "%"; //进度条当前显示的值
        // 使用 QStyle::drawControl()成员函数绘制进度条，
        // 由此可见，项目上具体需要显示什么，完全可以由程序员自行绘制。
        p.textVisible = true;
        QApplication::style()->drawControl(QStyle::CE_ProgressBar,
                                           &p, painter);
    }
    //绘制第 2 行 1 列的项目，该项目会绘制一个图标和一个文本
    else if(index.row()==2 && index.column() == 1)
    {
        QStyleOptionViewItem p; //该类用于设置绘制模型/视图的数据项时所需的信息
        p.index=index; //设置需要绘制的项目的索引，此项不是必须设置项
        // 绘制项目的区域(使用 Qt 自动获取的区域)，此项必须设置，
        // 否则图形不知绘制于何处
        p.rect=p1.rect;
        //要显示图标，以下选项必须设置
        p.features = QStyleOptionViewItem::HasDecoration //要显示图标，必须包含该特征
                |QStyleOptionViewItem::HasDisplay;
        p.decorationSize=QSize(55,55); // 设置装饰(通常为图标)的大小，若不设置该选项，则因装饰大小为无效大小(-1,-1)而无法绘制。*/
        p.icon=index.data(Qt::DecorationRole).value<QIcon>(); //需要绘制的图标
        //要使项目被选择时高亮显示，需设置以下选项
        p.state=p1.state; //设置项目的样式标志(即项目是否被选择，是否启用等)
        qDebug()<<p1.state; //读者可观察项目样式标志的变化情况
        p.showDecorationSelected=true; //设置为 true。
        if (p1.state & QStyle::State_Selected) //若项目被选择，则高亮绘制其矩形
            painter->fillRect(p1.rect, p1.palette.highlight());
        //其他一些设置
        p.decorationPosition=QStyleOptionViewItem::Bottom; //装饰(图标)显示在文字下方
        p.displayAlignment=Qt::AlignLeft|Qt::AlignHCenter; //设置项目文本的对齐方式
        p.text=index.data().toString(); //设置项目需要显示的文本
        //绘制项目
        QApplication::style()->drawControl(
                    QStyle::CE_ItemViewItem, //该参数表示，绘制模型/视图的项目
                    &p, painter);
    }
    // 绘制第 2 行 0 列的项目，本示例将该项目绘制于其他地方
    // (即该项目未位于视图的单元格之内)
    else if(index.row()==2&&index.column() == 0)
    {
        QStyleOptionViewItem p;
        p.features=QStyleOptionViewItem::HasDisplay
                |QStyleOptionViewItem::HasCheckIndicator; //该项目可被选中
        p.rect=QRect(199,144,111,44); //该项目位置于此处
        p.state=p1.state;
        p.showDecorationSelected=true;
        p.text=index.data().toString();
        p.backgroundBrush=QBrush(QColor(111,1,1)); //设置背景色
        QFont f;
        f.setPixelSize(22);
        p.font=f; //设置字体
        p.displayAlignment=Qt::AlignLeft|Qt::AlignVCenter; //设置对齐方式
        QApplication::style()->drawControl(QStyle::CE_ItemViewItem,
                                           &p,painter);
    }
    //绘制其他项目
    else
    {
        QStyleOptionViewItem p;
        p.features=QStyleOptionViewItem::HasDisplay;
        p.index=index;
        p.rect=p1.rect;
        p.state=p1.state;
        // 设置为 true，否则没有内容的项目被选择时不会高亮显示
        p.showDecorationSelected=true;
        p.text=index.data().toString();
        QApplication::style()->drawControl(QStyle::CE_ItemViewItem,
                                           &p, painter);
    }
}

QSize MyItemDelegate::sizeHint(const QStyleOptionViewItem &option,
                               const QModelIndex &index) const
{
    return QSize(0,0);
}

QWidget *MyItemDelegate::createEditor(QWidget *parent,
                                      const QStyleOptionViewItem &option,
                                      const QModelIndex &index) const
{
    //创建两种类型的编辑器，以用于不同数据类型
    QLineEdit *pe=new QLineEdit(parent);

    pe->setStyleSheet("border: 2px solid red; color: blue;");
    QSpinBox *ps=new QSpinBox(parent);

    pe->setObjectName("EEE");
    ps->setObjectName("SSS");
    //若单元格的数据是文本或无效数据，则使用 pe 编辑器进行编辑
    if(index.data().type()==QMetaType::QString||index.data().isNull())
    {
        pe->setFocusPolicy(Qt::TabFocus);
        return pe;
    }
    //否则使用 ps 编辑器进行编辑
    else
    {
        ps->setMaximum(1000);
        return ps;
    }
}

void MyItemDelegate::setEditorData(QWidget *e, const QModelIndex &index) const
{
    //若单元格之前是文本或无效数据，则把模型中的数据读入到 QLineEdit 类型的编辑器中
    if(index.data().type()==QMetaType::QString||index.data().isNull())
    {
        ((QLineEdit*)e)->setText(index.data().toString());
    }
    //否则把模型中的数据读入到 QSpinBox 类型的编辑器中
    else
    {
        ((QSpinBox*)e)->setValue(index.data().toInt());
    }
}

void MyItemDelegate::setModelData(QWidget *e, QAbstractItemModel *m, const QModelIndex &index) const
{
    //若单元格之前是文本或无效数据，则把 QLineEdit 类型编辑器的数据写入模型
    if(index.data().type()==QMetaType::QString||index.data().isNull())
    {
        m->setData(index,((QLineEdit*)e)->text());
    }
    //否则把 QSpinBox 类型编辑器的数据写入模型
    else
    {
        m->setData(index,((QSpinBox*)e)->value());
    }
}

void MyItemDelegate::updateEditorGeometry(QWidget *e,
                                          const QStyleOptionViewItem &option,
                                          const QModelIndex &index) const
{
    //只需把编辑器的尺寸(位置和大小)设置为单元格的尺寸即可。
    QRect rect = option.rect;
    rect.adjust(-5,-5,5,5);

    e->setGeometry(rect);
}

void MyItemDelegate::destroyEditor(QWidget *e, const QModelIndex &index) const
{
    qDebug()<< e->objectName(); //查看删除的编辑器
    delete e;
} //使用 delete 删除编辑器，当然，你也可以不删除编辑器。
