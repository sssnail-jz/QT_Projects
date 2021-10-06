#ifndef MYTESTWIDGET_H
#define MYTESTWIDGET_H

#include <QWidget>
#include "myitemdelegate.h"

namespace Ui {
class MyTestWidget;
}

class MyTestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyTestWidget(QWidget *parent = nullptr);
    ~MyTestWidget();

private:
    Ui::MyTestWidget *ui;
    QStandardItemModel *m_ItemModel;
    MyItemDelegate *m_ItemDelegate;
};

#endif // MYTESTWIDGET_H
