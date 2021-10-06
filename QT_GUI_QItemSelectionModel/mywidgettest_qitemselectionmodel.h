#ifndef MYWIDGETTEST_QITEMSELECTIONMODEL_H
#define MYWIDGETTEST_QITEMSELECTIONMODEL_H

#include <QWidget>
#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class MyWidgetTest_QItemSelectionModel;
}

class MyWidgetTest_QItemSelectionModel : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidgetTest_QItemSelectionModel(QWidget *parent = nullptr);
    ~MyWidgetTest_QItemSelectionModel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MyWidgetTest_QItemSelectionModel *ui;
    QStandardItemModel *m_ItemModel;
    QItemSelectionModel *m_selectModel;
};

#endif // MYWIDGETTEST_QITEMSELECTIONMODEL_H
