#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebChannel>
#include "tinteractobj.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void OnReceiveMessageFromJS(QString strParameter);

signals:
    void SigSendMessageToJS(QString strParameter);

private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QWebEngineView *mpJSWebView;
};

#endif // MAINWINDOW_H
