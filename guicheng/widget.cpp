#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    on_pushButtonAddPage_clicked();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonAddPage_clicked()
{
    NicContentWidget *nicContentWidget = new NicContentWidget;

    int newTabIndex = ui->tabWidget->addTab(nicContentWidget,"newtab");
}
