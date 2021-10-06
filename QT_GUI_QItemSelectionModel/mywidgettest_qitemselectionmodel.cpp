#include "mywidgettest_qitemselectionmodel.h"
#include "ui_mywidgettest_qitemselectionmodel.h"

MyWidgetTest_QItemSelectionModel::MyWidgetTest_QItemSelectionModel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidgetTest_QItemSelectionModel)
{
    ui->setupUi(this);

    m_ItemModel=new QStandardItemModel(3,3,this);
    // 向模型中添加数据
    m_ItemModel->setData(m_ItemModel->index(0,0,QModelIndex()),"111",Qt::DisplayRole);
    m_ItemModel->setData(m_ItemModel->index(1,0,QModelIndex()),222);
    m_ItemModel->setData(m_ItemModel->index(2,2,QModelIndex()),333);
    m_ItemModel->setData(m_ItemModel->index(2,1,QModelIndex()),QIcon("C:/Users/Jack Zheng/Documents/QT_GUI_QItemSelectionModel/1.jpg"),Qt::DecorationRole);
    m_ItemModel->setData(m_ItemModel->index(2,1,QModelIndex()),"FFF");

    QItemSelectionModel *pp=ui->tableView->selectionModel(); //获取视图 ui->tableView 的选择模型
    ui->tableView->setModel(m_ItemModel); //该设置会同时清除 ui->tableView 之前的选择模型
    m_selectModel=new QItemSelectionModel;
    m_selectModel->setModel(m_ItemModel); //设置选择模型关联的项目模型
    //设置视图 ui->tableView 的选择模型，注意：该语句应位于ui->tableView->setModel(d)之后
    ui->tableView->setSelectionModel(m_selectModel);
    if(pp != nullptr)
    {
        delete pp; //删除 ui->tableView 之前的选择模型
    }
}

MyWidgetTest_QItemSelectionModel::~MyWidgetTest_QItemSelectionModel()
{
    delete ui;
}

void MyWidgetTest_QItemSelectionModel::on_pushButton_clicked()
{
    ui->tableView->setFocus(); //使视图获得焦点。
    m_selectModel->select(m_ItemModel->index(2,1,QModelIndex()),
                          QItemSelectionModel::Select);
}

void MyWidgetTest_QItemSelectionModel::on_pushButton_2_clicked()
{
    ui->tableView->setFocus(); //使视图获得焦点。
    m_selectModel->select(m_ItemModel->index(2,1,QModelIndex()),
                          QItemSelectionModel::ClearAndSelect);
}

void MyWidgetTest_QItemSelectionModel::on_pushButton_3_clicked()
{
    ui->tableView->setFocus(); //使视图获得焦点。
    m_selectModel->select(m_ItemModel->index(2,1,QModelIndex()),
                          QItemSelectionModel::Toggle);
}

void MyWidgetTest_QItemSelectionModel::on_pushButton_4_clicked()
{
    ui->tableView->setFocus(); //使视图获得焦点。
    m_selectModel->select(m_ItemModel->index(2,1,QModelIndex()),
                          QItemSelectionModel::Rows);
}

void MyWidgetTest_QItemSelectionModel::on_pushButton_5_clicked()
{
    ui->tableView->setFocus(); //使视图获得焦点。
    m_selectModel->select(m_ItemModel->index(2,1,QModelIndex()),
               QItemSelectionModel::Select|QItemSelectionModel::Rows);
}

void MyWidgetTest_QItemSelectionModel::on_pushButton_6_clicked()
{
    ui->tableView->setFocus(); //使视图获得焦点。
    m_selectModel->setCurrentIndex(m_ItemModel->index(2,1,QModelIndex()),
                                   QItemSelectionModel::Select);
}

void MyWidgetTest_QItemSelectionModel::on_pushButton_7_clicked()
{
    ui->tableView->setFocus(); //使视图获得焦点。
    m_selectModel->setCurrentIndex(m_ItemModel->index(2,1,QModelIndex()),
                                   QItemSelectionModel::NoUpdate);
}

void MyWidgetTest_QItemSelectionModel::on_pushButton_8_clicked()
{
    ui->tableView->setFocus(); //使视图获得焦点。
    m_selectModel->clear();
}

void MyWidgetTest_QItemSelectionModel::on_pushButton_9_clicked()
{
    ui->tableView->setFocus(); //使视图获得焦点。
    m_selectModel->clearCurrentIndex();
}

void MyWidgetTest_QItemSelectionModel::on_pushButton_10_clicked()
{
    ui->tableView->setFocus(); //使视图获得焦点。
    m_selectModel->clearSelection();
}
