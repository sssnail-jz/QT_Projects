#include "mytestwidget.h"
#include "ui_mytestwidget.h"

MyTestWidget::MyTestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTestWidget)
{
    ui->setupUi(this);
    m_ItemModel = new QStandardItemModel(3,3,this);
    //向模型中添加数据
    m_ItemModel->setData(m_ItemModel->index(0,0,QModelIndex()),"111",Qt::DisplayRole);
    m_ItemModel->setData(m_ItemModel->index(1,0,QModelIndex()),222);
    m_ItemModel->setData(m_ItemModel->index(1,1,QModelIndex()),33);
    m_ItemModel->setData(m_ItemModel->index(2,0,QModelIndex()),"XXXX");
    m_ItemModel->setData(m_ItemModel->index(2,1,QModelIndex()),QIcon("C:/Users/Jack Zheng/Documents/QT_GUI_QItemSelectionModel/1.jpg"),Qt::DecorationRole);
    m_ItemModel->setData(m_ItemModel->index(2,1,QModelIndex()),11);
    m_ItemModel->setData(m_ItemModel->index(2,1,QModelIndex()),11,Qt::ToolTipRole);
    m_ItemModel->setData(m_ItemModel->index(2,2,QModelIndex()),333);
    ui->tableView->setModel(m_ItemModel); //设置模型
    //设置视图的委托为自定义委托
    m_ItemDelegate=new MyItemDelegate(this);
    ui->tableView->setItemDelegate(m_ItemDelegate);
}

MyTestWidget::~MyTestWidget()
{
    delete ui;
}
