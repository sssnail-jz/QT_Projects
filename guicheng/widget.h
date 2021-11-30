#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QPixmap>

#include "niccontentwidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonAddPage_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
