#include "tinteractobj.h"

TInteractObj::TInteractObj(QObject *parent)
    :QObject(parent)
{
}

TInteractObj::~TInteractObj()
{
}

void TInteractObj::JSSendMessage(QString strParameter)
{
    emit SigReceivedMessFromJS(strParameter);
}
