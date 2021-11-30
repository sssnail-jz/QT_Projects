#include "niccontentwidget.h"
#include "ui_niccontentwidget.h"

NicContentWidget::NicContentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NicContentWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
}

NicContentWidget::~NicContentWidget()
{
    delete ui;
}
