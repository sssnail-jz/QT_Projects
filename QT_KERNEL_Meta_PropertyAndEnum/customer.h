#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QObject>
#include <QDate>
#include <QMetaObject>
#include <QMetaProperty>
class Customer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ getId
               WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName
               WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString address READ getAddress
               WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(QString phone READ getPhone
               WRITE setPhone NOTIFY phoneChanged)
    Q_PROPERTY(QDate date READ getDate
               WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(CustomerType type READ getType
               WRITE setType NOTIFY typeChanged)

public:
    enum CustomerType
    {Corporate, Individual, Educational, Government};
    Q_ENUMS(CustomerType)

    explicit Customer(QString objectName = QString(),
                      QObject *parent = nullptr);

    QString getId() const {return m_id;}
    QString getName() const {return m_name;}
    QString getAddress() const {return m_address;}
    QString getPhone() const {return m_phone;}
    QDate getDate() const {return m_date;}
    CustomerType getType() const {return m_type;}

    void setId(const QString &id);
    void setName(const QString &name);
    void setAddress(const QString &address);
    void setPhone(const QString &phone);
    void setDate(const QDate &date);
    void setType(const CustomerType &type);
    void setType(const QString typeName);

signals:
    void idChanged(QString oldId, QString newId);
    void nameChanged(QString oldName, QString newName);
    void addressChanged(QString oldAddress, QString newAddress);
    void phoneChanged(QString oldPhone, QString newPhone);
    void dateChanged(QDate oldDate, QDate newDate);
    void typeChanged(CustomerType oldType, CustomerType newType);

private:
    QString m_id, m_name, m_address, m_phone;
    QDate m_date;
    CustomerType m_type;
};

#endif // CUSTOMER_H
