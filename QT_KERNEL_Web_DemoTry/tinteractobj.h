#ifndef TINTERACTOBJ_H
#define TINTERACTOBJ_H

#include <QObject>

class TInteractObj : public QObject
{
    Q_OBJECT
public:
    TInteractObj(QObject *parent);
    ~TInteractObj();

    //关键字 Q_INVOKABLE 用于识别槽,该函数名必须与Web中js的发送函数同名
    Q_INVOKABLE void JSSendMessage(QString strParameter);
signals:
    void SigReceivedMessFromJS(QString strParameter);
    //该信号名必须与js中接收函数同名
    void SigSendMessageToJS(QString strParameter);
};

#endif // TINTERACTOBJ_H
