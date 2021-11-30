#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mpJSWebView = new QWebEngineView();

    QWebChannel *pWebChannel = new QWebChannel(mpJSWebView->page());
    //自定义通道类
    TInteractObj *pInteractObj = new TInteractObj(this);
    //注册通道时"interactObj"名字应该与html的变量名一致
    pWebChannel->registerObject(QStringLiteral("interactObj"), pInteractObj);

    mpJSWebView->page()->setWebChannel(pWebChannel);
    mpJSWebView->page()->load(QUrl("D:/QT_Project_Git/QT_KERNEL_Web_DemoTry/ston.html"));
    mpJSWebView->show();

    connect(pInteractObj, &TInteractObj::SigReceivedMessFromJS,
            this, &MainWindow::OnReceiveMessageFromJS);
    connect(this,&MainWindow::SigSendMessageToJS,
            pInteractObj, &TInteractObj::SigSendMessageToJS);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnReceiveMessageFromJS(QString strParameter)
{
    if (strParameter.isEmpty())
    {
        return;
    }

    ui->textEdit->setText(strParameter);
}

void MainWindow::on_pushButton_clicked()
{
    QString strMessage = ui->lineEdit->text().trimmed();
    if (strMessage.isEmpty())
    {
        return;
    }
    emit SigSendMessageToJS(strMessage);
}
