#include "customer.h"

Customer::Customer(QString objectName, QObject *parent)
    :QObject(parent)
{
    setObjectName(objectName);
}

void Customer::setId(const QString &id)
{
    if(m_id != id) {
        QString _oldId = m_id;
        m_id = id;
        emit idChanged(_oldId, m_id);
    }
}

void Customer::setName(const QString &name)
{
    if(m_name != name) {
        QString _oldName = m_name;
        m_name = name;
        emit nameChanged(_oldName, m_name);
    }
}

void Customer::setAddress(const QString &address)
{
    if(m_address != address) {
        QString _oldAddress = m_address;
        m_address = address;
        emit addressChanged(_oldAddress, m_address);
    }
}

void Customer::setPhone(const QString &phone)
{
    if(m_phone != phone) {
        QString _oldPhone = m_phone;
        m_phone = phone;
        emit phoneChanged(_oldPhone, m_phone);
    }
}

void Customer::setDate(const QDate &date)
{
    if(m_date != date) {
        QDate _oldDate = m_date;
        m_date = date;
        emit dateChanged(_oldDate, m_date);
    }
}

void Customer::setType(const Customer::CustomerType &type)
{
    if(m_type != type) {
        Customer::CustomerType _oldType = m_type;
        m_type = type;
        emit typeChanged(_oldType, m_type);
    }
}

void Customer::setType(const QString typeName)
{
    // 利用元对象通过字符串获得枚举值
    static const QMetaObject *meta = metaObject();
    static int propIndex = meta->indexOfProperty("type");
    static const QMetaProperty mp = meta->property(propIndex);

    QMetaEnum menum = mp.enumerator();
    const char * ntype = typeName.toLatin1().data();
    const Customer::CustomerType theType =
            static_cast<Customer::CustomerType>(menum.keyToValue(ntype));

    if(m_type != theType) {
        Customer::CustomerType _oldType = m_type;
        m_type = theType;
        emit typeChanged(_oldType, m_type);
    }
}
