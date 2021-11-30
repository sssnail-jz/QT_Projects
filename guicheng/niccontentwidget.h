#ifndef NICCONTENTWIDGET_H
#define NICCONTENTWIDGET_H

#include <QWidget>

namespace Ui {
class NicContentWidget;
}

class NicContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NicContentWidget(QWidget *parent = nullptr);
    ~NicContentWidget();

private:
    Ui::NicContentWidget *ui;
};

#endif // NICCONTENTWIDGET_H
