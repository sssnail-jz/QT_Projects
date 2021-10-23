#include "widget.h"
#include <QApplication>
#include "customer.h"
#include <QDebug>

template<typename firstT, typename secondT>
void MyCompare(QString output, const firstT &first, const secondT &second)
{
    qDebug() << QString("[ %1 ] beg").arg(output);
    if(first == second)
    {
        qDebug() << " [ equal]";
    }
    else
    {
        qDebug() << " [ not equal]";
    }
    qDebug() << QString("[ %1 ] end").arg(output);
}

void testCustomer()
{
    Customer cust("Customer");

    // 暂时 setType(QString)有字符乱码的情况
    cust.setType("Individual");
    MyCompare("test setType(QString)",
              cust.getType(), Customer::CustomerType::Individual);

    // 测试 property
    QString id = "1111111";
    cust.setId(id);
    QVariant v = cust.property("id");
    MyCompare("test cust.property()", id, v.toString());

    // 测试 setProperty
    QString name = "JJJJJ";
    cust.setProperty("name", name);
    MyCompare("test cust.setProperty()", name, cust.getName());

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    testCustomer();

    return a.exec();
}
