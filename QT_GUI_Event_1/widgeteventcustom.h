#ifndef WIDGETEVENTCUSTOM_H
#define WIDGETEVENTCUSTOM_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class WidgetEventCustom;
}

class WidgetEventCustom : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetEventCustom(QWidget *parent = nullptr);
    ~WidgetEventCustom();

    bool event(QEvent* e);
    void mousePressEvent(QMouseEvent* e);

private:
    Ui::WidgetEventCustom *ui;
};

#endif // WIDGETEVENTCUSTOM_H
