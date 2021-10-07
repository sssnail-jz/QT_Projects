#include "qcustomitemmodel.h"

QCustomItemModel::QCustomItemModel(QObject *parent)
    : QAbstractItemModel(parent)
{

}

QCustomItemModel::QCustomItemModel(int i, int j)
    :m_rowCount(i),m_colCount(j)
{
    for(int k=0;k<m_colCount*m_rowCount;k++)
    {
        m_list<<QVariant();
        m_role<<-1;
    }
}

int QCustomItemModel::rowCount(const QModelIndex &parent) const
{
    return m_rowCount;
}

int QCustomItemModel::columnCount(const QModelIndex &parent) const
{
    return m_colCount;
}

QModelIndex QCustomItemModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

QModelIndex QCustomItemModel::index(int row, int column,
                                    const QModelIndex &parent) const
{
    //其他模型可能需要判断传递进来的索引是否有效。
    //if(!hasIndex(row,column,parent))return QModelIndex();

    /*
        本示例仅需简单的为传递进来的单元格创建一个索引即可，注意第 3 个参数的使用，请参阅
        createIndex()原型。
    */
    return createIndex(row, column, (void*)&(m_list.at(row * m_colCount+column)));
}

QVariant QCustomItemModel::data(const QModelIndex &index, int role) const
{
    //单元格所在数据 m_list 中的位置
    int i = index.row() * m_colCount + index.column();

    //以下对不同角色返回的数据会被视图使用以使数据正确的显示在其单元格中。
    /*
        对于 QListView 和 QTreeView 必须对所在节点设置大小，
        否则这两个视图不会显示任何内容(因为节点大小为 0）
    */
    //if(role==Qt::SizeHintRole)
    //  return QSize(55,55);

    /*
        设置角色 CheckStateRole 的数据，
        本示例返回一个无效的 QVariant 作为该角色的数据， 若返
        回有效值，会使单元格的左侧显示一个复选框。
    */
    if(role==Qt::CheckStateRole)
        return QVariant();

    //设置单元格中数据的对齐方式，本示例为左侧垂直居中对齐
    if(role==Qt::TextAlignmentRole)
        return Qt::AlignLeft|Qt::AlignVCenter;

    //设置角色 DecorationRole(图片)的数据
    if(role==Qt::DecorationRole)
        //若用户设置了 DecorationRole 角色的数据，则返回用户为该单元格设置的数据。
        if(m_role.at(i)==Qt::DecorationRole)
            return m_list.at(i);

    // 若用户为角色 EditRole 或 DisplayRole 角色设置了数据，
    // 则返回用户为该单元格设置的数据。
    if(role==Qt::EditRole|role==Qt::DisplayRole)
        if(m_role.at(i)==Qt::EditRole|m_role.at(i)==Qt::DisplayRole)
            return m_list.at(i);

    //其余角色使用无效数据
    return QVariant();
}

bool QCustomItemModel::setData(const QModelIndex &index,
                               const QVariant &value, int role)
{
    /*
        使用数据 value 和角色 role 分别替换列表 m_list 和 m_role 中原有的值，使用 replace 便于下一个示
        例(拖放)的使用。
    */
    m_list.replace(index.row() * m_colCount+index.column(),value);
    m_role.replace(index.row() * m_colCount+index.column(),role);

    //数据改变后，需要发送此信号。
    emit dataChanged(index, index);

    //返回 true，表示数据设置成功。
    return true;
}

bool QCustomItemModel::insertRows(int row,
                                  int count,
                                  const QModelIndex &parent)
{
    emit beginInsertRows(parent, row + 1, row + count);
    // 行数增加
    m_rowCount += count;

    // 开始在哪里插入空元素
    int insertPos = row * m_colCount;
    // 一共插入多少个元素（行数 * 列）
    int elemCount = count * m_colCount;

    qDebug() << insertPos;
    qDebug() << elemCount;

    for(int i = 0; i < elemCount; i++)
    {
        m_list.insert(insertPos,QVariant());
        m_role.insert(insertPos, -1);
        insertPos++;
    }
    emit endInsertRows();

    return true;
}
