#include "widgeteventcustom.h"
#include "ui_widgeteventcustom.h"

WidgetEventCustom::WidgetEventCustom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetEventCustom)
{
    ui->setupUi(this);
}

WidgetEventCustom::~WidgetEventCustom()
{
    delete ui;
}

bool WidgetEventCustom::event(QEvent *e)
{
    static int i=0;
    qDebug() << "E" << i++;
    if(e->type()==QEvent::KeyPress)
        qDebug() << "keyDwon";
    return QWidget::event(e);
}

void WidgetEventCustom::mousePressEvent(QMouseEvent *e)
{
    qDebug() <<"mouseDwon";
}
